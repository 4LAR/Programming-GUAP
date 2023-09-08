import numpy as np
from sympy import *

from file import *
from simple_numpy import *
from simple_sympy import *

# simple_numpy()

################################################################################

def draw_array(array, size_x, size_y):
    for y in range(size_y):
        for x in range(size_x):
            print("%.2lf" % array[x + y], end="\t")
        print()

def Minor_elem(array, i, j):
    array.row_del(i)
    array.col_del(j)
    return array

def sympy_to_array(array, size_x, size_y):
    result = []
    for y in range(size_y):
        result.append([])
        for x in range(size_x):
            result[y].append(float(array[x + y]))

    return np.array(result)

################################################################################

array = Matrix(read_array("input3.txt"))
print("Максимальное число линейних независимых векторов:", array.rank())
# print(array)
array_t = array.T.columnspace()
for el in array_t:
    print(el)
print("\n", array.rref()[0])
print("\n", array.rref()[1])

print("-" * 100)

minor_array = Minor_elem(array, 3, 2)
draw_array(minor_array, 3, 3)
print()
draw_array(pow(-1, 3 + 2) * minor_array, 3, 3)
print("-" * 100)

a = np.array([[3, 2, 0], [1, -1, 0], [0, 5, 1]])
b = np.array([2, 4, -1])
u = np.linalg.solve(a, b)
print(u)
print("Проверка:", (np.dot(a, u) == b))

################################################################################
x1, x2, x3 = symbols("x1 x2 x3")
y1 = x1 + x2 + 2 * x3 - 2
y2 = 2 * x1 + x2 + x3 - 3
out = linsolve([y1, y2], [x1, x2])
print("", out)
