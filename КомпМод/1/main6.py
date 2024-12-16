from sympy import symbols, Function, sqrt, diff, Eq, simplify, dsolve

# Определение переменных
x = symbols('x')
y = Function('y')(x)

# Первая производная y по x
dy = diff(y, x)

# Определение лагранжиана
F = sqrt(x) * dy**2 + (y**2) / (2 * x * sqrt(x))

# Частные производные
dFdy = diff(F, y)         # Производная по y
dFd1y = diff(F, dy)       # Производная по y'

# Производная по x от dF/dy'
d_dFd1y_dx = diff(dFd1y, x)

# Уравнение Эйлера-Лагранжа
L = dFdy - d_dFd1y_dx     # Левое выражение уравнения Эйлера-Лагранжа

# Приведение уравнения к стандартному виду
eqn = Eq(simplify(L), 0)

print("Уравнение Эйлера-Лагранжа:")
print(eqn)

# Решение уравнения
sol = dsolve(eqn)
print("Решение:")
print(sol)

eq1 = sol.subs({x:2, y:1})
eq2 = sol.subs({x:4 * (1/2), y:4})
coeffs = solve([eq1, eq2])
res = sol.subs(coeffs)
res.doit()
