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

def interv(data_):
    result = [0 for _ in range(length_data)]
    for i in range(length_data):
        result += (data[i] - mean_estimate) ** 2

    disp = (result / (length_data - 1))[0]

    sko = np.sqrt(disp)

    inter = [mean_estimate - 2 * sko, mean_estimate + 2 * sko]

    return inter, result, sko, disp

inter, arr, sko, disp = interv(data)

print("Интервал", inter)
print("Массив", arr)
print("СКО",  sko)
print("Диперсия", disp)

# 2. Построение 95%-го доверительного интервала
n = len(data)
std_dev = np.std(data, ddof=1)  # Стандартное отклонение с поправкой на выборку
z_value = stats.norm.ppf(0.975)  # z-критерий для 95% доверительного интервала

# !!!!!!!! СКО - я хз что это но это налдо посчитать
# !!!!!!!!! 11 интервалов должно быть т.к. на входе 12
margin_of_error = z_value * (std_dev / np.sqrt(n))
print(margin_of_error)
confidence_interval = (mean_estimate - margin_of_error, mean_estimate + margin_of_error)
print(confidence_interval)
print(f"95%-й доверительный интервал: {confidence_interval}")

# 3. Отсечение аномальных наблюдений
filtered_data = data[(data >= confidence_interval[0]) & (data <= confidence_interval[1])]
print(f"Данные после отсеивания аномальных наблюдений: {filtered_data}")

# 4. Уточненная оценка математического ожидания
mean_estimate_refined = np.mean(filtered_data)
print(f"Уточненная оценка математического ожидания: {mean_estimate_refined:.4f}")

# 5. Проверка качества оценивания
# а. Доверительный интервал для уточненной оценки
n_refined = len(filtered_data)
std_dev_refined = np.std(filtered_data, ddof=1)

margin_of_error_refined = z_value * (std_dev_refined / np.sqrt(n_refined))
confidence_interval_refined = (mean_estimate_refined - margin_of_error_refined, mean_estimate_refined + margin_of_error_refined)
print(f"95%-й доверительный интервал для уточненной оценки: {confidence_interval_refined}")

# б. Проверка по заданной максимальной вероятной погрешности
max_error = 0.33
confidence_level = 0.88
z_value_max_error = stats.norm.ppf((1 + confidence_level) / 2)

# Доверительный интервал по максимальной вероятной погрешности
confidence_interval_max_error = (mean_estimate - max_error, mean_estimate + max_error)
print(f"Доверительный интервал по максимальной вероятной погрешности: {confidence_interval_max_error}")

# Проверка попадания математического ожидания в интервал
probability_within_interval = stats.norm.cdf(
    confidence_interval_max_error[1],
    loc=mean_estimate, scale=std_dev) - stats.norm.cdf(confidence_interval_max_error[0],
    loc=mean_estimate,
    scale=std_dev
)
print(f"Вероятность попадания математического ожидания в интервал: {probability_within_interval:.4f}")

# Построение графика
x = np.linspace(-5, 15, 1000)  # Диапазон значений для графика
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
