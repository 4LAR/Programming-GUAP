import sympy as sp

# Определяем переменную x и функцию y(x)
x = sp.symbols('x')
y = sp.Function('y')(x)
y_prime = y.diff(x)

# Определение функционала
L = sp.sqrt(x) * y_prime**2 + (y**2) / (2 * x * sp.sqrt(x))

# Применение уравнения Эйлера-Лагранжа
# Находим производные: частные производные лагранжиана по y и y'
dL_dy_prime = sp.diff(L, y_prime)
dL_dy = sp.diff(L, y)

# Производная по x от dL/dy'
d_dx_dL_dy_prime = sp.diff(dL_dy_prime, x)

# Уравнение Эйлера-Лагранжа
euler_lagrange_eq = sp.Eq(d_dx_dL_dy_prime - dL_dy, 0)

# Решаем уравнение Эйлера-Лагранжа относительно y(x)
solution = sp.dsolve(euler_lagrange_eq, y)
print(solution)

# # Определяем граничные условия
# y1 = 2  # y(1) = 2
# y4 = 4.5  # y(4) = 4.5
#
# # Записываем общее решение
# general_solution = C1 / sp.sqrt(x) + C2 * x
#
# # Подставляем граничные условия в общее решение
# eq1 = sp.Eq(general_solution.subs(x, 1), y1)
# eq2 = sp.Eq(general_solution.subs(x, 4), y4)
#
# # Решаем систему уравнений относительно C1 и C2
# constants = sp.solve([eq1, eq2], (C1, C2))
