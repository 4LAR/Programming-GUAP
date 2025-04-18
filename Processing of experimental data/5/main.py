import numpy as np
import scipy.stats as stats

# Данные
x1 = np.array([-2, -1, 0, 1, 2, -3])
x2 = np.array([1, 3, 4, 6, 7, -10])
y = np.array([-11, -2, 7, 16, 26, -9])

x1_centered = x1 - np.mean(x1)
x2_centered = x2 - np.mean(x2)
# y_centered = y - np.mean(y) # убрал центрирование Y
y_centered = y
print(y_centered)

# Шаг 2: Составление матричного уравнения
X = np.column_stack((np.ones(len(x1_centered)), x1_centered, x2_centered))  # Добавляем столбец единиц
Y = y_centered  # Используем центрированное y

# Шаг 3: Оценка коэффициентов регрессии
beta = np.linalg.inv(X.T @ X) @ X.T @ Y
print("Коэффициенты регрессии:", beta)

# Шаг 4: Проверка адекватности уравнения регрессии
# Предсказанные значения
Y_pred = X @ beta

# Остатки
residuals = Y - Y_pred

# Средняя квадратичная ошибка (MSE)
MSE = np.mean(residuals**2)

# Общая сумма квадратов (SST)
SST = np.sum((Y - np.mean(Y))**2)

# Сумма квадратов регрессии (SSR)
SSR = np.sum((Y_pred - np.mean(Y))**2)

# Сумма квадратов остатков (SSE)
SSE = np.sum(residuals**2)

# Степени свободы
n = len(Y)
p = X.shape[1]  # Количество параметров (включая свободный член)
df_regression = p - 1
df_residual = n - p

# Средняя квадратичная регрессии (MSR) и средняя квадратичная остатков (MSE)
MSR = SSR / df_regression
MSE = SSE / df_residual

# Статистика F
F_statistic = MSR / MSE
F_critical = stats.f.ppf(1 - 0.05, df_regression, df_residual)

print(f"Статистика F: {F_statistic}, Критическое значение F: {F_critical}")

if F_statistic > F_critical:
    print("Модель адекватна.")
else:
    print("Модель неадекватна.")

# Шаг 5: Селекция факторов по критерию Стьюдента
# Стандартная ошибка коэффициентов
standard_errors = np.sqrt(np.diag(MSE * np.linalg.inv(X.T @ X)))

# t-статистика для каждого коэффициента
t_statistics = beta / standard_errors

# p-значения
p_values = 2 * (1 - stats.t.cdf(np.abs(t_statistics), df_residual))

print("t-статистики:", t_statistics)
print("p-значения:", p_values)

# Уровень значимости
alpha = 0.05
significant_factors = p_values < alpha
print("Значимые факторы:", significant_factors)

# Шаг 6: Повторная проверка адекватности после исключения незначимых факторов
# Исключаем незначимые факторы
X_significant = X[:, significant_factors]
beta_significant = np.linalg.inv(X_significant.T @ X_significant) @ X_significant.T @ y_centered

# Предсказанные значения для значимой модели
Y_pred_significant = X_significant @ beta_significant
residuals_significant = y_centered - Y_pred_significant

# Остатки
SSE_significant = np.sum(residuals_significant**2)
SSR_significant = np.sum((Y_pred_significant - np.mean(y_centered))**2)

# Степени свободы
n_significant = len(y_centered)
p_significant = X_significant.shape[1]
df_regression_significant = p_significant - 1
df_residual_significant = n_significant - p_significant

# Средняя квадратичная регрессии (MSR) и средняя квадратичная остатков (MSE)
MSR_significant = SSR_significant / df_regression_significant
MSE_significant = SSE_significant / df_residual_significant

# Статистика F для значимой модели
F_statistic_significant = MSR_significant / MSE_significant
F_critical_significant = stats.f.ppf(1 - 0.05, df_regression_significant, df_residual_significant)

print(f"Статистика F для значимой модели: {F_statistic_significant}, Критическое значение F: {F_critical_significant}")

if F_statistic_significant > F_critical_significant:
    print("Модель адекватна.")
else:
    print("Модель неадекватна.")

# Выводим коэффициенты значимой модели
print("Коэффициенты значимой модели:", beta_significant)
