import numpy as np
from file import *


def simple_numpy():
    array = np.array(read_array("input.txt"))
    array2 = np.array(read_array("input2.txt"))
    
    print(array)
    print(array2)

    print("-"*20)
    print(array - array2)
    print(array + array2)

    print("-"*20)
    print(np.linalg.det(array))

    print("-"*20)
    print(np.linalg.inv(array))

    print("-"*20)
    print(np.linalg.matrix_rank(array))
