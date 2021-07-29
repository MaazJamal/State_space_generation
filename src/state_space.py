#TODO using coupled models draw the state space of the model.

# Use select function to pick first component("atomic model") in the system to start 
# for this component check if there is any EIC that can trigger any changes. 
# Then look for the next component and check for any EIC that can trigger any change.
# Then look for IC and and see for which output does the system change state.
#  ### Important only consider transitions where a state change occurs otherwise we get
# loops in the graph. 
# Follow this with any EOC that have and output and see how the state changes.
# In all of these the select function tells us which component to transition first. 
# The select component also decides the order in which the states are represented.
# 
# 
# Some potential issues with this:
# 1- There is an assupmtion here that when all the transitions are catered for
# the model will represent the entire state space. Is this assumption valid?
# 2- By having combination of all the states are we in effect doing the same thing
# as what we did previousl with our cartesian product? 
# 3- Internal and external transitions of the model will be triggered by this. How will
# we cater for the scenario where both models have fin internal transition and will trigger 
# in some time?

from src.graph import graph
from src.coupled import coupled 
from src.atomic import atomic
import numpy as np
import itertools
import os

def combinator(model):
    
    #create the combination of all of the states in the system.
    component_order = model._select
    states = []

    for component in component_order:
        component_state = model.component_dict[component].state
        #add name of the component to the state so that we can distinguish it from others
        component_state = [".".join([component,state]) for state in component_state ]
        states.append(component_state)
    combinations = np.array(list(itertools.product(*states)))
    return combinations




