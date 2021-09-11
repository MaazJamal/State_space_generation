import os 




def write_cadmium(file_dir):

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
                states = data.split(",")
            elif what == "Int":
                int.append(data.split(","))
            elif what == "Ext":
                ext.append(data.split(","))
                

    return 

def write_files(top_dir):
    return