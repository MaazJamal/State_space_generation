import os 
import glob
import posixpath

def state_conversion(ind_state):
        ind_state = ind_state.replace(".","_")
        ind_state = ind_state.replace(",","_")
        ind_state = ind_state.replace("-","_")
        ind_state = ind_state.upper()
        return ind_state

def write_inverse(dir,in_ports,out_ports,states,int,ext):
    
    out = []
    
    with open(dir,"w+") as file:

        filename = dir.split("/")[-1].split(".")[0]
        out.append("#ifndef __{}__HPP__\n".format(filename.upper()))
        out.append("#define __{}__HPP__\n".format(filename.upper()))

        out.append("//STATE DEFINITIONS\n\n")
        for idx,ind_state in enumerate(states):
            state = state_conversion(ind_state)
            out.append("#define {} {}\n".format(state,idx))
        

        out.append(""" 

#include <cadmium/modeling/ports.hpp>
#include <cadmium/modeling/message_bag.hpp>
#include <limits>
#include <math.h>
#include <assert.h>
#include <memory>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>
#include <limits>
#include <random>

using namespace cadmium;
using namespace std;

#ifdef RT_ARM_MBED

#include "../mbed-os/mbed.h"
#include <cadmium/real_time/arm_mbed/embedded_error.hpp>

using namespace mbed;
#endif """)

        out.append("\n\n\n //PORTS \n\n")
        out.append("struct {}_defs {{\n".format(filename))
        for o_port in out_ports:
            out.append("    struct {} : public out_port<string> {{ }};\n".format(o_port))
        for i_port in in_ports:
            out.append("    struct {} : public in_port<string> {{ }};\n".format(i_port))
        out.append("};\n\n\n")


        out.append("""
        template <typename TIME>
class {0}
{{
  using defs = {0}_defs; // putting definitions in context
public:
  //Parameters to be overwriten when instantiating the atomic model
  bool fin;
  bool inf;
  bool ta;
  string out_port;
  string out;
  string in;
  string in_port;

  // default constructor
  {0}() noexcept
  {{
    fin = true;
    inf = false;
    ta = fin;
    out_port = "";
    out = "";
    in = "";
    in_port = "";
    this->state.state = 0;
  }} 
  
    // state definition
  struct state_type
  {{
    int state;
  }} state;
  
  """.format(filename))



        out.append("//port deifinitions\n\n")

        out.append("    using input_ports = std::tuple<")
        for idx,i_port in enumerate(in_ports):
            out.append("typename defs::{}".format(i_port))
            if idx != len(in_ports)-1:
               out.append(',') 
        out.append(">;\n")
        out.append("    using output_ports = std::tuple<")
    
        for idx,o_port in enumerate(out_ports):
            out.append("typename defs::{}".format(o_port))
            if idx != len(out_ports)- 1:
               out.append(',') 
        out.append(">;\n\n")
        

        out.append("//INTERNAL TRANSITIONS\n\n")
        out.append("""  void internal_transition()
  {\n""")
        out.append("switch (this->state.state) {\n")
        for tran in int:
            states = tran[2].split(":")
            state1 = state_conversion(states[0])
            state2 = state_conversion(states[1])
            out.append("    case {}:\n        this->state.state = {};\n".format(state1,state2))
            out.append("        this->out_port = \"{}\";\n        this->out = \"{}\";\n".format(tran[0],tran[1]))
            out.append("        this->ta = {};\n        break;\n".format(tran[3]))
        out.append("}}\n\n\n// External Inputs\n\n\n")
        

        out.append("""  void external_transition(TIME e, typename make_message_bags<input_ports>::type mbs)
  {{
    for (const auto &x : get_messages<typename defs::{0}>(mbs))
    {{

      this->in_port = "{0}";
      this->in = x;
    }}
""".format(in_ports[0]))

        # the external transitions are divided by port and then input. 
        ext_dict = {}
        for port in in_ports:
            ext_dict[port] = {}
        for tran in ext:
            if tran[1] in ext_dict[tran[0]]:
                ext_dict[tran[0]][tran[1]].append(tran)
            else:
                ext_dict[tran[0]][tran[1]] = []
                ext_dict[tran[0]][tran[1]].append(tran)

        for key in ext_dict.keys():
            out.append("    if(this->in_port == \"{}\") {{\n".format(key))
            value = ext_dict[key]
            for input,tran_value in value.items():
                out.append("        if(this->in == \"{}\"){{\n".format(input))
                out.append("            switch (this->state.state) {\n")

                for tran in tran_value:
                    states = tran[2].split(":")
                    state1 = state_conversion(states[0])
                    state2 = state_conversion(states[1])
                    out.append("                case {}:\n                this->state.state = {};\n".format(state1,state2))
                    out.append("                this->ta = {};\n                break;\n".format(tran[3]))                                
                out.append("            }\n")
                out.append("        }\n")
            out.append("    }\n")
        out.append("}\n")      
        out.append(""" // confluence transition
  void confluence_transition(TIME e, typename make_message_bags<input_ports>::type mbs)
  {{
    internal_transition();
    external_transition(TIME(), std::move(mbs));
  }}

  // output function
  typename make_message_bags<output_ports>::type output() const
  {{
    typename make_message_bags<output_ports>::type bags;
    if (this->out_port == "{0}")
    {{
      get_messages<typename defs::{0}>(bags).push_back(out);
    }}
    return bags;
  }}

  // time_advance function
  TIME time_advance() const
  {{
    if (ta)
    {{
      return TIME("00:00:00:500");
    }}
    else
    {{
      return numeric_limits<TIME>::infinity();
    }}
  }}

  friend std::ostringstream &operator<<(std::ostringstream &os, const typename {1}<TIME>::state_type &i)
  {{
    os << "Output: " << i.state;
    return os;
  }}
}};\n""".format(out_ports[0],filename))

        out.append("#endif")
        


        file.writelines(out)
    file.close()





