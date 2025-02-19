import numpy as np
import statsmodels.api as sm
import matplotlib.pyplot as plt

# Данные
x1 = np.array([-2, -1, 0, 1, 2, -3])
x2 = np.array([1, 3, 4, 6, 7, -10])
y = np.array([-11, -2, 7, 16, 26, -9])

# 1. Центрирование факторов
x1_centered = x1 - np.mean(x1)
x2_centered = x2 - np.mean(x2)

# 2. Составление матричного уравнения
X = np.vstack([np.ones(len(x1)), x1_centered, x2_centered]).T  # Матрица X
Y = y  # Вектор Y

# 3. Нахождение оценок коэффициентов регрессии
coefficients = np.linalg.solve(np.dot(X.T, X), np.dot(X.T, Y))
print(f"Коэффициенты регрессии: a0 = {coefficients[0]:.4f}, a1 = {coefficients[1]:.4f}, a2 = {coefficients[2]:.4f}")

# 4. Проверка адекватности уравнения регрессии по критерию Фишера
model = sm.OLS(Y, X).fit()
f_statistic = model.fvalue
p_value_f = model.f_pvalue
print(f"Критерий Фишера: F-статистика = {f_statistic:.4f}, p-значение = {p_value_f:.4f}")

alpha = 0.05
if p_value_f < alpha:
    print("Отвергаем нулевую гипотезу: модель адекватна.")
else:
    print("Не отвергаем нулевую гипотезу: недостаточно доказательств для утверждения о адекватности модели.")

# 5. Проверка значимости коэффициентов регрессии по критерию Стьюдента
summary = model.summary()
print(summary)

# Извлечение p-значений
p_values = summary.tables[1].data[1:]  # Получаем данные таблицы
p_values = np.array([row[4] for row in p_values], dtype=float)  # Извлекаем p-значения
insignificant = p_values[p_values > alpha]

if len(insignificant) > 0:
    print("Исключаем незначимые коэффициенты:", insignificant)
    # Повторная проверка модели без незначимых коэффициентов
    significant_x = X[:, 0]  # Оставляем только константу
    for i in range(1, len(p_values)):
        if p_values[i] <= alpha:
            significant_x = np.column_stack((significant_x, X[:, i]))

    model_reduced = sm.OLS(Y, significant_x).fit()

    # Проверка адекватности новой модели
    f_statistic_reduced = model_reduced.fvalue
    p_value_f_reduced = model_reduced.f_pvalue
    print(f"Критерий Фишера для уменьшенной модели: F-статистика = {f_statistic_reduced:.4f}, p-значение = {p_value_f_reduced:.4f}")

    if p_value_f_reduced < alpha:
        print("Отвергаем нулевую гипотезу: уменьшенная модель адекватна.")
    else:
        print("Не отвергаем нулевую гипотезу: недостаточно доказательств для утверждения о адекватности уменьшенной модели.")
else:
    print("Все коэффициенты значимы, повторная проверка не требуется.")
