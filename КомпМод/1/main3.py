import numpy as np
from scipy.integrate import solve_bvp
import matplotlib.pyplot as plt

# Определяем систему дифференциальных уравнений
def ode_system(x, y):
    # y[0] = y, y[1] = y'
    dydx = np.zeros((2, x.size))  # Создаем массив для производных
    dydx[0] = y[1]  # Первая производная y по x
    dydx[1] = (3/4) * y[0] / x - (1/2) * (x**(-1/2)) * y[1]  # Второе дифференциальное уравнение
    return dydx

# Определяем граничные условия
def bc(ya, yb):
    return np.array([ya[0] - 2, yb[0] - 4.5])  # Условия на границах: y(1) = 2 и y(4) = 4.5

# Начальная сетка и предположение для y и y'
x = np.linspace(1, 4, 100)  # Создаем массив x от 1 до 4 с 100 точками
y_guess = np.zeros((2, x.size))  # Инициализируем массив для предположений
y_guess[0] = 2 + (4.5 - 2) * (x - 1) / (4 - 1)  # Линейное предположение между граничными значениями

# Решаем задачу краевых значений
solution = solve_bvp(ode_system, bc, x, y_guess)

# Проверяем, была ли успешной находка решения
if solution.status == 0:
    print("Решение найдено успешно.")
else:
    print("Не удалось найти решение.")

# Строим график результата
plt.plot(solution.x, solution.y[0], label='y(x)')  # График y(x)
plt.xlabel('x')  # Подпись оси x
plt.ylabel('y(x)')  # Подпись оси y
plt.title('Решение задачи краевых значений')  # Заголовок графика
plt.legend()  # Легенда графика
plt.grid(True)  # Включаем сетку
plt.show()  # Отображаем график
