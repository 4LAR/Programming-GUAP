
import matplotlib.pyplot as plt
import numpy as np

# regression_line = lambda a, b: lambda x: a + (b * x)

def regression_line(a, b, x):
    return a + (b * x)

# Вычисление наклона линии (углового коэффициента)
def slope(xs, ys):
    # return xs.cov(ys) / xs.var()
    return np.cov(ys) / np.var(xs)

# Вычисление точки пересечения (с осью Y)
def intercept(xs, ys):
   # return ys.mean() - (xs.mean() * slope(xs, ys))
   return np.mean(ys) - np.mean(xs) * slope(xs, ys)

# вычисление остатков
def residuals(a, b, xs, ys):
    return [(regression_line(a, b, xs[i]) - ys[i]) for i in range(xs.size)]

def draw_graph(x, y):
    x = np.array(x)
    y = np.array(y)

    a  = intercept(x, y)
    b  = slope(x, y)
    print('Пересечение: %f, наклон: %f' % (a,b))

    resi_line = residuals(a, b, x, y)

    fig, ax = plt.subplots(nrows=2, ncols=1)
    range_line = range(-40, 30)
    x_line = np.array(range_line)
    y_line = np.array([regression_line(a, b, i) for i in range_line])
    # print(y_line)
    ax[0].plot(x, y, 'o', linewidth=1.0)
    ax[0].plot(x_line, y_line, linewidth=1.0)

    x1_line = np.array(range(-35, 20))
    y1_line = np.array([0 for _ in range(x1_line.size)])
    ax[1].plot(x, resi_line, 'o', linewidth=1.0)
    ax[1].plot(x1_line, y1_line, linewidth=1.0)

    plt.show()
