import numpy as np

# чтение массива с файла
def read_array(file_name):
    result = []
    with open(file_name, "r", encoding="utf-8") as f:
        for row in f.read().split("\n"):
            if len(row) > 0:
                result.append([float(el) for el in row.split(" ") if len(el) > 0])

    return result