def read_inverse(file_dir):
    
    int = []
    ext = []

    with open(file_dir,"r+") as file:
        lines = file.readlines()
        for idx,line in enumerate(lines):
            
            if idx == 0:
                continue
            line = line.split("=")
            what = line[0].strip()
            data = line[1].strip()

            if what == "X":
                in_ports = data.split(",")
            elif what == "Y":
                out_ports = data.split(",")
            elif what == "S":
                states = data.split("|")
            elif what == "Int":
                int.append(data.split("|"))
            elif what == "Ext":
                ext.append(data.split("|"))
    file.close()     
    return  in_ports,out_ports,states,int,ext

def read_atomic(file_dir):
    
    int = []
    ext = []

    with open(file_dir,"r+") as file:
        lines = file.readlines()
        for idx,line in enumerate(lines):
        
            line = line.strip()
            if idx == 0 or line == '':
                continue
            line = line.split("=")
            what = line[0].strip()
            data = line[1].strip()

            if what == "X":
                in_ports = data.split(",")
            elif what == "Y":
                out_ports = data.split(",")
            elif what == "S":
                states = data.split(",")
            elif what == "Int" or what == "Ext":
                splits = data.split(",")
                port = splits[0]
                data_type = splits[1]
                ta = splits[-1]
                transition = ":".join([splits[2],splits[3]])
                trans = [port,data_type,transition,ta]
                if what == "Int":
                    int.append(trans)
                elif what == "Ext":
                    ext.append(trans)

    file.close()     
    return  in_ports,out_ports,states,int,ext


def read_atomic_files(top_dir):
    output = "output/hpp"
    if not os.path.isdir(output):
        os.mkdir(output)
    
    searchstring = os.path.join(top_dir+"/","*.txt")
    files = glob.glob(searchstring)
    files = [f.replace(os.sep, posixpath.sep) for f in files]
    for file in files:
        with open(file,"r") as f:
            header = f.readline().strip()
            if header == "[atomic]":
                f.close()
                in_ports,out_ports,states,int,ext = read_atomic(file)
                write_inverse(output+"/{}.hpp".format(file.split('/')[-1].split(".")[0]),in_ports,out_ports,states,int,ext)
            else:
                f.close()
                continue
    return


def read_inverse_files(top_dir):
    
    output = "output/hpp"
    if not os.path.isdir(output):
        os.mkdir(output)
    
    dir = next(os.walk("output/Models"))[1]
    for folder in dir:
        name = top_dir+folder+"/inverse.txt"
        in_ports,out_ports,states,int,ext = read_inverse(name)

        write_inverse(output+"/{}.hpp".format(folder),in_ports,out_ports,states,int,ext)
    return

