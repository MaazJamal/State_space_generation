


class atomic:
    
    def __init__(self, name, X, Y, S, trans_ext, trans_int):
            self._name = name
            self.input = X
            self.output = Y
            self.state = S
            self.trans_ext = trans_ext
            self.trans_int = trans_int 
            

    def add_transition(self, port,message,transition,ta,tran):
        if isinstance(tran) != str:
            raise TypeError("Unknown transition object type expected str got " + type(tran).__name__)
        transition = (port,message,transition,ta)
        if tran == "ext":
            self.trans_ext.append(transition)
        elif tran == "int":
            self.trans_int.append(transition)
        else:
            raise ValueError("Incorrect transition type" + tran)

    def add_input(self,X):
        if isinstance(X,str):
            self.input.append(X)
        elif isinstance(X,list):
            self.input.extend(X)
        else:
            raise TypeError("Incorrect atomic input type. Expecting str or list got type" + type(X).__name__)
    
    def add_output(self,Y):
        if isinstance(Y,str):
            self.input.append(Y)
        elif isinstance(Y,list):
            self.input.extend(Y)
        else:
            raise TypeError("Incorrect atomic output type. Expecting str or list got type" + type(Y).__name__)
    
    def add_state(self,S):
        if isinstance(S,str):
            self.input.append(S)
        elif isinstance(S,list):
            self.input.extend(S)
        else:
            raise TypeError("Incorrect atomic state type. Expecting str or list got type" + type(S).__name__)
    

    def __str__(self) -> str:
        return "atomic_"+self.name
    
    def ext_trans(self):
        return self.trans_ext
    
    def int_trans(self):
        return self.trans_int
    
    @property
    def name(self):
        return self._name