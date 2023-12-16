def golden_section_method(func, a, b, epsilon=1e-6, max_iterations=100):
    history = []
    # a, b - начальный интервал
    # epsilon - требуемая точность
    # max_iterations - максимальное количество итераций

    # Вычисление точек деления интервала
    phi = (1 + 5**0.5) / 2  # Значение золотого сечения
    x1 = b - (b - a) / phi
    x2 = a + (b - a) / phi

    # Вычисление значений функции в точках деления
    f1 = func(x1)
    f2 = func(x2)

    iteration = 0
    while abs(b - a) > epsilon and iteration < max_iterations:
        history.append([iteration, a, b, (a + b) / 2])
        if f1 < f2:
            b = x2
            x2 = x1
            f2 = f1
            x1 = b - (b - a) / phi
            f1 = func(x1)
        else:
            a = x1
            x1 = x2
            f1 = f2
            x2 = a + (b - a) / phi
            f2 = func(x2)

        iteration += 1
    history.append([iteration, a, b, (a + b) / 2])
    return (a + b) / 2, history
