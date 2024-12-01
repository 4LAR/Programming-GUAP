import numpy as np
import time

# Функция De Jong's Function 1
def de_jong_function(x):
    return np.sum(x**2)

# Параметры эволюционной стратегии
population_size = 100  # Размер популяции
max_generations = 100  # Лимит поколений
mutation_probability = 0.3  # Вероятность мутации
mutation_sigma = 0.1  # Стандартное отклонение для мутации

# Границы переменных
bounds = (-5.12, 5.12)
dimensions = 3  # Размерность задачи

# Инициализация популяции
initial_population = np.random.uniform(bounds[0], bounds[1], (population_size, dimensions))

# Начало замера времени
start_time = time.time()

# История лучшей пригодности
best_fitness_history = []
best_solution = initial_population[0]
best_fitness = de_jong_function(best_solution)

# Основной цикл
for generation in range(max_generations):
    # Оценка популяции
    fitness_values = np.array([de_jong_function(ind) for ind in initial_population])

    # Поиск лучшего решения
    current_best_fitness = np.min(fitness_values)
    best_idx = np.argmin(fitness_values)
    if current_best_fitness < best_fitness:
        best_fitness = current_best_fitness
        best_solution = initial_population[best_idx]

    best_fitness_history.append(best_fitness)

    # Создание новой популяции
    new_population = []
    sorted_indices = np.argsort(fitness_values)
    selected_parents = initial_population[sorted_indices[:population_size // 2]]  # Выбор лучших 50%

    for _ in range(population_size):
        parent = selected_parents[np.random.choice(selected_parents.shape[0])]

        # Мутация
        if np.random.rand() < mutation_probability:
            child = parent + np.random.normal(0, mutation_sigma, dimensions)
            child = np.clip(child, bounds[0], bounds[1])  # Убедитесь, что значения остаются в пределах
        else:
            child = parent

        new_population.append(child)

    initial_population = np.array(new_population)

# Результаты
execution_time = time.time() - start_time
print(f"Лучшее найденное решение: x = {best_solution}")
print(f"Значение функции в этой точке: f(x) = {best_fitness:.6f}")
print(f"Известный оптимум: f(x) = 0 при x = [0, 0, ..., 0]")
print(f"Время выполнения программы: {execution_time:.2f} секунд")
