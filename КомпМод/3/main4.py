
from scipy.optimize import curve_fit
from numpy.polynomial.polynomial import Polynomial
import matplotlib.pyplot as plt
from sklearn.metrics import r2_score
import numpy as np

t = np.array([2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017])
Y = np.array([17.7, 17.9, 15.4, 15.5, 16.1, 19.5, 19.5, 19.4])


# Сравнение скорректированных R^2
r2_poly2 = max(r2_adjusted)  # Полином 2-й степени
r2_func3 = r2_score(Y, Y_fit3)
print(f"R^2 для полинома 2-й степени: {r2_poly2:.4f}")
print(f"R^2 для функции f3: {r2_func3:.4f}")

# Прогноз на 2018 год
t_future = 2018
x_future = t_future - t.mean()
y_pred_poly2 = a2*x_future**2 + a1*x_future + a0
y_pred_func3 = func3(t_future, a, b)

print(f"Прогноз на 2018 год:")
print(f"Полином 2-й степени: {y_pred_poly2:.2f}")
print(f"Функция f3: {y_pred_func3:.2f}")
