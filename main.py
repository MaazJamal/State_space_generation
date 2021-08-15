from src.read_model import read_model
from src.state_space import *
from src.specification_parser import specification_parser as sp

reader_obj = read_model("input")
atomics,coupled = reader_obj.read_models()
graphs = state_space(coupled[0])
state_graph_to_file(graphs,"output/")
spec_obj = sp(graphs, "input/spec/specification.txt")

out = spec_obj.reduced_graph()
state_graph_to_file(out,"output/")