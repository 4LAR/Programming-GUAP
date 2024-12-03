import numpy as np
import matplotlib.pyplot as plt

# Целевая функция Де Йонга
def f_dejong(x):
    return np.sum(x**2, axis=1)

# Генетический алгоритм
def genetic_algorithm(n, pop_size, mutation_prob, max_generations):
    # Инициализация популяции
    population = np.random.uniform(-5.12, 5.12, (pop_size, n))
    fitness_scores = f_dejong(population)
    best_solution = population[np.argmin(fitness_scores)]
    best_fitness = np.min(fitness_scores)
    fitness_history = [best_fitness]

    for generation in range(max_generations):
        # Селекция (турнирный отбор)
        selected = []
        for _ in range(pop_size):
            i, j = np.random.choice(pop_size, 2, replace=False)
            selected.append(population[i] if fitness_scores[i] < fitness_scores[j] else population[j])
        parents = np.array(selected)

        # Кроссовер (одноточечный)
        offspring = []
        for i in range(0, pop_size, 2):
            parent1, parent2 = parents[i], parents[(i+1) % pop_size]
            crossover_point = np.random.randint(1, n)
            child1 = np.hstack((parent1[:crossover_point], parent2[crossover_point:]))
            child2 = np.hstack((parent2[:crossover_point], parent1[crossover_point:]))
            offspring.extend([child1, child2])
        offspring = np.array(offspring[:pop_size])

        # Мутация
        mutation_mask = np.random.rand(pop_size, n) < mutation_prob
        offspring[mutation_mask] += np.random.uniform(-0.1, 0.1, np.sum(mutation_mask))
        offspring = np.clip(offspring, -5.12, 5.12)

        # Обновление популяции
        population = offspring
        fitness_scores = f_dejong(population)

        # Обновление лучшего решения
        current_best_index = np.argmin(fitness_scores)
        if fitness_scores[current_best_index] < best_fitness:
            best_fitness = fitness_scores[current_best_index]
            best_solution = population[current_best_index]

        fitness_history.append(best_fitness)
        print(f"best_fitness: {best_fitness}, best_solution: {best_solution}")

    return best_solution, best_fitness, fitness_history, population

# Визуализация в 3D
def plot_results_3d(best_solution, population, fitness_history):
    # Определение сетки для визуализации функции
    x = np.linspace(-5.12, 5.12, 200)
    y = np.linspace(-5.12, 5.12, 200)
    X, Y = np.meshgrid(x, y)
    Z = X**2 + Y**2

    # Создание 3D-графика
    fig = plt.figure(figsize=(12, 8))
    ax = fig.add_subplot(111, projection='3d')
    ax.plot_surface(X, Y, Z, cmap='viridis', alpha=0.8, edgecolor='none')

    # Отображение популяции
    ax.scatter(population[:, 0], population[:, 1], f_dejong(population), color='blue', s=20, label='Популяция')
    # Отображение найденного минимума
    ax.scatter(best_solution[0], best_solution[1], f_dejong(np.array([best_solution]))[0],
               color='red', s=100, label='Найденный минимум')

    # Настройки графика
    ax.set_title("Функция Де Йонга и найденный минимум", fontsize=16)
    ax.set_xlabel("x1", fontsize=14)
    ax.set_ylabel("x2", fontsize=14)
    ax.set_zlabel("f(x)", fontsize=14)
    ax.legend()
    plt.show()

    # График изменения значений функции на протяжении поколений
    plt.figure(figsize=(10, 6))
    plt.plot(fitness_history, label='Лучшее значение функции')
    plt.title("Сходимость генетического алгоритма")
    plt.xlabel("Поколение")
    plt.ylabel("Значение функции")
    plt.legend()
    plt.grid()
    plt.show()

# Параметры
n = 5  # Размерность задачи
pop_size = 50  # Размер популяции
mutation_prob = 0.1  # Вероятность мутации
max_generations = 40  # Количество поколений

# Запуск генетического алгоритма
best_solution, best_fitness, fitness_history, final_population = genetic_algorithm(n, pop_size, mutation_prob, max_generations)

# Вывод результатов
print(f"Найденное решение: {best_solution}")
print(f"Значение функции в найденной точке: {best_fitness}")

# Визуализация
plot_results_3d(best_solution, final_population, fitness_history)
