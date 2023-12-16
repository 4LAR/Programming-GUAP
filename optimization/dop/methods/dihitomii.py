
def dihitomii_method(func, a, b, epsilon=1e-6, max_iterations=100):
    history = []
    # a, b - начальный интервал
    # epsilon - требуемая точность
    # max_iterations - максимальное количество итераций

    iteration = 0
    while (b - a) / 2 > epsilon and iteration < max_iterations:
        c = (a + b) / 2
        history.append([iteration, a, b, c])
        if func(c) == 0:
            break
        elif func(a) * func(c) < 0:
            b = c
        else:
            a = c
        iteration += 1
    history.append([iteration, a, b, (a + b) / 2])
    return (a + b) / 2, history
