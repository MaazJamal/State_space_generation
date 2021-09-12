from src.read_model import read_model
from src.state_space import *
from src.specification_parser import specification_parser as sp
from src.path_analysis import path_analysis as pa
import argparse
import os
import posixpath

def single_loop():
    
    reader_obj = read_model("input")
    _,coupleds = reader_obj.read_models()
    graphs = state_space(coupleds[0])
    state_graph_to_file(graphs,"output/")
    spec_obj = sp(graphs, "input/spec/specification.txt")

    out = spec_obj.reduced_graph()
    del(spec_obj)
    state_graph_to_file(out,"output/")
    analysis = pa(out,"no")
    analysis.path_exists()
    analysis.inverse_devs(coupleds[0])
    return


def multiple_loop():


    # get all the child subdirectories

    sub_dir_name = next(os.walk("input/Models"))[1]
    dir = [os.path.abspath("input/Models/"+subdir) for subdir in sub_dir_name]
    dir = [f.replace(os.sep, posixpath.sep) for f in dir]

    for idx,model_dir in enumerate(dir):
        reader_obj = read_model(model_dir)
        _,coupleds = reader_obj.read_models()
        out_path = "output/Models/"+sub_dir_name[idx] 
        if not os.path.isdir(out_path):
            os.mkdir(out_path)

        graphs = state_space(coupleds[0])
        state_graph_to_file(graphs,out_path)
        spec_obj = sp(graphs, model_dir+"/spec/specification.txt")

        out = spec_obj.reduced_graph()
        del(spec_obj)
        state_graph_to_file(out,out_path)
        analysis = pa(out,"no")
        analysis.path_exists()
        very_strong_transition,strong_transition,weak_transition = analysis.controllability()
        
        analysis.print_controllability(very_strong_transition,strong_transition,weak_transition,out_path+"/")
        analysis.inverse_devs(coupleds[0],out_path)





if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Single or multiple models')
    parser.add_argument('--mode',"-m", dest="mode" ,type=int,
                    help='mode 0 for one model. 1 for multiple models')
 
    args = parser.parse_args()
    if args.mode == 0:
        single_loop()
    
    elif args.mode == 1:
        multiple_loop()