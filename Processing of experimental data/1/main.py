import numpy as np
import scipy.stats as stats
import matplotlib.pyplot as plt

# Чтение данных из файла
filename = 'data.txt'
data = np.loadtxt(filename)
length_data = len(data)

# 1. Оценка математического ожидания
mean_estimate = np.mean(data)
print(f"Оценка математического ожидания: {mean_estimate:.4f}")

# 2. Функция для вычисления дисперсии, СКО и доверительного интервала
def calculate_statistics(data):
    n = len(data)
    result = 0
    for i in range(n):
        result += (data[i] - mean_estimate) ** 2
    variance = (result / (n - 1))
    sko = np.sqrt(variance)
    inter = [mean_estimate - 2 * sko, mean_estimate + 2 * sko]
    return sko, variance, inter

# 3. Построение 95%-го доверительного интервала
std_dev, variance, confidence_interval = calculate_statistics(data)
print(f"Дисперсия: {variance:.4f}")
print(f"Стандартное отклонение: {std_dev:.4f}")
print(f"95%-й доверительный интервал: {confidence_interval}")

# 4. Отсечение аномальных наблюдений
filtered_data = data[(data >= confidence_interval[0]) & (data <= confidence_interval[1])]
print(f"Данные после отсеивания аномальных наблюдений: {filtered_data}")

# 5. Уточненная оценка математического ожидания
mean_estimate_refined = np.mean(filtered_data)
print(f"Уточненная оценка математического ожидания: {mean_estimate_refined:.4f}")

# 6. Доверительный интервал для уточненной оценки
std_dev_refined, variance_refined, confidence_interval_refined = calculate_statistics(filtered_data)
print(f"Дисперсия уточненной оценки: {variance_refined:.4f}")
print(f"Стандартное отклонение уточненной оценки: {std_dev_refined:.4f}")
print(f"95%-й доверительный интервал для уточненной оценки: {confidence_interval_refined}")

# 7. Проверка по заданной максимальной вероятной погрешности
max_error = 0.33
confidence_interval_max_error = (mean_estimate - max_error, mean_estimate + max_error)
print(f"Доверительный интервал по максимальной вероятной погрешности: {confidence_interval_max_error}")

# 8. Проверка попадания математического ожидания в интервал
probability_within_interval = stats.norm.cdf(confidence_interval_max_error[1], loc=mean_estimate, scale=std_dev) - \
                              stats.norm.cdf(confidence_interval_max_error[0], loc=mean_estimate, scale=std_dev)
print(f"Вероятность попадания математического ожидания в интервал: {probability_within_interval:.4f}")

# 9. Построение графика
x = np.linspace(min(data) - 1, max(data) + 1, 1000)  # Диапазон значений для графика
y = stats.norm.pdf(x, mean_estimate, std_dev)  # Значения функции плотности вероятности

plt.figure(figsize=(10, 6))
plt.plot(x, y, label='Нормальное распределение', color='blue')
plt.fill_between(x, y, where=(x >= confidence_interval[0]) & (x <= confidence_interval[1]), color='lightblue', alpha=0.5, label='95%-й доверительный интервал')
plt.axvline(mean_estimate, color='red', linestyle='--', label='Оценка математического ожидания')
plt.axvline(confidence_interval[0], color='green', linestyle='--', label='Нижняя граница доверительного интервала')
plt.axvline(confidence_interval[1], color='green', linestyle='--', label='Верхняя граница доверительного интервала')
plt.title('График нормального распределения')
plt.xlabel('Значения')
plt.ylabel('Плотность вероятности')
plt.legend()
plt.grid()
plt.show()
