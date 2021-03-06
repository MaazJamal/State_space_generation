from src.graph import graph

class path_analysis:

    def __init__(self, graph, objectives_file):
        self.graph = graph
        self.objective = objectives_file
        self.path_exists()

    # def parse_objectives(self):
        
    #     with open(self.objective,"r") as f:
    #         for line in f:
                

    def path_exists(self):
        
        vertex = self.graph.V
        visited = [[False,False] for i in range(len(vertex))]  
        traversal = []
        visited[0][0] = True
        traversal.append(vertex[0])
        count = 0
        out = []
        while traversal:

            vertice = traversal.pop()
            if count == 0:  
                out.append([0,vertice])
            edge_idx = self.graph[vertice]
            last_visited = vertice
            count += 1
            for edge_id in edge_idx:
                edge = self.graph.E[edge_id]
                edge_state = edge[0][1]
                try:
                    edge_state_id = self.graph.vert_dict[edge_state]
                    
                    if visited[edge_state_id][0] == False:
                        traversal.append(edge_state)

                        visited[edge_state_id][0] = True 
                except KeyError:
                    continue


        if count != len(vertex):
            error_str = [last_visited,"Not Visited:"]
            for  vidx,visit in enumerate(visited):
                if visit[0] == False:
                    error_str.append(vertex[vidx])
            error_str = "\n".join(error_str)
            raise ValueError("No path found to all vertices. Last vertice: "+error_str)

        # now find a path back to everything
        state_id = self.graph.vert_dict[last_visited]

        visited = [[False,False] for i in range(len(vertex))]  
        visited[state_id][0] = True
        traversal.append(vertex[state_id])
        self.not_allowed_states = []
        self.is_path = False

        count = 0
        while traversal:

            vertice = traversal.pop()
            edge_idx = self.graph[vertice]
            last_visited = vertice
            count += 1
            for edge_id in edge_idx:
                edge = self.graph.E[edge_id]
                edge_state = edge[0][1]
                
                try:
                    edge_state_id = self.graph.vert_dict[edge_state]
                    
                    if visited[edge_state_id][0] == False:
                        traversal.append(edge_state)
                        visited[edge_state_id][0] = True 
                    
                    if edge_state_id == 0:
                        traversal = []
                        break
                except KeyError:
                    self.not_allowed_states.append(edge_state)
                    print("Transition to not-allowed state found: "+edge_state)
        

        if edge_state_id != 0:
            raise ValueError("No return path found to start. Last vertice: " + last_visited)
        else:
            print("closed loop found")
            self.is_path = True
            return 
    

    def controllability(self):
        
        if self.is_path:
            vertex = self.graph.V
            visited = [False] * len(vertex)
            traversal = []
            visited[0] = True
            traversal.append(vertex[0])
            strong_transition = []
            weak_transition = []
            very_strong_transition = []
            while traversal:
                vertice = traversal.pop()
                edge_idx = self.graph[vertice]
                
                for edge_id in edge_idx:
                    edge = self.graph.E[edge_id]
                    edge_state = edge[0][1]
                    
                    if edge[1] == "ext":
                        
                        #if ext transition to state not on path then we have a problem.
                        if edge_state in self.not_allowed_states:
                            message = "".join(["Ext transition to not allowed state: ",edge[0][0],"->",edge[0][1],"Ext"])
                            print(message)
                            weak_transition.append(edge)
                        
                        else:
                            # Strongly controllable paths.
                            if edge[2][-1] == "fin":
                               strong_transition.append(edge)
                    
                    if edge[1] == "int":

                        # if there is a finite transition time.  then internal transition can move it to another state.
                        if edge[2][-1] == "fin":

                            if edge_state in self.not_allowed_states:
                                message = "".join(["Int transition to not allowed state: ",edge[0][0],"->",edge[0][1],"Ext"])
                                print(message)
                                weak_transition.append(edge)
                            
                            else:
                                very_strong_transition.append(edge)
                            
                        else:
                            if edge_state in self.not_allowed_states:
                                message = "".join(["Int transition to not allowed state: ",edge[0][0],"->",edge[0][1],"Ext"])
                                print(message)
                                strong_transition.append(edge)
                            else:
                                very_strong_transition.append(edge)


                    

                    try:
                        edge_state_id = self.graph.vert_dict[edge_state]
                    
                        if visited[edge_state_id] == False:
                            traversal.append(edge_state)
                            visited[edge_state_id] = True
                    except KeyError:
                        continue 

        return (very_strong_transition,strong_transition,weak_transition)
        
    
    def print_controllability(self,very_strong,strong,weak,dir="output/"):
        file_dir = dir+"/controllabilty.txt"
        with open(file_dir,"w+") as file:
            if len(weak) > 0:
                file.write("[weak]\n")
                for edge in weak:
                    transition = "".join(edge[0])
                    line = ",".join([transition,edge[1],edge[2][0],edge[2][1],edge[2][2],"\n"])
                    file.write(line)
            
            if len(strong) > 0:
                file.write("[strong]\n")
                for edge in strong:
                    transition = "".join(edge[0])
                    line = ",".join([transition,edge[1],edge[2][0],edge[2][1],edge[2][2],"\n"])
                    file.write(line)
      
            if len(very_strong) > 0:
                file.write("[very_strong]\n")
                for edge in very_strong:
                    transition = "".join(edge[0])
                    line = ",".join([transition,edge[1],edge[2][0],edge[2][1],edge[2][2],"\n"])
                    file.write(line)
    

    def inverse_devs(self, source_coupled,dir="output/"):
        # Use the coupled representation just for the coupled outputs adn inputs
        # The controller is an atomic model. Remember coupled models can be converted to 
        # atomic models using the closure under coupling property. 
        # the states are the states of the graph. The transitions are what we have.

        # How do we reduce the states and transitions? 

        Y = [port.split(".")[1] for port in source_coupled._input]
        X = [port.split(".")[1] for port in source_coupled._output]
        states = ["{}".format(state) for state in self.graph.V]
        ext = []
        int = [] 

        # Edge is structured as 3 tuple. 
        #   list of states. 0 is first state 1 is second state
        #   string int or ext
        #   list of transition. 0 is the port, 1 is the output, 2 is time advance


        for edge in self.graph.E:
            
            trans = "{}:{}|{}".format(edge[0][0],edge[0][1],edge[2][2])
            port_io = "{}|{}|".format(edge[2][0],edge[2][1])
               
            # invert ext to int and vice versa
            if edge[1] == "ext":
                int.append("Int = "+port_io+trans+"\n")
            elif edge[1] == "int":
                ext.append("Ext = "+port_io+trans+"\n")

        with open(dir+"/"+"inverse.txt","w+") as file:
            file.write("[inverse_atomic]\n")
            file.write("X = ")
            file.write(",".join(X))
            file.write("\n")
            file.write("Y = ")
            file.write(",".join(Y))
            file.write("\n")
            file.write("S = ")
            file.write("|".join(states))
            file.write("\n")
            file.writelines(ext)
            file.writelines(int)

            file.close()
        

            

            
