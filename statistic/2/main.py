
from scipy.optimize import linprog

obj = [-3, -3]

lhs_ineq = [[3, 2],
            [1, 5],
            [1, 1]]

rhs_ineq = [8, 6, 3]

bnd = [(0, float("inf")),  # Границы x
       (0, float("inf"))]  # Границы y

opt = linprog(c=obj, A_ub=lhs_ineq, b_ub=rhs_ineq, method="highs")

print(opt)
print("оптимальное решение: X:", max(opt.x))
