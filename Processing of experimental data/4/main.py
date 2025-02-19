import numpy as np
import statsmodels.api as sm
import matplotlib.pyplot as plt

# Данные
x = np.array([-3, -1, 0, 2, 3])
y = np.array([2, 8, 9, 3, 1])

# 1. Составление системы нормальных уравнений
X = np.vstack([np.ones(len(x)), x, x**2]).T  # Матрица X
Y = y  # Вектор Y

# 2. Нахождение оценок коэффициентов регрессии
XtX = np.dot(X.T, X)
XtY = np.dot(X.T, Y)
coefficients = np.linalg.solve(XtX, XtY)

print(f"Коэффициенты регрессии: a0 = {coefficients[0]:.4f}, a1 = {coefficients[1]:.4f}, a2 = {coefficients[2]:.4f}")

# 3. Расчеты в матричной форме
X_with_const = sm.add_constant(X[:, 1:])  # Добавляем константу
model = sm.OLS(Y, X_with_const).fit()

# 4. Проверка адекватности уравнения регрессии по критерию Фишера
f_statistic = model.fvalue
p_value_f = model.f_pvalue
print(f"Критерий Фишера: F-статистика = {f_statistic:.4f}, p-значение = {p_value_f:.4f}")

alpha = 0.01
if p_value_f < alpha:
    print("Отвергаем нулевую гипотезу: модель адекватна.")
else:
    print("Не отвергаем нулевую гипотезу: недостаточно доказательств для утверждения о адекватности модели.")

# 5. Проверка значимости коэффициентов регрессии по критерию Стьюдента
summary = model.summary()
print(summary)

# 6. Повторная проверка адекватности уравнения регрессии после исключения незначимых коэффициентов
# Извлечение p-значений
p_values = summary.tables[1].data[1:]  # Получаем данные таблицы
p_values = np.array([row[4] for row in p_values], dtype=float)  # Извлекаем p-значения
insignificant = p_values[p_values > alpha]

if len(insignificant) > 0:
    print("Исключаем незначимые коэффициенты:", insignificant)
    # Повторная проверка модели без незначимых коэффициентов
    significant_x = X[:, 1]  # Оставляем только x
    model_reduced = sm.OLS(Y, sm.add_constant(significant_x)).fit()

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

# Визуализация
plt.scatter(x, y, color='blue', label='Данные')
x_fit = np.linspace(-4, 4, 100)
y_fit = coefficients[0] + coefficients[1] * x_fit + coefficients[2] * x_fit**2
plt.plot(x_fit, y_fit, color='red', label='Регрессионная модель')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Регрессионная модель второй степени')
plt.legend()
plt.grid()
plt.show()
