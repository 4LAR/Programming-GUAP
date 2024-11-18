import numpy as np
from scipy.integrate import solve_bvp
import matplotlib.pyplot as plt

# Define the differential equation
def ode_system(x, y):
    # y[0] = y, y[1] = y'
    dydx = np.zeros((2, x.size))
    dydx[0] = y[1]
    dydx[1] = (3/4) * y[0] / x - (1/2) * (x**(-1/2)) * y[1]
    return dydx

# Define the boundary conditions
def bc(ya, yb):
    return np.array([ya[0] - 2, yb[0] - 4.5])

# Initial mesh and guess for y and y'
x = np.linspace(1, 4, 100)
y_guess = np.zeros((2, x.size))
y_guess[0] = 2 + (4.5 - 2) * (x - 1) / (4 - 1)  # Linear guess between the boundary values

# Solve the boundary value problem
solution = solve_bvp(ode_system, bc, x, y_guess)

# Check if the solution was successful
if solution.status == 0:
    print("Solution found successfully.")
else:
    print("Solution failed.")

# Plot the result
plt.plot(solution.x, solution.y[0], label='y(x)')
plt.xlabel('x')
plt.ylabel('y(x)')
plt.title('Solution of the Boundary Value Problem')
plt.legend()
plt.grid(True)
plt.show()
