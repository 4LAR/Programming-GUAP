def fibonacci(n):
    # Генерация n чисел Фибоначчи
    fib_sequence = [0, 1]
    while len(fib_sequence) < n:
        fib_sequence.append(fib_sequence[-1] + fib_sequence[-2])
    return fib_sequence

def fibonacci_method(func, a, b, epsilon=1e-6, max_iterations=100):
    history = []
    # a, b - начальный интервал
    # epsilon - требуемая точность
    # max_iterations - максимальное количество итераций
    iteration = 0

    fib_numbers = fibonacci(max_iterations)
    n = len(fib_numbers) - 1

    x1 = a + (b - a) * (fib_numbers[n - 2] / fib_numbers[n])
    x2 = a + (b - a) * (fib_numbers[n - 1] / fib_numbers[n])

    f1 = func(x1)
    f2 = func(x2)

    for k in range(1, n - 1):
        history.append([iteration, a, b, (a + b) / 2])
        if f1 > f2:
            a = x1
            x1 = x2
            f1 = f2
            x2 = a + (b - a) * (fib_numbers[n - k - 1] / fib_numbers[n - k])
            f2 = func(x2)
        else:
            b = x2
            x2 = x1
            f2 = f1
            x1 = a + (b - a) * (fib_numbers[n - k - 2] / fib_numbers[n - k])
            f1 = func(x1)
        iteration += 1
    history.append([iteration, a, b, (a + b) / 2])
    return (a + b) / 2, history
