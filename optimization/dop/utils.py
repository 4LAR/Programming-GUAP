AUTO = True             # Использовать заранее заготовленную функцию
TABLE_DRAW_COUNT = 6    # количество выводимых строк в таблицах (только чётные числа)
SLICE_TABLE = True      # Сокращаться ли размер таблиц

# ввод функции пользователем
def read_function(prompt="Введите функцию: f(x) = "):
    while True:
        try:
            text_function = input(prompt)
            func = lambda x: eval(text_function, {"x": x})
            return func
        except Exception as e:
            print("Ошибка ввода: ", e)

# обрезка количества строк в таблице
def slice(arr):
    if not SLICE_TABLE:
        return arr

    if len(arr) <= TABLE_DRAW_COUNT + 1:
        return arr

    result = []
    for i in range(TABLE_DRAW_COUNT // 2):
        result.append(arr[i])
    result.append(["...", "...", "...", "..."])
    for i in range(TABLE_DRAW_COUNT // 2):
        result.append(arr[len(arr) - (TABLE_DRAW_COUNT // 2) + i])
    return result
