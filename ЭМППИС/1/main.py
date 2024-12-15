import numpy as np
import matplotlib.pyplot as plt

# Определяем функцию
def f(x):
    return np.cos(np.exp(x)) * np.sin(np.log(x))

# Параметры генетического алгоритма
population_size = 100
generations = 50
mutation_rate = 0.2
mutation_chance = 0.9
x_bounds = [2, 4]

# Инициализация популяции
population = np.random.uniform(x_bounds[0], x_bounds[1], population_size)

# История для визуализации
fitness_history = []
population_history = []

# Основной цикл генетического алгоритма
for generation in range(generations):
    fitness = f(population)
    fitness_history.append(fitness)
    population_history.append(population)

    # Селекция: выбираем лучших индивидов
    selected_indices = np.argsort(fitness)[-population_size // 2:]
    selected_population = population[selected_indices]

    # Кроссовер
    offspring = []
    for i in range(len(selected_population) // 2):
        parent1 = selected_population[2 * i]
        parent2 = selected_population[2 * i + 1]
        crossover_point = np.random.rand()
        child = crossover_point * parent1 + (1 - crossover_point) * parent2
        offspring.append(child)

    offspring = np.array(offspring)

    # Мутация
    if np.random.uniform(0, 1) <= mutation_chance:
        mutation = np.random.uniform(-0.1, 0.1, offspring.shape) * mutation_rate
        offspring += mutation
        offspring = np.clip(offspring, x_bounds[0], x_bounds[1])  # Ограничение в пределах диапазона

    # Новая популяция
    population = np.concatenate((selected_population, offspring))

# Функция для визуализации конкретного поколения
def plot_generation(generation):
    print(f"Поколение {generation + 1}:")
    print("Приспособленность:", fitness_history[generation])
    print("Популяция:", population_history[generation])
    plt.figure(figsize=(10, 6))
    plt.plot(population_history[generation], fitness_history[generation], 'o', label=f'Поколение {generation + 1}', alpha=0.7)
    # Построение графика исходной функции
    x_values = np.linspace(x_bounds[0], x_bounds[1], 400)
    plt.plot(x_values, f(x_values), label='Исходная функция', color='red', linewidth=2)

    plt.title(f'Приспособленность индивидов в поколении {generation + 1}')
    plt.xlabel('Индивид (x)')
    plt.ylabel('Приспособленность f(x)')
    plt.legend(loc='upper right', fontsize='small')
    plt.grid()
    plt.show()

# Взаимодействие с пользователем
while True:
    user_input = input("Введите номер поколения (1-50) или 'all' для отображения всех поколений ('q' для выхода): ")

    if user_input.lower() == 'q':
        break
    if user_input.lower() == 'all':
        # Визуализация всех поколений на одном графике
        plt.figure(figsize=(12, 8))
        for i in range(generations):
            plt.plot(population_history[i], fitness_history[i], 'o', label=f'Поколение {i + 1}', alpha=0.5)

        # Построение графика исходной функции
        x_values = np.linspace(x_bounds[0], x_bounds[1], 400)
        plt.plot(x_values, f(x_values), label='Исходная функция', color='red', linewidth=2)

        plt.title(f'Приспособленность индивидов на протяжении {generations} поколений')
        plt.xlabel('Индивид (x)')
        plt.ylabel('Приспособленность f(x)')
        plt.legend(loc='upper right', fontsize='small')
        plt.grid()
        plt.show()
    else:
        try:
            generation_number = int(user_input) - 1  # Преобразуем в индекс (0-49)
            if 0 <= generation_number < generations:
                plot_generation(generation_number)
            else:
                print(f"Пожалуйста, введите номер поколения от 1 до {generations}.")
        except ValueError:
            print("Некорректный ввод. Пожалуйста, введите номер поколения или 'all'.")
