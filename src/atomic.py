


class atomic:
    
    """
    A class used to represent an Atomic model.

    The atomic models are represented as inputs, outputs and transitions between states.
    The format for the transition is port,output/input,transitions,time advance

    ...

    Attributes
    ----------
    _name : str
        a string that stores the name of the atomic. The atomic name is the name of the file.
    input : list[str]
        the input ports. It is a list of strings with port names.
    output : list[str]
        the output ports. It is a list of the strings of port names.
    state : list[str]
        A list of strings of the states of the atomic.
    trans_ext : list[tuple(str,str,str,str)]
        A list of tuple of strings. That mention the port name, input , transition, time advance
    trans_int : list[tuple(str,str,str,str)]
        A list of tuple of strings. That mention the port name, output , transition, time advance

    Methods
    -------
    add_transition(port : str ,message : str,transition : str,ta : str,tran : str)
        Generic function that adds a transition to either external or internal list.
        Depending upon the input at tran. "ext" specifies external and "int"
        specifies internal.
    
    add_input(X)
        adds a port to the model. If X can be  str or list[str] 
   
    add_output(Y)
        adds a port to the model. If X can be  str or list[str]     
   
    add_state()
        adds a state to the model. If X can be  str or list[str] 

    ext_trans()
        returns external transitions 
    int_trans()
        returns internal transitions

    """


    def __init__(self, name, X, Y, S, trans_ext, trans_int):
            self._name = name
            self.input = X
            self.output = Y
            self.state = S
            self.trans_ext = trans_ext
            self.trans_int = trans_int 
            

    def add_transition(self, port : str ,message : str,transition : str,ta : str,tran : str):
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