def state_space(model):
    
    ####### REMOVE THIS LINE BEFORE RUNNING
    #model = coupled()
    state_graph = graph()
    state_graph.name = model.name + "_graph"
    EIC = np.array(model._EIC)
    EOC = np.array(model._EOC)
    IC = np.array(model._IC)
    external_coupled = EIC[:,2].tolist() #complete today
    internal_coupled = IC[:,0].tolist() #complete today
    output_coupled = EOC[:,0].tolist() #complete tomorrow
        

    component_order = model._select

    #contains all the state combiniations 
    all_states = combinator(model)

    ## make connections 
    for component_idx,component in enumerate(component_order):
        atomic_model = model.component_dict[component]

        ####### REMOVE THIS LINE BEFORE RUNNING
    #    atomic_model = atomic()
        
        #find if component is in the external coupled list
        
        #index = external_coupled.index(component) if component in external_coupled else None
        index = [i for i,item in enumerate(external_coupled) if component == item]
        if index != []:
            for idx in index:
                component_name_port = EIC[idx][2:]
                ext_trans = atomic_model.trans_ext
                ext_trans_port = [port for port in ext_trans if port[0] == component_name_port.tolist()[1]]
                for trans in ext_trans_port:
                    port = trans[0]
                    #if port == component_name_port.split('.')[1]:
                    #state_1 is the index of first state in the transition
                    state_1 = []
                    state_2 = []
                    for state_index,state in enumerate(all_states[:,component_idx].tolist()):
                        if state.split(".")[1] == trans[2][0]:
                            state_1.append(state_index)
                        elif state.split(".")[1] == trans[2][1]:
                            state_2.append(state_index)
                    
                    for state1_id in state_1:
                        #convert to string
                        state1_name = ",".join(all_states[state1_id].tolist())
                        if state_graph.get(state1_name) is None:
                            state_graph.add_vertex(state1_name)

                        for state2_id in state_2:
                            state2_name = ",".join(all_states[state2_id].tolist())
                            if state_graph.get(state2_name) is None:
                                state_graph.add_vertex(state2_name)
                            
                            W = [port,trans[1],trans[-1]]
                            trans_type = "ext"
                            edge = (state1_name,state2_name)
                            state_graph.add_edge(edge,trans_type,W)
        

        # Internal coupling space
        
        index = [i for i,item in enumerate(internal_coupled) if component == item]
        if index != []:
            for idx in index:


                #internal transition giving output
                ic_output_port = IC[idx][0:2]

                #external transition recieving input at second location
                ic_input_port = IC[idx][2:]
                
                int_trans = atomic_model.trans_int
                int_trans_port = [port for port in int_trans if port[0] == ic_output_port.tolist()[1]]

                second_atomic_name = ic_input_port.tolist()[0]
                second_atomic = model.component_dict[second_atomic_name]


                # two optimizations one the ext transition should check for input type if it does not match skip the transition
                # second the external transition should only cater for those states in which the state of the output atomic is the 
                # transitioned state..



                output_type = []
                global_state_2 = []
                for trans in int_trans_port:
                    port = trans[0]


                    # create output list so that we can chose external transitions that will trigger
                    if output_type == []:
                        output_type.append(trans[1])
                    elif output_type[-1] != trans[1]:
                        output_type.append(trans[1])


                    state_1 = []
                    state_2 = []
                    for state_index,state in enumerate(all_states[:,component_idx].tolist()):
                        if state.split(".")[1] == trans[2][0]:
                            state_1.append(state_index)
                        elif state.split(".")[1] == trans[2][1]:
                            state_2.append(state_index)
                            global_state_2.append(state_index)
                    
                    for state1_id in state_1:
                        #convert to string
                        state1_name = ",".join(all_states[state1_id].tolist())
                        if state_graph.get(state1_name) is None:
                            state_graph.add_vertex(state1_name)

                        for state2_id in state_2:
                            state2_name = ",".join(all_states[state2_id].tolist())
 
                            if state_graph.get(state2_name) is None:
                                state_graph.add_vertex(state2_name)
                            
                            W = [port,trans[1],trans[-1]]
                            trans_type = "ext"
                            edge = (state1_name,state2_name)
                            state_graph.add_edge(edge,trans_type,W)

                # All the external transitions
                ext_trans = second_atomic.trans_ext

                # The external transitions that match the IC port
                # with added check if the output type matches the transition

                ext_trans_port = [port for port in ext_trans if port[0] == ic_input_port.tolist()[1] and port[1] in output_type]

                for trans in ext_trans_port:


                    ext_state_1 = []
                    ext_state_2 = []

                    ### THE IDX needs to correspond to the second state. Find this ID

                    second_idx = model._select.index(second_atomic_name)
                    out_state = [all_states[:,idx][i].tolist() for i in global_state_2]
                    
                    for state_index,state in enumerate(all_states[:,second_idx].tolist()):
                        if state.split(".")[1] == trans[2][0]:
                            ### THIS IS NOT WORKING 
                            cur_state = all_states[state_index,component_idx].tolist()
                            ## contains the output of stuff 


                            if cur_state in out_state :
                                ext_state_1.append(state_index)
                        #The idx must correspond to the second atomic otherwise this will not work
                        elif state.split(".")[1] == trans[2][1]:
                            ext_state_2.append(state_index)
                    
                    for state1_id in ext_state_1:
                        #convert to string
                        state1_name = ",".join(all_states[state1_id].tolist())
                        if state_graph.get(state1_name) is None:
                            state_graph.add_vertex(state1_name)

                        for state2_id in ext_state_2:
                            state2_name = ",".join(all_states[state2_id].tolist())
 
                            if state_graph.get(state2_name) is None:
                                state_graph.add_vertex(state2_name)
                            
                            W = [port,trans[1],trans[-1]]
                            trans_type = "ext"
                            edge = (state1_name,state2_name)
                            state_graph.add_edge(edge,trans_type,W)


        # external coupling 
        index = [i for i,item in enumerate(output_coupled) if component == item]
        if index != []:
            for idx in index:
                component_name_port = EOC[idx][:2]
                int_trans = atomic_model.trans_int
                int_trans_port = [port for port in int_trans if port[0] == component_name_port.tolist()[1]]
                for trans in int_trans_port:
                    port = trans[0]
                    #if port == component_name_port.split('.')[1]:
                    #state_1 is the index of first state in the transition
                    state_1 = []
                    state_2 = []
                    for state_index,state in enumerate(all_states[:,component_idx].tolist()):
                        if state.split('.')[1] == trans[2][0]:
                            state_1.append(state_index)
                        elif state.split('.')[1]  == trans[2][1]:
                            state_2.append(state_index)
                    
                    for state1_id in state_1:
                        #convert to string
                        state1_name = ",".join(all_states[state1_id].tolist())
                        if state_graph.get(state1_name) is None:
                            state_graph.add_vertex(state1_name)

                        for state2_id in state_2:
                            state2_name = ",".join(all_states[state2_id].tolist())
                            if state_graph.get(state2_name) is None:
                                state_graph.add_vertex(state2_name)
                            
                            W = [port,trans[1],trans[-1]]
                            trans_type = "int"
                            edge = (state1_name,state2_name)
                            state_graph.add_edge(edge,trans_type,W)
 
        

    return state_graph


def state_graph_to_file(state_graph,dir):
        
        if not os.path.isdir(dir):
            raise NotADirectoryError()
        filename = state_graph.name
        file = dir + filename + ".txt"

        with open(file,"w") as f:

            vertices = state_graph.graph_dict.keys()
            for V in vertices:
                data = []
                if type(V) == str:
                    state = V
                if type(V) == list:
                    state = ",".join(V)
                data.append("".join(["V,",state,"\n"]))
                for edge_idx in state_graph.graph_dict[state]:
                    edge = state_graph.E[edge_idx]
                    edge_str = ["E"]
                    if type(edge[0][0]) == str:
                        edge_str.append(",".join(edge[0]))
                    elif type(edge[0][0]) == list:
                        combine_edge = ["/".join(edge[0][0]) , "/".join(edge[0][1])]
                        edge_str.append(",".join(combine_edge))
                    edge_str.append(edge[1])
                    edge_str.append(",".join(edge[2]))
                    data.append("".join([",".join(edge_str),"\n"]))
                    
                f.writelines(data)
        f.close()

#TODO future State space of multiple models.
#def state_space_multiple():  