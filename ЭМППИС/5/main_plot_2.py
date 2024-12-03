import numpy as np
import matplotlib.pyplot as plt
import time

# Функция De Jong's (f1)
def fDeJong(x):
    return np.sum(x**2)

# Параметры эволюционной стратегии
population_size = 600          # Размер популяции
max_generations = 1000          # Максимальное количество поколений
mutation_probability = 0.5     # Вероятность мутации
mutation_sigma = 0.1           # Стандартное отклонение для мутации
no_improvement_limit = 100     # Лимит поколений без улучшений для остановки

# Диапазоны для оптимизации
x_min, x_max = -5.12, 5.12
dimensions = 5  # Размерность задачи

# Инициализация начальной популяции
initial_population = np.random.uniform(x_min, x_max, (population_size, dimensions))

# Начало замера времени
start_time = time.time()

best_fitness_history = []
best_solution = initial_population[0]
best_fitness = fDeJong(best_solution)

# Основной цикл эволюционной стратегии
no_improvement_count = 0

for generation in range(max_generations):
    # Оценка популяции
    fitness_values = np.array([fDeJong(ind) for ind in initial_population])

    # Поиск лучшего решения
    current_best_fitness = np.min(fitness_values)
    best_idx = np.argmin(fitness_values)

    if current_best_fitness < best_fitness:
        best_fitness = current_best_fitness
        best_solution = initial_population[best_idx]
        no_improvement_count = 0  # Сброс при улучшении
    else:
        no_improvement_count += 1  # Увеличиваем счетчик без улучшения

    best_fitness_history.append(best_fitness)

    # Проверка условия остановки
    if no_improvement_count >= no_improvement_limit:
        print(f"Остановка на поколении {generation} из-за отсутствия улучшений за {no_improvement_limit} поколений.")
        break

    # Создание новой популяции
    new_population = []
    for _ in range(population_size):
        # Выбор родителя случайным образом
        parent = initial_population[np.random.choice(population_size)]

        # Мутация с вероятностью
        if np.random.rand() < mutation_probability:
            child = parent + np.random.normal(0, mutation_sigma, dimensions)
            child = np.clip(child, x_min, x_max)
        else:
            child = parent
        new_population.append(child)

    # print(np.array(new_population))
    # print()

    initial_population = np.array(new_population)

# Окончание замера времени
end_time = time.time()
execution_time = end_time - start_time

# Построение 3D-графика функции
x1 = np.linspace(x_min, x_max, 200)
x2 = np.linspace(x_min, x_max, 200)
x1, x2 = np.meshgrid(x1, x2)

# Вычисление значений функции для каждого элемента сетки
z = x1**2 + x2**2

fig = plt.figure(figsize=(12, 8))
ax = fig.add_subplot(111, projection='3d')
surf = ax.plot_surface(x1, x2, z, cmap='viridis', edgecolor='none')
ax.set_title("De Jong's function 1", fontsize=16, fontweight='bold')
ax.set_xlabel('$x_1$', fontsize=14)
ax.set_ylabel('$x_2$', fontsize=14)
ax.set_zlabel('$f(x_1, x_2)$', fontsize=14)
ax.view_init(elev=30, azim=240)

# Отображение найденного экстремума
ax.scatter(best_solution[0], best_solution[1], best_fitness,
           color='red', s=100, label='Найденный минимум')
ax.legend(loc='upper right')

# Вывод результатов в формате задания
print("РЕЗУЛЬТАТЫ ОПТИМИЗАЦИИ:")
print(f"Функция: De Jong's (f1)")
print(f"Глобальный минимум функции: f(x) = 0 при x = [0, 0]")
print(f"Лучшее найденное решение (ЭС): x = {best_solution}, f(x) = {best_fitness:.6f}")
print(f"Количество поколений: {generation + 1}")
print(f"Время выполнения программы: {execution_time:.2f} секунд")

plt.show()
