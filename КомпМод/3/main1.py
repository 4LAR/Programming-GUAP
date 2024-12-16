import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import r2_score

# Исходные данные
t = np.array([2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017])
Y = np.array([17.7, 17.9, 15.4, 15.5, 16.1, 19.5, 19.5, 19.4])

# Центрирование x (для улучшения численной стабильности)
x = t - t.mean()

# МНК для полинома 2-й степени: Y = a2*x^2 + a1*x + a0
A = np.vstack([x**2, x, np.ones_like(x)]).T
coeffs, _, _, _ = np.linalg.lstsq(A, Y, rcond=None)

a2, a1, a0 = coeffs
print(f"Коэффициенты для полинома 2-й степени: a2={a2:.4f}, a1={a1:.4f}, a0={a0:.4f}")

# Построение графика
x_fit = np.linspace(x.min(), x.max(), 100)
y_fit = a2*x_fit**2 + a1*x_fit + a0

plt.scatter(t, Y, color='red', label="Исходные данные")
plt.plot(t.mean() + x_fit, y_fit, label="Полином 2-й степени", color='blue')
plt.xlabel('Год')
plt.ylabel('Y(t)')
plt.legend()
plt.grid()
plt.show()
