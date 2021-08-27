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



from src.graph import graph
from os import path

class specification_parser:

    def __init__(self, state_graph, specification_file):

        self.specication_file = specification_file
        self.state_graph = state_graph
        self.out_graph = graph()
        self.out_graph.name = "spec_"+self.state_graph.name
        self.specication_file
        self.path_spec_list = []
        self.state_spec_list = []
        self.trans_spec_list = []
        self.vertex = []
        self.edge = []
        self.state_count = len(state_graph.V[0].split(","))
        self.specification()
    
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
                    ind_1 = [idx for idx,x in enumerate(specs[1:self.state_count+1]) if x != "?"]
                    ind_2 = [idx for idx,x in enumerate(specs[self.state_count+1:]) if x != "?"]
                    self.path_spec_list.append((specs[1:self.state_count+1],ind_1,specs[self.state_count+1:],ind_2))

                elif specs[0] == "no_state":
                    ind = [idx for idx,x in enumerate(specs[1:]) if x != "?"]
                    self.state_spec_list.append((specs[1:],ind))
                elif specs[0] == "no_transition":
                    ind = [idx for idx,x in enumerate(specs[1:]) if x != "?"]
                    self.trans_spec_list.append((specs[1:],ind))


        return 

    def state_spec(self):
        vertice_list = self.state_graph.V
        for vertice in vertice_list:
            states = vertice.split(",")
            match = False
            for spec,idx in self.state_spec_list:
                
                ## if vertice state match the rule then skip. Otherwise add to final vertice
                matched_states = [x for x in idx if states[x] == spec[x]]
                if len(matched_states) == len(idx):
                    match = True
                    break

            # if it does not match with anything then append other skip
            if match != True:
                self.vertex.append(vertice)
    
        return 
   
    def trans_spec(self):
        trans_list = self.state_graph.E
        for trans in trans_list:

            if trans[0][0] in self.vertex:
                states = trans[0][0].split(",") + trans[0][1].split(",")
                match = False
                for spec,idx in self.trans_spec_list:
                    for id in idx:
                        if spec[id] == states[id]:
                            match = True
                            break
                    if match:
                        break
                if match != True:
                    self.edge.append(trans)


        return

    def path_spec(self):
        
        # if no edges were removed or no vertices were removed then set it to the whole graph.
        if self.edge == []:
            self.edge = self.state_graph.E
        if self.vertex == []:
            self.vertex = self.state_graph.V
        
        self.out_graph.from_vertice(self.vertex)
        self.out_graph.from_edge(self.edge)

        del self.state_graph
        no_path_found = 0
        #problems how to find a path between two states.
        for spec1,idx_1,spec2,idx_2 in self.path_spec_list:
            

            state1 = []
            state2 = []
            for vert_id,vert in enumerate(self.vertex):    
                # find all vertices that match the state in vertex list.
                # find if any vertex completes the path.
                # move to the next spec in the list. all spec must meet the stuff.

                state = vert.split(",")
                total_1 = [id for id in idx_1 if state[id] == spec1[id]]
                total_2 = [id for id in idx_2 if state[id] == spec2[id]]
                if len(total_1) == len(idx_1):
                    state1.append((vert,vert_id))

                if len(total_2) == len(idx_2):
                        state2.append(vert)
            
            for source,id in state1:
                for dest in state2:
                    
                    #mark all states as unmarked i.e they havent been traversed,
                    marked = [False] * (len(self.vertex))
                    
                    dest_id = self.out_graph.vert_dict[dest]
                    traversal = []
                    traversal.append(source)
                    marked[self.out_graph.vert_dict[source]] = True

                    # edge = edge,tran,W : edge is tuple of list of string defining the state list()
                    # iterate until traversal list is empty or dest is reached
                    while traversal and not marked[dest_id]:
                        
                        cur_state = traversal.pop()

                        for edge_id in self.out_graph[cur_state]:
                            edge = self.out_graph.E[edge_id]
                            edge_state = edge[0][1]
                            try:
                            
                                edge_state_id = self.out_graph.vert_dict[edge_state]
                                
                                #if at destination add to path found and break loop
                                if edge_state_id == dest_id:
                                    marked[dest_id] = True
                                    no_path_found += 1
                                    break

                                #if state no ttraversed then add to traversal list and mark as traversed
                                if not marked[edge_state_id]:
                                    traversal.append(edge_state)
                                    marked[edge_state_id] = True 
                            except KeyError:
                                print("removed state found.")
                        
                    if marked[dest_id]:
                        break
                
                if marked[dest_id]:
                    break
            
        
        if no_path_found == len(self.path_spec_list):
            return True
        
        else:
            return False
 
    def reduced_graph(self):
        self.state_spec()
        self.trans_spec()
        valid_graph = self.path_spec()
        if valid_graph:
            return self.out_graph
        else:
            return None
        