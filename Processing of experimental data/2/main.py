import numpy as np
import matplotlib.pyplot as plt
from scipy import stats

# Данные
intervals = [0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5]  # Границы интервалов
mi = [1, 12, 25, 30, 21, 9, 2]  # Число попаданий

# 1. Найти статистические вероятности попаданий значений случайной величины в интервалы
total_count = sum(mi)
probabilities = [m / total_count for m in mi]

# 2. Построить гистограмму распределения экспериментальных данных
plt.bar(intervals[:-1], probabilities, width=np.diff(intervals), edgecolor='black', alpha=0.7, label='Экспериментальные данные')

# 3. Найти теоретическую плотность нормального распределения
# Для этого найдем среднее и стандартное отклонение
mean = np.average(np.array(intervals[:-1]), weights=mi)
std_dev = np.sqrt(np.average((np.array(intervals[:-1]) - mean) ** 2, weights=mi))

# Создаем точки для теоретической плотности
x = np.linspace(0, 3.5, 100)
normal_pdf = stats.norm.pdf(x, mean, std_dev)

# Наносим теоретическую кривую на гистограмму
plt.plot(x, normal_pdf / normal_pdf.sum() * (np.diff(intervals).sum() / total_count), color='red', label='Теоретическая плотность нормального распределения')
plt.xlabel('Случайная величина')
plt.ylabel('Вероятность')
plt.title('Гистограмма распределения и теоретическая плотность')
plt.legend()
plt.show()

# 4. Проверка гипотезы о соответствии статистического и теоретического распределений
# Метод К. Пирсона
# Вычисляем ожидаемое количество попаданий в каждый интервал
expected = []
for i in range(len(intervals) - 1):
    expected_count = (stats.norm.cdf(intervals[i + 1], mean, std_dev) - stats.norm.cdf(intervals[i], mean, std_dev)) * total_count
    expected.append(expected_count)

# Преобразуем списки в массивы NumPy для удобства вычислений
observed = np.array(mi)
expected = np.array(expected)

# Вычисляем статистику хи-квадрат
chi_squared_stat = np.sum((observed - expected) ** 2 / expected)

# Степени свободы
degrees_of_freedom = len(observed) - 1 - 1  # минус 1 для оценивания параметров

# Критическое значение для уровня значимости
alpha = 0.05
critical_value = stats.chi2.ppf(1 - alpha, degrees_of_freedom)

# Результаты
print(f"Статистика хи-квадрат: {chi_squared_stat}")
print(f"Критическое значение: {critical_value}")

if chi_squared_stat < critical_value:
    print("Не отвергаем нулевую гипотезу: распределения соответствуют.")
else:
    print("Отвергаем нулевую гипотезу: распределения не соответствуют.")
