from scipy.optimize import curve_fit
from numpy.polynomial.polynomial import Polynomial
import matplotlib.pyplot as plt
from sklearn.metrics import r2_score
import numpy as np

t = np.array([2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017])
Y = np.array([17.7, 17.9, 15.4, 15.5, 16.1, 19.5, 19.5, 19.4])
# Модель функции
def func3(x, a, b):
    return np.sqrt(x + 1) / a + b

# Увеличиваем maxfev и задаём начальные приближения
params, _ = curve_fit(func3, t, Y, p0=[3, 1], maxfev=10000)
a, b = params
print(f"Параметры модели f3: a={a:.4f}, b={b:.4f}")

# Расчёт значений модели
Y_fit3 = func3(t, a, b)

# Построение графика
plt.scatter(t, Y, color='red', label="Исходные данные")
plt.plot(t, Y_fit3, label="f3(x) = sqrt(x+1)/a + b", color='green')
plt.xlabel('Год')
plt.ylabel('Y(t)')
plt.legend()
plt.grid()
plt.show()
