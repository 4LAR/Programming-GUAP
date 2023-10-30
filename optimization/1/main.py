import numpy as np
from sympy import *

def task1():
   
    print("----------задание 1----------")
    # Создаем матрицу размером (n+1) x (m+1)
    matrix = np.array([[1, 3, 4, 5, 0],
                    [4, -1, 0, 1, 2],
                    [3, 2, 5, 5, 3],
                    [-2, 0, 1, -1, 1],
                    [4, 6, 7, 11, -1]])

    # Находим максимальное количество линейно независимых векторов
    max_independent_vectors = np.argmax(matrix, axis=1)
    print("Максимальное количество линейно независимых векторов:", max_independent_vectors)

def task2():
    print("----------задание 2----------")
    matrix = Matrix([[1,3,4],
                    [4,-1,0],
                    [3,2,5],
                    [-2,0,1],
                    [4,6,7]])
    matrix.T.columnspace()
    print(matrix.rref())

def task3():
    print("----------задание 3----------")
    matrix = Matrix([[1,2,0,9],[-3,7,11,5],[-9,4,25,84],[3,12,-5,58]])
    matrix.row_del(2)
    matrix.col_del(1)
    print("минор ", matrix.det())

def task4():
    print("----------задание 4----------")
    matrix = Matrix([[1,2,0,9],[-3,7,11,5],[-9,4,25,84],[3,12,-5,58]])
    matrix.row_del(2)
    matrix.col_del(1)
    minor = matrix.det()
    print("алг доп", (-1)**5*minor)

def task5():
    print("----------задание 5----------")
    matrix = Matrix([[1,2,0,9],[-3,7,11,5],[-9,4,25,84],[3,12,-5,58]])
   
    matrix.row_del(1)
    matrix.row_del(2)
    matrix.col_del(0)
    matrix.col_del(1)
    print(matrix)
    print("минор", matrix.det())

def task6():#############################################
    print("----------задание 6----------")
    matrix = Matrix([[1,3,2,4,5],[0,0,-1,2,7],[3,9,6,12,15],[5,15,9,26,22],[5,15,9,26,22],[1,3,1,10,2]])
    
    print(matrix.rank() )


def task7():
    print("----------задание 7----------")
    A = np.array([[3,2,0],[1,-1,0], [0,5,1]])
    b = np.array([2,4,-1])
    u = np.linalg.solve(A,b)
    print('решение ',u)

def task8():############################################
    print("----------задание 8----------")
    x1,x2,x3=symbols('x1 x2 x3')
    y1 = x1+x2+3*x3-18
    y2 = 2*x1-x2+9*x3-30
    res = linsolve([y1,y2],[x1,x2])
    print(res)

def task9():
    print("----------задание 9----------")
    x1,x2,x3=symbols('x1 x2 x3')
    y1 = x1-2*x2+4*x3-6
    y2 = x1-2*x2+x3-4
    y3 = -3*x1+6*x2-12*x3+18
    res =linsolve([y1,x1],[y2,x2])
    print(res)

def task10():
    print("----------задание 10----------")
    x,y,z = symbols('x, у, z')
    A = Matrix([[1,2,3],[4,5,6], [7,8,10]])
    b = Matrix([3,6,9])
    u = linsolve([A,b],[x,y,z])
    print('решение ',u)

def task11():
    A = np.array([[-3,2,0], [1,4,-5]])
    B = np.array([[2,0],[-1,4],[3,-6]])
    print(B@A)

if __name__ == "__main__": 
 
    task11()