from src.read_model import read_model
from src.state_space import state_space

reader_obj = read_model("input")
atomics,coupled = reader_obj.read_models()
graphs = state_space(coupled[0])
print(graphs)