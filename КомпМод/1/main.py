from pulp import LpProblem, LpMinimize, LpVariable, lpSum, LpStatus, value

   # Создание задачи
   problem = LpProblem("Animal_Feed_Optimization", LpMinimize)

   # Переменные
   x1 = LpVariable("Feed_Type_I", lowBound=0)
   x2 = LpVariable("Feed_Type_II", lowBound=0)
   x3 = LpVariable("Feed_Type_III", lowBound=0)

   # Целевая функция
   problem += 9 * x1 + 12 * x2 + 10 * x3

   # Ограничения
   problem += x1 + 3 * x2 + 4 * x3 >= 60  # Питательное вещество A
   problem += 2 * x1 + 4 * x2 + 2 * x3 >= 50  # Питательное вещество B
   problem += x1 + 4 * x2 + 3 * x3 >= 12  # Питательное вещество C

   # Решение задачи
   problem.solve()

   # Результаты
   print("Статус:", LpStatus[problem.status])
   print("Количество корма I вида:", value(x1))
   print("Количество корма II вида:", value(x2))
   print("Количество корма III вида:", value(x3))
   print("Минимальные затраты:", value(problem.objective))
