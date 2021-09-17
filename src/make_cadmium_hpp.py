import os 

def state_conversion(ind_state):
        ind_state = ind_state.replace(".","_")
        ind_state = ind_state.replace(",","_")
        ind_state = ind_state.upper()
        return ind_state

def write_inverse(dir,in_ports,out_ports,states,int,ext):
    
    out = []
    with open(dir,"w+") as file:
        out.append("//STATE DEFINITIONS\n\n")
        for idx,ind_state in enumerate(states):
            state = state_conversion(ind_state)
            out.append("#define {} {}\n".format(state,idx))
        
        out.append("\n\n\n //PORTS \n\n")
        out.append("struct {}_defs {{\n".format(dir.split("/")[-1].split(".")[0]))
        for o_port in out_ports:
            out.append("    struct {} : public out_port<string> {{ }};\n".format(o_port))
        for i_port in in_ports:
            out.append("    struct {} : public in_port<string> {{ }};\n".format(i_port))
        out.append("};\n\n\n")
        out.append("//INTERNAL TRANSITIONS\n\n")
        
        out.append("switch (this->state.state) {\n")
        for tran in int:
            states = tran[2].split(":")
            state1 = state_conversion(states[0])
            state2 = state_conversion(states[1])
            out.append("    case {}:\n        this->state.state = {};\n".format(state1,state2))
            out.append("        this->out_port = \"{}\";\n        this->out = \"{}\"\n".format(tran[0],tran[1]))
            out.append("        this->ta = {};\n        break;\n".format(tran[3]))
        out.append("}\n\n\n// External Inputs\n\n\n")

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
            out.append("    if(this->in_port == \"{}\" {{\n".format(key))
            value = ext_dict[key]
            for input,tran_value in value.items():
                out.append("        if(this->in == \"{}\"{{\n".format(input))
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