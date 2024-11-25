import time

def iterations(x, y):
    print(f"Вызов функции iterations({x}, {y})")
    result = 0
    while x - y + 1 >= 10:
        x -= 10
        result += 1
    return result

def recursive(x, y):
    print(f"Вызов функции recursive({x}, {y})")
    if x - y + 1 < 10:
        return 0
    else:
        return 1 + recursive(x - 10, y)

while True:
    try:
        x = int(input("Введите значение x: "))
        y = int(input("Введите значение y: "))

        # Измерение времени для итеративного способа
        start_time = time.time()
        iter_result = iterations(x, y)
        iter_time = time.time() - start_time

        print(f"Итеративный способ: f({x}, {y}) = {iter_result}, время выполнения: {iter_time:.6f} секунд")

        # Измерение времени для рекурсивного способа
        start_time = time.time()
        rec_result = recursive(x, y)
        rec_time = time.time() - start_time

        print(f"Рекурсивный способ: f({x}, {y}) = {rec_result}, время выполнения: {rec_time:.6f} секунд")

    except Exception as e:
        print("Пожалуйста, введите корректное целое число.")
