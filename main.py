from src.read_model import read_model
from src.state_space import *
from src.specification_parser import specification_parser as sp
from src.path_analysis import path_analysis as pa

reader_obj = read_model("input")
atomics,coupleds = reader_obj.read_models()
graphs = state_space(coupleds[0])
state_graph_to_file(graphs,"output/")
spec_obj = sp(graphs, "input/spec/specification.txt")

out = spec_obj.reduced_graph()
del(spec_obj)
state_graph_to_file(out,"output/")
analysis = pa(out,"no")
analysis.path_exists()
analysis.inverse_devs(coupleds[0])
