# Class graph

class graph:
   
    """
    A class used to represent graphs

    The class represents directed graphs the vertices are the states of teh system while the 
    edges are weighted to tell us 

    Attributes
    ----------
    says_str : str
        a formatted string to print out what the animal says
    name : str
        the name of the animal
    sound : str
        the sound that the animal makes
    num_legs : int
        the number of legs the animal has (default 4)

    Methods
    -------
    says(sound=None)
        Prints the animals name and what sound it makes
    """

    def __init__(self):
        self.V = []
        self.E = []
        self.graph_dict = {}
        self.vert_dict = {}
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

    def from_vertice(self, vertice):
        if type(vertice) != list:
            raise ValueError("Expected List of vertices")
        self.V = vertice
        self.graph_dict = {x: [] for x in vertice}
        self.vert_dict = {x: id for id,x in enumerate(vertice)}
    
    def from_edge(self, edges):
        if type(edges) != list:
            raise ValueError("Expected List of edges")
        
        for idx,data in enumerate(edges):
            edge = data[0]
            trans = data[1]
            W = data[2]
            self.E.append((edge,trans,W))
            
            if trans == "ext":
                self.ext_tran_idx.append(idx)
            elif trans == "int":
                self.int_tran_idx.append(idx)

            self.graph_dict[edge[0]].append(idx)




    @property
    def name(self) -> str:
        return self._name
    @name.setter
    def name(self,value):
        self._name = value 
    @name.getter
    def name(self):
        return self._name

    def get(self, key):
        return self.graph_dict.get(key)

    def __getitem__(self, key):
        return self.graph_dict[key]


