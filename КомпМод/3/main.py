import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from numpy.polynomial.polynomial import Polynomial
from sklearn.metrics import r2_score, mean_absolute_error, mean_squared_error

# Исходные данные
t = np.array([2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017])
Y = np.array([17.7, 17.9, 15.4, 15.5, 16.1, 19.5, 19.5, 19.4])

# Центрирование для улучшения стабильности
x = t - t.mean()

# --- 1. Полином 2-й степени МНК ---
# Создаем матрицу A для полинома 2-й степени
A = np.vstack([x**2, x, np.ones_like(x)]).T
coeffs, _, _, _ = np.linalg.lstsq(A, Y, rcond=None)
a2, a1, a0 = coeffs

# Значения для полинома 2-й степени
x_fit = np.linspace(x.min(), x.max(), 100)
y_fit_poly2 = a2 * x_fit**2 + a1 * x_fit + a0

# --- 2. Подбор полиномиальных моделей разной степени ---
degrees = [1, 2, 3, 4, 5]  # Степени полиномов
r2_adjusted = []

plt.figure(figsize=(10, 6))
plt.scatter(t, Y, color='red', label="Исходные данные")

for d in degrees:
    poly = Polynomial.fit(t, Y, d)
    Y_pred = poly(t)
    r2 = r2_score(Y, Y_pred)
    n, k = len(Y), d + 1
    r2_adj = 1 - (1 - r2) * (n - 1) / (n - k - 1)
    r2_adjusted.append(r2_adj)
    plt.plot(t, Y_pred, label=f"Полином {d}-й степени")

plt.plot(t.mean() + x_fit, y_fit_poly2, label="Полином 2-й степени (ручной МНК)", color='blue', linestyle='--')
plt.xlabel('Год')
plt.ylabel('Y(t)')
plt.legend()
plt.grid()
plt.title("Полиномиальные модели")
plt.show()

# Лучшая степень полинома
best_degree = degrees[np.argmax(r2_adjusted)]
print(f"Лучшая степень полинома: {best_degree}, скорректированный R^2 = {max(r2_adjusted):.4f}")

# --- 3. Аппроксимация функцией f3(x) ---
# Функция sqrt(x+1)/a + b
def func3(x, a, b):
    return np.sqrt(x + 1) / a + b

# Подгонка параметров
params, _ = curve_fit(func3, t, Y, p0=[3, 1], maxfev=10000)
a, b = params
print(f"Параметры модели f3: a={a:.4f}, b={b:.4f}")

# Значения для функции f3
Y_fit3 = func3(t, a, b)

# Построение графика
plt.figure(figsize=(10, 6))
plt.scatter(t, Y, color='red', label="Исходные данные")
plt.show()
