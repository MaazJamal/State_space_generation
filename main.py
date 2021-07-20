from src.read_model import read_model

reader_obj = read_model("input")
atomics,coupled = reader_obj.read_models()
graphs = []