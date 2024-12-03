import numpy as np
import random
import matplotlib.pyplot as plt

# Функция для вычисления значения дерева
def evaluate(tree, x):
    if isinstance(tree, (int, float)):  # Если это число, вернуть его
        return tree
    if tree == "x":  # Если переменная x, вернуть её значение
        return x
    op, left, right = tree  # Оператор и поддеревья
    left_val = evaluate(left, x)  # Рекурсивная оценка левого поддерева
    right_val = evaluate(right, x)  # Рекурсивная оценка правого поддерева
    try:
        # Выполнение операции
        if op == "+":
            return left_val + right_val
        elif op == "-":
            return left_val - right_val
        elif op == "*":
            return left_val * right_val
        elif op == "/":
            return left_val / right_val if right_val != 0 else 1  # Защита от деления на ноль
    except:
        return 1  # Обработка исключений


# Инициализация начальной популяции
def initialize_population(population_size, max_depth=5):
    def random_tree(depth):
        if depth == 0:
            return random.choice(["x", random.uniform(-10, 10)])
        op = random.choice(["+", "-", "*", "/"])
        return [op, random_tree(depth - 1), random_tree(depth - 1)]

    return [random_tree(max_depth) for _ in range(population_size)]


# Оценка приспособленности (RMS)
def fitness(individual, data):
    def evaluate(tree, x):
        if isinstance(tree, (int, float)):
            return tree
        if tree == "x":
            return x
        op, left, right = tree
        left_val = evaluate(left, x)
        right_val = evaluate(right, x)
        try:
            if op == "+":
                return left_val + right_val
            elif op == "-":
                return left_val - right_val
            elif op == "*":
                return left_val * right_val
            elif op == "/":
                return left_val / right_val if right_val != 0 else 1
        except:
            return 1  # Избежание ошибок деления

    predictions = np.array([evaluate(individual, x) for x in data["x"]])
    return -np.sqrt(np.mean((predictions - data["y"]) ** 2))  # RMS с отрицательным знаком для максимизации


# Операция кроссовера (усекающий/растущий)
def crossover(parent1, parent2, depth=5):
    if depth == 0 or isinstance(parent1, (int, float, str)) or isinstance(parent2, (int, float, str)):
        return random.choice([parent1, parent2])
    if random.random() < 0.5:
        return parent1
    return [parent1[0], crossover(parent1[1], parent2[1], depth - 1), crossover(parent1[2], parent2[2], depth - 1)]


# Операция мутации (поддерево)
def mutate(tree, depth=5):
    if depth == 0 or isinstance(tree, (int, float, str)):
        return random.choice(["x", random.uniform(-10, 10)])
    if random.random() < 0.3:
        return random.choice(["x", random.uniform(-10, 10)])
    return [tree[0], mutate(tree[1], depth - 1), mutate(tree[2], depth - 1)]


# Ранговая селекция
def rank_selection(population, fitness_values):
    sorted_indices = np.argsort(fitness_values)[::-1]
    probabilities = np.linspace(1, 0, len(population))
    probabilities /= probabilities.sum()
    return population[np.random.choice(sorted_indices, p=probabilities)]


# Генетическое программирование
def genetic_algorithm(train_data, test_data, population_size=50, generations=50):
    population = initialize_population(population_size)
    best_errors = []
    train_predictions = None
    test_predictions = None

    for gen in range(generations):
        fitness_values = np.array([fitness(ind, train_data) for ind in population])
        best_fitness_index = np.argmax(fitness_values)
        best_individual = population[best_fitness_index]

        if gen == generations - 1:
            train_predictions = np.array([evaluate(best_individual, x) for x in train_data["x"]])

        best_errors.append(-fitness_values[best_fitness_index])

        # Новая популяция
        new_population = [best_individual]  # Элитарность
        while len(new_population) < population_size:
            parent1 = rank_selection(population, fitness_values)
            parent2 = rank_selection(population, fitness_values)
            child = crossover(parent1, parent2)
            child = mutate(child)
            new_population.append(child)
        population = new_population

        print(f"ERROR: {best_errors[-1]}")

    # Тестовое множество
    test_fitness_values = np.array([fitness(ind, test_data) for ind in population])
    best_test_index = np.argmax(test_fitness_values)
    best_test_individual = population[best_test_index]
    test_predictions = np.array([evaluate(best_test_individual, x) for x in test_data["x"]])

    # Построение графиков
    plot_results(train_data, test_data, train_predictions, test_predictions, best_errors, generations)


# Визуализация результатов
def plot_results(train_data, test_data, train_predictions, test_predictions, best_errors, generations):
    fig, axs = plt.subplots(1, 3, figsize=(21, 5))

    # Обучающее множество
    axs[0].plot(train_data["x"], train_data["y"], label="Истинное значение (Обучение)", marker='o')
    axs[0].plot(train_data["x"], train_predictions, label="Предсказание (Обучение)", linestyle="--")
    axs[0].set_title("Обучающее множество")
    axs[0].legend()

    # Тестовое множество
    axs[1].plot(test_data["x"], test_data["y"], label="Истинное значение (Тест)", marker='o')
    axs[1].plot(test_data["x"], test_predictions, label="Предсказание (Тест)", linestyle="--")
    axs[1].set_title("Тестовое множество")
    axs[1].legend()

    # График ошибки
    axs[2].plot(range(1, generations + 1), best_errors, label="Ошибка (RMS)")
    axs[2].set_title("Динамика ошибки")
    axs[2].legend()

    plt.tight_layout()
    plt.show()


# Пример данных
train_data = {"x": np.linspace(0, 10, 20), "y": np.sin(np.linspace(0, 10, 20))}
test_data = {"x": np.linspace(0, 10, 10), "y": np.sin(np.linspace(0, 10, 10))}

# Запуск алгоритма
genetic_algorithm(train_data, test_data)
