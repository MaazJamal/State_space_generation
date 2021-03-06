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


#### Making the change so that their can only be one transition at a time. To avoid complications
### This is done by ensuring only one atomic model is allowed to change the state.
### I justify this by saying that in case multiple events happen at the same time then the system can 
### carry out multiple transitions in sequence. The state space graph should not be polluted.

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
    eic_exist = False

    if EIC.size == 0:
        eic_exist = False
    else:
        eic_exist = True
        external_coupled = EIC[:,2].tolist() #complete today
    ic_exist = True
    try:
        internal_coupled = IC[:,0].tolist() #complete today
    except IndexError: 
        ic_exist = False
    output_coupled = EOC[:,0].tolist() #complete tomorrow
        

    component_order = model._select

    #contains all the state combiniations 
    all_states = combinator(model)

    ## make connections 
    for component_idx,component in enumerate(component_order):
        atomic_model = model.component_dict[component]

        
        #find if component is in the external coupled list
        
        #index = external_coupled.index(component) if component in external_coupled else None
        if eic_exist:
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

                        ## These states are the states of the atomics. not the coupled state space
                        for state_index,state in enumerate(all_states[:,component_idx].tolist()):
                            if state.split(".")[1] == trans[2][0]:
                                state_1.append([state_index, state])
                            elif state.split(".")[1] == trans[2][1]:
                                state_2.append(state_index)
                        
                        # These states are combined states of the coupled model
                        for state1_id,state_name in state_1:
                            #convert to string
                            states = all_states[state1_id].tolist()

                            ## We need the position to distinguish between instances eof the same type
                            position = states.index(state_name)
                            state1_name = ",".join(states)
                            if state_graph.get(state1_name) is None:
                                state_graph.add_vertex(state1_name)

                            for state2_id in state_2:
                                
                                ## new code 
                                states_2 = all_states[state2_id].tolist()
                                matches = len([x for idx,x in enumerate(states_2) if x==states[idx] and idx !=position])
                                # if there are less matches than more than one atomic has changed state so we skip
                                if matches != (len(states_2)-1):
                                    continue
                                state2_name = ",".join(states_2)
                                
                                ### End of new code to prevent state transitions from multiple atomics from one input.
                                
                                if state_graph.get(state2_name) is None:
                                    state_graph.add_vertex(state2_name)
                                
                                W = [port,trans[1],trans[-1]]
                                trans_type = "ext"
                                edge = (state1_name,state2_name)
                                state_graph.add_edge(edge,trans_type,W)
            

        # Internal coupling space
        
        #index = [i for i,item in enumerate(internal_coupled) if component == item]
        #For Debugging
        if ic_exist:
            index = []
            for i,item in enumerate(internal_coupled):
                if component == item:
                    index.append(i)
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
                                state_1.append([state_index,state])
                            elif state.split(".")[1] == trans[2][1]:
                                state_2.append(state_index)
                                global_state_2.append(state_index)
                        
                        for state1_id,state_name in state_1:
                            #convert to string
                            states = all_states[state1_id].tolist()
                            position = states.index(state_name)

                            state1_name = ",".join(states)
                            if state_graph.get(state1_name) is None:
                                state_graph.add_vertex(state1_name)

                            for state2_id in state_2:

                                states_2 = all_states[state2_id].tolist()

                                #number of matches needs to be one less than total as the one atomic is always changing state
                                matches = len([x for idx,x in enumerate(states_2) if x==states[idx]])
                                ## there need to be an exact number of matches otherwise 
                                if matches != len(states_2)-1:
                                    continue
                                state2_name = ",".join(states_2)
    
                                if state_graph.get(state2_name) is None:
                                    state_graph.add_vertex(state2_name)
                                
                                W = [port,trans[1],trans[-1]]
                                trans_type = "int"
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
                        ### WE ARE USING THE IDX to find the The state the internal transition
                        # in the IC has transitioned to. This state needs to be the same in the 
                        # transition of the external state. i.e if x is the state transitioned to in ic 
                        #  then state space transition must be a,x -> b,x . x must stay the same while a - > is the 
                        # external transition of the second atomic. 
                        # BUG the IDX is not correct so the out_state does not take proper state values.
                        second_idx = model._select.index(second_atomic_name)
                        first_idx = model._select.index(component)
                        out_state = [all_states[:,first_idx][i].tolist() for i in global_state_2]
                        
                        for state_index,state in enumerate(all_states[:,second_idx].tolist()):
                            if state.split(".")[1] == trans[2][0]:
                                
                                cur_state = all_states[state_index,component_idx].tolist()
                                ## contains the output of stuff 


                                if cur_state in out_state :
                                    ext_state_1.append(state_index)
                            #The idx must correspond to the second atomic otherwise this will not work.
                            elif state.split(".")[1] == trans[2][1]:
                                ext_state_2.append(state_index)
                        
                        for state1_id in ext_state_1:
                            #convert to string
                            states = all_states[state1_id].tolist()
                            state1_name = ",".join(states)
                            if state_graph.get(state1_name) is None:
                                state_graph.add_vertex(state1_name)

                            for state2_id in ext_state_2:
                                states_2 = all_states[state2_id].tolist()
                                state2_name = ",".join(states_2)

                                #number of matches needs to be one less than total as the one atomic is always changing state
                                matches = len([x for idx,x in enumerate(states_2) if x==states[idx]])
                                ## there need to be an exact number of matches otherwise 
                                if matches != len(states_2)-1:
                                    continue
                            
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
                        states = all_states[state1_id].tolist()
                        state1_name = ",".join(states)
                        if state_graph.get(state1_name) is None:
                            state_graph.add_vertex(state1_name)

                        for state2_id in state_2:
                            
                            states_2 = all_states[state2_id].tolist()
                            #number of matches needs to be one less than total as the one atomic is always changing state
                            matches = len([x for idx,x in enumerate(states_2) if x==states[idx]])
                            ## there need to be an exact number of matches otherwise 
                            if matches != len(states_2)-1:
                                continue
                         
                            state2_name = ",".join(states_2)
                            if state_graph.get(state2_name) is None:
                                state_graph.add_vertex(state2_name)
                            
                            W = [port,trans[1],trans[-1]]
                            trans_type = "int"
                            edge = (state1_name,state2_name)
                            state_graph.add_edge(edge,trans_type,W)
 
        

    return state_graph


def state_graph_to_file(state_graph,dir, mode=0):
        dir = dir+"/"
        if not os.path.isdir(dir):
            raise NotADirectoryError()
        if state_graph is None:
            raise TypeError("state graph is empty. None Type recieved")
        filename = state_graph.name
        file = dir + filename + ".txt"
        file_vertice = dir + filename + "_vertice.txt"

        with open(file,"w") as f, open(file_vertice,"w") as fv:

            vertices = state_graph.graph_dict.keys()
            data_vertice = []
            data_vertice.append("Vertice: {}\nEdge: {}\n".format(len(state_graph.V),len(state_graph.E)))
            if mode == 0:
                for V in vertices:
                    data = []
                    if type(V) == str:
                        state = V
                    if type(V) == list:
                        state = ",".join(V)
                    vert = "".join(["V,",state,"\n"])
                    data.append(vert)
                    data_vertice.append(vert)
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
            fv.writelines(data_vertice)
        f.close()
        fv.close()

#TODO future State space of multiple models.
#def state_space_multiple():  