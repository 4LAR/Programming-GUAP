import matplotlib.pyplot as plt
import math

a = 2.37
b = -2.99
c = 0.56
e = 5 * math.pow(10, -4)
xMin = 0.53
xMax = 1.21
def func(x):
    return (b * c * c) * math.exp(c * x) + (a * a) / math.pow(x, 3)

fig, ax = plt.subplots()

X = [(xMin + e * i) for i in range(int((xMax - xMin)/2))]
Y = [func(x) for i in X]
ax.plot(X, Y)
plt.show()
