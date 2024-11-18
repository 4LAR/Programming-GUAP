from pulp import LpProblem, LpMinimize, LpVariable, lpSum, LpStatus, value

# Содержание питательных веществ в 1 кг каждого вида корма
feed_nutrients = {
    "I": [1, 2, 1],   # [A, B, C]
    "II": [3, 4, 4],
    "III": [4, 2, 3]
}

# Цены на 1 кг каждого вида корма
feed_prices = {
    "I": 9,
    "II": 12,
    "III": 10
}

# Минимальные требования к питательным веществам
min_requirements = {
    "A": 60,
    "B": 50,
    "C": 12
}

# Создание задачи
problem = LpProblem("Animal_Feed_Optimization", LpMinimize)

# Переменные
x1 = LpVariable("Feed_Type_I", lowBound=0)
x2 = LpVariable("Feed_Type_II", lowBound=0)
x3 = LpVariable("Feed_Type_III", lowBound=0)

# Целевая функция
problem += feed_prices["I"] * x1 + feed_prices["II"] * x2 + feed_prices["III"] * x3

# Ограничения
problem += feed_nutrients["I"][0] * x1 + feed_nutrients["II"][0] * x2 + feed_nutrients["III"][0] * x3 >= min_requirements["A"]  # A
problem += feed_nutrients["I"][1] * x1 + feed_nutrients["II"][1] * x2 + feed_nutrients["III"][1] * x3 >= min_requirements["B"]  # B
problem += feed_nutrients["I"][2] * x1 + feed_nutrients["II"][2] * x2 + feed_nutrients["III"][2] * x3 >= min_requirements["C"]  # C

# Решение задачи
problem.solve()

# Результаты
print("Статус:", LpStatus[problem.status])
print("Количество корма I вида:", value(x1))
print("Количество корма II вида:", value(x2))
print("Количество корма III вида:", value(x3))
print("Минимальные затраты:", value(problem.objective))
