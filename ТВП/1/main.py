# Глобальные переменные для подсчета числа вызовов функций
iter_count = 0
rec_count = 0

# Итеративная функция для вычисления x - y + 1
def iterative_function(x, y):
    global iter_count                                                           # Используем глобальную переменную для подсчета числа вызовов
    result = x                                                                  # Начальное значение результата равно x
    for _ in range(y):                                                          # Цикл, который выполняется y раз
        iter_count += 1                                                         # Увеличиваем счетчик вызовов итеративной функции
        result -= 1                                                             # На каждой итерации уменьшаем результат на 1
    return result + 1                                                           # Возвращаем результат с добавлением 1

# Рекурсивная функция для вычисления x - y + 1
def recursive_function(x, y):
    global rec_count                                                            # Используем глобальную переменную для подсчета числа вызовов
    rec_count += 1                                                              # Увеличиваем счетчик вызовов рекурсивной функции
    if y == 0:                                                                  # Базовый случай: если y равно 0
        return x + 1
    else:                                                                       # Рекурсивный случай
        return recursive_function(x, y - 1) - 1

x = int(input("Введите значение x: "))                                          # Ввод значения x
y = int(input("Введите значение y: "))                                          # Ввод значения y

# Вычисление итеративным способом
iterative_result = iterative_function(x, y)                                     # Вызов итеративной функции
print(f"Результат итеративного вычисления: {iterative_result}")                 # Вывод результата итеративного вычисления

# Вычисление рекурсивным способом
recursive_result = recursive_function(x, y)                                     # Вызов рекурсивной функции
print(f"Результат рекурсивного вычисления: {recursive_result}")                 # Вывод результата рекурсивного вычисления

# Вывод количества вызовов функций
print(f"Количество вызовов итеративной функции: {iter_count}")                  # Вывод числа вызовов итеративной функции
print(f"Количество вызовов рекурсивной функции: {rec_count}")                   # Вывод числа вызовов рекурсивной функции
