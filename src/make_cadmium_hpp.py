import os 


def write_inverse(dir,in_ports,out_ports,states,int,ext):
    
    out = []
    with open(dir,"w+") as file:
        out.append("//STATE DEFINITIONS\n\n")
        for idx,state in enumerate(states):
            state = state.replace(".","_")
            state = state.replace(",","_")
            state = state.upper()
            out.append("#define {} {}\n".format(state,idx))
        
        out.append("\n\n\n //PORTS \n\n")
        out.append("struct {}_defs {{\n".format(dir.split("/")[-1].split(".")[0]))
        for o_port in out_ports:
            out.append("    struct {} : public out_port<string> {{ }};\n".format(o_port))
        for i_port in in_ports:
            out.append("    struct {} : public in_port<string> {{ }};\n".format(i_port))
        out.append("}\n\n\n")
        out.append("//INTERNAL TRANSITIONS\n\n")
        
        out.append("switch (this->state.state) {\n")
        for tran in int:
            state = state.replace(".","_")
            state = state.replace(",","_")
            state = state.upper()
            tran
        out.append("    case {}:\n")


        file.writelines(out)
    file.close()





def read_inverse(file_dir):

    with open(file_dir,"r+") as file:
        lines = file.readlines()
        for idx,line in enumerate(lines):
            
            if idx == 0:
                continue
            line = line.split("=")
            what = line[0].strip()
            data = line[1].strip()
            int = []
            ext = []
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