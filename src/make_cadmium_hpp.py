import os 


def write_inverse(dir,in_ports,out_ports,states,int,ext):
    
    out = []
    with open(dir,"w+") as file:
        for idx,state in enumerate(states):
            state = state.replace(".","_")
            state = state.replace(",","_")
            state = state.upper()
            out.append("#define {} {}".format(state,idx))




def read_inverse(file_dir):

    with open(file_dir,"r+") as file:
        lines = file.readlines
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
    
    dir = os.listdir(top_dir)
    return