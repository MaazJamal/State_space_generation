import os
import glob
import posixpath
from src.atomic import atomic as at
from src.coupled import coupled as coup

class read_model:

    def __init__(self,dir):
        self.dir = dir
        if not os.path.isdir(self.dir):
            raise NotADirectoryError()
        
    def file_names(self):
        searchstring = os.path.join(self.dir+"/","*.txt")
        files = glob.glob(searchstring)
        files = [f.replace(os.sep, posixpath.sep) for f in files]
        return files
    
    """ This method reads the transition of an atomic model to tell the result."""

    def transition_parser(self, data, ext):
        data = data.split(",") 
        if len(data) != 5:
            raise ValueError("Incorrect number of transition inputs")
        port  = data[0]
        msg = data[1]
        trans = [data[2],data[3]]
        ta = data[4]
        if ta not in ["inf","fin","zero"]:
            raise ValueError("Unrecognized time advanced: " + ta)
        if ext == True:
            if port == "" or port == None:
                raise ValueError("Expected port for external transition ")
            if msg == '' or port == None:
                raise ValueError("Expected message for external transition")
        else:
            if (len(port) == 0 and len(msg) > 0) or (len(port) > 0 and len(msg) == 0):
                    raise ValueError("One of port or message not set for internal transition.")

        out = (port,msg,trans,ta)
        return out


    def coupling_parser(self, data):
        data_split = data.split(",")
        if len(data_split) != 2:
            raise ValueError("Incorrect coupling data: {}".format(data))
        out_model,out_port = data_split[0].split(".")
        in_model,in_port = data_split[1].split(".")
        coupling = (out_model, out_port, in_model, in_port)
        return coupling



    def read(self,file):
        
        model_name = file.split("/")[-1].split(".")[0]


        with open(file, 'r') as f:
            header_flag = False
            atomic = False
            coupled = False
            ext_trans = []
            int_trans = []

            for line in f:
                line = line.replace(" ",'')
                line = line.strip()
                #check if file is atomic or coupled
                if not header_flag:
                    if line == "[atomic]":
                        atomic = True
                        header_flag = True
                    elif line == "[coupled]":
                        coupled = True
                        header_flag = True
                    
                
                elif atomic:

                    data = line.split("=")
                    X = None
                    Y = None
                    if data[0]== "X":
                        X = data[1].split(',')
                    if data[0] == "Y":
                        Y = data[1].split(',')
                    if data[0] == "S":
                        S = data[1].split(',')
                    
                    if data[0] == "Ext":
                       ext_trans.append(self.transition_parser(data[1], ext=True))
                    if data[0] == "Int":
                        int_trans.append(self.transition_parser(data[1], ext=False))

                elif coupled:
                    model = coup()

            if atomic:
                model = at(model_name,X,Y,S,ext_trans,int_trans)
               
        f.close()
        return model

    def read_coupled(self, file, atomics):
        model_name = file.split("/")[-1].split(".")[0]
        atomic_names = list(name.name for name in atomics)
         
        with open(file) as f:
            header_flag = False
            atomic = False
            coupled = False
            M = []
            EIC = []
            IC = []
            EOC = []

            for line in f:
                line = line.replace(" ",'')
                line = line.strip()
                #check if file is atomic or coupled
                if header_flag != True:
                    if line == "[atomic]":
                        atomic = True
                        header_flag = True
                    elif line == "[coupled]":
                        coupled = True
                        header_flag = True
                
                elif coupled:

                    data = line.split("=")

                    X = None
                    Y = None
                    if data[0]== "X":
                        X = data[1].split(',')
                    if data[0] == "Y":
                        Y = data[1].split(',')
                    if data[0] == "D":
                        D = data[1].split(',')
                    
                    if data[0] == "M":
                        M_names = data[1].split(',')
                        for M_name in M_names:
                            idx = atomic_names.index(M_name)
                            M.append(atomics[idx])

                    # the D names should be more personalised. While the M is just the atomics name.
                    # The EIC,EOC and IC need to have information about who is who. So they need to know 
                    # that is this instance of the atomic. 
                    # The select function uses the names by D.


                    if data[0] == "EIC":
                        out = self.coupling_parser(data[1])
                        EIC.append(out)
                    if data[0] == "EOC":
                        out = self.coupling_parser(data[1])
                        EOC.append(out)
                    if data[0] == "IC":
                        out = self.coupling_parser(data[1])
                        IC.append(out)
                    if data[0] == "select":
                        select = data[1].split(",")


        f.close()
        coupled_model = coup(model_name,X,Y,D,M,EIC,EOC,IC,select) 
        return coupled_model

    def read_models(self):
        files = self.file_names()
        atomics = []
        coupled = []
        coupled_files = []

        for file in files:
            model = self.read(file)
            if type(model) == at:
                atomics.append(model)
            elif type(model) == coup:
                coupled_files.append(file)
        
        for file in coupled_files:
            model = self.read_coupled(file,atomics)
            model.sort_verify()
            coupled.append(model)
        
        return [atomics,coupled]




                

