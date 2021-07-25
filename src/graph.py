

class graph:

    def __init__(self):
        self.V = []
        self.E = []
        self.graph_dict = {}
        self.ext_tran_idx = []
        self.int_tran_idx = []

    def add_vertex(self,vertex):
        self.V.append(vertex)
        if type(vertex) == str:
            self.graph_dict[vertex] = []
        elif type(vertex) == list:
            self.graph_dict[','.join(vertex)] = []
            
    
    def add_edge(self,edge,trans,W):
        # edge list transition, trans ext or int W is port,message,ta
        self.E.append((edge,trans,W))
        idx = len(self.E) -1 
        if trans == 'ext':
            self.ext_tran_idx.append(idx)
        elif trans == "int":
            self.int_tran_idx.append(idx)
        if type(edge[0]) == str:
            self.graph_dict[edge[0]].append(idx)
        elif type(edge[0]) == list:
            self.graph_dict[",".join(edge[0])].append(idx)


    @property
    def name(self):
        return self._name
    @name.setter
    def name(self,value):
        self._name = value 
    @name.getter
    def name(self):
        return self._name




