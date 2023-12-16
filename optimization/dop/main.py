from prettytable import PrettyTable

from methods.dihitomii import dihitomii_method
from methods.golden_section import golden_section_method
from methods.fibonacci import fibonacci_method
from utils import *

################################################################################

a = 0
b = 3

# Определение функции, для которой ищем корень
f = None
if AUTO:
    f = lambda x: x**2 - 4
    print("Функция: x**2 - 4")
    print("Отрезки: a = 0, b = 3")
    print()
else:
    f = read_function()
    a = input("A = ")
    b = input("B = ")

my_table = PrettyTable()
my_table.field_names = ["iter", "a", "b", "result"]
my_table.align["iter"] = "l"
my_table.align["a"] = "l"
my_table.align["b"] = "l"
my_table.align["result"] = "l"

################################################################################
my_table.clear_rows()
print(" [ Метод дихотомии ]")
result, history = dihitomii_method(f, a, b)
for el in slice(history):
    my_table.add_row(el)

print(my_table)
print("Приближенный корень:", result)
print()

################################################################################
my_table.clear_rows()
print(" [ Метод золотого сечения ]")
result, history = golden_section_method(f, a, b)
for el in slice(history):
    my_table.add_row(el)

print(my_table)
print("Приближенный корень:", result)
print()

################################################################################
my_table.clear_rows()
print(" [  Метод Фибоначчи ]")
result, history = fibonacci_method(f, a, b)
for el in slice(history):
    my_table.add_row(el)

print(my_table)
print("Приближенный корень:", result)
print()

################################################################################
