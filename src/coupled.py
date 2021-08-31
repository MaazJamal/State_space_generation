#TODO Create representaion that can take atomic models and links between them.
#TODO Future should also be able to take other coupled models and be able to link them.
# Use text files to define the coupled models and its links. 

#1 - Atomic model can be used multiple times. The atomic model only has one name. Must include way to name models
#   in coupled listing. 
#
# 2 -The coupled model needs to verify itself. The read model will return data to the coupled model. The coupled
# model should check if the connections are valid and the ports match.
#  

class coupled:
    
    def __init__(self, name="default", X=[], Y=[], D=[], M=[], EIC=[], EOC=[], IC=[], select=[]):
            self._name = name
            self._input = X
            self._output = Y
            self._component_names = D
            self._model_instance = M
            self._EIC = EIC
            self._EOC = EOC
            self._IC = IC
            self._select = select
            
    def update_name(self, name):
        self._name = name
    
    def add_input_ports(self,X):
        self._input = []
        for port in X:
            self._input.append(port)

    def add_output_ports(self,Y):
        self._input = []
        for port in Y:
            self._input.append(port)
    
    def add_component(self, D):
        for component in D:
            self._component_names.append(component)
    
    def add_module(self,M):
        for module in M:
            self._model_instance.append(module)

    def add_EIC(self,EIC):
        for module in EIC:
            self._EIC.append(module)

    def add_EOC(self,EOC):
        for module in EOC:
            self._EOC.append(module)

    def add_IC(self,IC):
        for module in IC:
            self._IC.append(module)

    def add_select(self,select):
        for module in select:
            self._select.append(module)
    
    #sorts the component names according to select function and verifies if the coupled model is correct

    def sort_verify(self):

        if len(self._select) != len(self._component_names):
            raise ValueError("length of select function is not equal to number of components")
        

        if len(self._component_names) != len(self._model_instance):
            raise ValueError("length of components is not equal to number of modules")

        self.component_dict = dict(zip(self._component_names,self._model_instance))
        self.model_names = list([model.name for model in self._model_instance])

        # for idx,value in enumerate(list(self.component_dict.values())):
        #     if self.model_names != []:
        #         if value.name not in self.model_names:
        #             self.model_names.append(value.name)
        #         else:
        #             continue
        #     else:
        #         self.model_names.append(value.name)

        

        # for key,value in self.component_dict:
        #     if key != value.name:
        #         raise IndexError("length of component names and modules do not match.")
        if self._input is not None:
            len_x = len(self._input)

            for x in self._input:

                x = x.split(".")

                if x[0] == self._name:
                    len_x -= 1
                    continue

                else:
                    try:
                        model_idx = self.model_names.index(x[0])
                        model_ports = self._model_instance[model_idx].input
                        if x[1] in model_ports:
                            len_x -=1
                            continue
                        else:
                            raise ValueError("No input port {} found in {}".format(x[1],x[0]))
                    except KeyError as error:
                        print(error)
                        print("model {} not found in components".format(x[0]))
                        exit(-1)

            if len_x != 0:
                raise ValueError("The number of output ports of the system do not match the number of ports of the models")

        if self._output is not None:    
            len_y = len(self._output)

            for y in self._output:

                y = y.split(".")

                if y[0] == self._name:
                    len_y -= 1
                    continue

                else:
                    try:
                        model_idx = self.model_names.index(y[0])
                        model_ports = self._model_instance[model_idx].output
                        if y[1] in model_ports:
                            len_y -=1
                            continue
                        else:
                            raise ValueError("No output port {} found in {}".format(y[1],y[0]))
                    except KeyError as error:
                        print(error)
                        print("model {} not found in components".format(y[0]))
                        exit(-1)

            if len_y != 0:
                raise ValueError("The number of output ports of the system do not match the number of ports of the models")
            
            if self._EIC != []:
                for eic in self._EIC:
                    port = ".".join(eic[0:2])
                    if port in self._input:
                        pass
                    else:
                        raise ValueError("Incorrect external input port in EIC coupling {}.{} -> {}.{}".format(eic[0],eic[1],eic[2],eic[3]))
                    in_port = self.component_dict[eic[2]].input
                    if eic[3] in in_port:
                        pass
                    else:
                        raise ValueError("Incorrect input port in EIC coupling {}.{} -> {}.{}".format(eic[0],eic[1],eic[2],eic[3]))

            
            if self._EOC != []:
                for eoc in self._EOC:
                    out_port = self.component_dict[eoc[0]].output
                    if eoc[1] in out_port:
                        pass
                    else:
                        raise ValueError("Incorrect output port in EOC coupling {}.{} -> {}.{}".format(eoc[0],eoc[1],eoc[2],eoc[3]))
                    
                    port = ".".join(eoc[2:])
                    if port in self._output:
                        pass
                    else:
                        raise ValueError("Incorrect external output port in EOC coupling {}.{} -> {}.{}".format(eoc[0],eoc[1],eoc[2],eoc[3]))
                        
            
            if self._IC != []:
                for ic in self._IC:
                    out_port = self.component_dict[ic[0]].output
                    if ic[1] in out_port:
                        pass
                    else:
                        raise ValueError("Incorrect output port in IC coupling {}.{} -> {}.{}".format(ic[0],ic[1],ic[2],ic[3]))
                    
                    in_port = self.component_dict[ic[2]].input
                    if ic[3] in in_port:
                        pass
                    else:
                        raise ValueError("Incorrect input port in IC coupling {}.{} -> {}.{}".format(ic[0],ic[1],ic[2],ic[3]))


        return



    def update_coupled(self, name="", X=[], Y=[], D=[], M=[], EIC=[],EOC=[], IC=[], select=[]):

        if name != "":
            self.update_name(name)
        if len(X) != 0:
            self.add_input_ports(X)
        if len(Y) != 0:
            self.add_output_ports(Y)
        if len(D) != 0:
            self.add_component(D)
        if len(M) != 0:
            self.add_module(M)
        if len(EIC) != 0:
            self.add_EIC(EIC)
        if len(EOC) != 0:
            self.add_EOC(EOC)
        if len(IC) != 0:
            self.add_IC(IC)
        if len(select) != 0:
            self.add_select(select)

        self.sort_verify()        

    
    def __str__(self) -> str:
        return "coupled_{}".format(self._name)
    
    @property
    def name(self):
        return self._name
