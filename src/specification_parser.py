#read graph. Use string matching to select usefull vertices.
# The specification needs to be stored as a txt files.
# Specification formats:
# 1 - path, state 1 , state 2 (find path from state to state including all states in the path)
# 2 - no_state , state ( there should no state of the type specified in the graph or diagram)
# 3 - no_transition, state 1, state 2 ( There should be no transitions between state 1 and stat 2)
#    
# Specification special symbols.
#   ? : state doesnt matter.
#   


import pathlib
from src.graph import graph
import re
from os import path

class specification_parser:

    def __init__(self, state_graph, specification_file):

        self.specication_file = specification_file
        self.state_graph = state_graph
        self.out_graph = graph()
        self.specication_file
        self.path_spec_list = []
        self.state_spec_list = []
        self.trans_spec_list = []
        self.vertex = []
        self.edge = []

    
    def specification(self):
        if not path.isfile(self.specication_file):
            raise FileNotFoundError("Specification file not found")

        with open(self.specication_file,"r") as file:
            for line in file:

                line = line.strip()
                specs = line.split(",")
                if specs[0] == '':
                    continue
                elif specs[0] == "path":
                    ind = [idx for idx,x in enumerate(line[1:]) if x != "?"]
                    self.path_spec_list.append((line,ind))

                elif specs[0] == "no_state":
                    ind = [idx for idx,x in enumerate(line[1:]) if x != "?"]
                    self.state_spec_list.append(line,ind)
                elif specs[0] == "no_transition":
                    ind = [idx for idx,x in enumerate(line[1:]) if x != "?"]
                    self.trans_spec_list.append(line,ind)
                elif specs[0] == "states":
                    self.state_count = specs[1]

        return 

    def state_spec(self):
        vertice_list = self.state_graph.V
        for vertice in vertice_list:
            states = vertice.split(",")
            for spec,idx in self.state_spec_list:
                
                ## if vertice state match the rule then skip. Otherwise add to final vertice
                states = [x for x in idx if states[x] == spec[x]]
                if len(states) == len(idx):
                    continue
                else:
                    self.vertex.append(vertice)
    
        return 
   
    def trans_spec(self):
        trans_list = self.state_graph.E
        for trans in trans_list:
            states = trans.split(",")
            match = 0
            for spec,idx in self.trans_spec_list:
                for id in idx:
                    if spec[id] == states[id]:
                        match +=1
                if match != len(idx) :
                    self.edge.append(trans)

        return

    def path_spec(self):
        
        # if no edges were removed or no vertices were removed then set it to the whole graph.
        if self.edge == []:
            self.edge = self.state_graph.E
        if self.vertex == []:
            self.vertex = self.state_graph.V
        
        #problems how to find a path between two states.
        
        return
 
