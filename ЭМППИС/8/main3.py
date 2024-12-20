import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import random

data = pd.read_csv('data.csv')

# Параметры алгоритма
# population_size = 300
# generations = 50
# mutation_rate = 0.3
# train_percentage = 0.5
population_size = 100
generations = 30
mutation_rate = 0.1
train_percentage = 0.8

# Разделение данных на обучающее и тестовое множество на основе train_percentage
train_size = int(len(data) * train_percentage)
# train_size = 13
train_data = data.iloc[:train_size]
test_data = data.iloc[train_size:]

# Генерация случайного дерева
def generate_tree(depth=3):
    if depth == 0 or (depth > 1 and random.random() > 0.7):
        return random.choice(["L", "Me", random.uniform(1, 100)])
    operation = random.choice(["+", "-", "*", "/"])
    return [operation, generate_tree(depth - 1), generate_tree(depth - 1)]

# Оценка дерева
def evaluate_tree(tree, data_row):
    if isinstance(tree, (int, float)):
        return tree
    if isinstance(tree, str):
        return data_row[tree]
    operation, left, right = tree
    left_val = evaluate_tree(left, data_row)
    right_val = evaluate_tree(right, data_row)
    try:
        if operation == "+":
            return left_val + right_val
        elif operation == "-":
            return left_val - right_val
        elif operation == "*":
            return left_val * right_val
        elif operation == "/":
            return left_val / right_val if right_val != 0 else 1
    except:
        return 1

# RMS ошибка
# def fitness(tree, data_subset):
#     predictions = data_subset.apply(lambda row: evaluate_tree(tree, row), axis=1)
#     error = np.sqrt(np.mean((predictions - data_subset["Ef"]) ** 2))
#     return -error
def fitness(tree, data_subset):
    predictions = data_subset.apply(lambda row: evaluate_tree(tree, row), axis=1)
    error = np.sqrt(np.mean((predictions - data_subset["Ef"]) ** 2))
    complexity_penalty = count_tree_nodes(tree) * 0.01  # Штраф за сложность
    return -(error + complexity_penalty)

def count_tree_nodes(tree):
    if isinstance(tree, (int, float, str)):
        return 1
    return 1 + count_tree_nodes(tree[1]) + count_tree_nodes(tree[2])

# Кроссовер
def crossover(tree1, tree2):
    if isinstance(tree1, (int, float, str)) or isinstance(tree2, (int, float, str)):
        return tree1 if random.random() < 0.5 else tree2
    if not isinstance(tree1, list) or not isinstance(tree2, list):
        return tree1 if random.random() < 0.5 else tree2
    return [tree1[0] if random.random() < 0.5 else tree2[0],
            crossover(tree1[1], tree2[1]),
            crossover(tree1[2], tree2[2])]

# Мутация
def mutate(tree, depth=3):
    if isinstance(tree, (int, float, str)) or depth == 0:
        return generate_tree(depth) if random.random() < mutation_rate else tree
    if random.random() < mutation_rate:
        return generate_tree(depth)
    return [tree[0], mutate(tree[1], depth - 1), mutate(tree[2], depth - 1)]

# Ранговая селекция
def rank_selection(population, fitness_values):
    sorted_population = [x for _, x in sorted(zip(fitness_values, population), key=lambda pair: pair[0])]
    return random.choices(sorted_population[-10:], k=1)[0]
# Генетический алгоритм
def genetic_algorithm(train_data, test_data):
    population = [generate_tree() for _ in range(population_size)]
    best_tree = None
    best_fitness = -np.inf
    fitness_history_train = []
    fitness_history_test = []

    for gen in range(generations):
        # Оценка на обучающем множестве
        fitness_values = [fitness(tree, train_data) for tree in population]

        # Обновление лучшего решения
        if max(fitness_values) > best_fitness:
            best_fitness = max(fitness_values)
            best_tree = population[np.argmax(fitness_values)]

        # Сохранение ошибки для обучающего и тестового множеств
        fitness_history_train.append(-best_fitness)
        test_rms_error = -fitness(best_tree, test_data)
        fitness_history_test.append(test_rms_error)

        print(f"Поколение {gen + 1}: Ошибка на обучении = {-best_fitness:.4f}, Ошибка на тесте = {test_rms_error:.4f}")

        # Формирование нового поколения
        new_population = []
        while len(new_population) < population_size:
            parent1 = rank_selection(population, fitness_values)
            parent2 = rank_selection(population, fitness_values)
            child = crossover(parent1, parent2)
            child = mutate(child)
            new_population.append(child)

        population = new_population

    # График обучения
    # plt.plot(range(1, generations + 1), fitness_history, label="RMS Error")
    # plt.xlabel("Поколение")
    # plt.ylabel("Ошибка RMS")
    # plt.title("Обучение генетического алгоритма")
    # plt.legend()

    plt.figure(figsize=(10, 6))
    plt.plot(range(1, generations + 1), fitness_history_train, label="Ошибка на обучении (RMS)", color='b')
    plt.plot(range(1, generations + 1), fitness_history_test, label="Ошибка на тесте (RMS)", color='r')
    plt.xlabel("Поколение")
    plt.ylabel("Ошибка RMS")
    plt.title("Динамика ошибок на обучающем и тестовом множестве")
    plt.legend()
    plt.grid()

    # Тестирование на тестовом множестве
    test_error = -fitness(best_tree, test_data)
    print(f"\nТестовая ошибка RMS: {test_error:.4f}")
    print(f"Лучшее дерево: {best_tree}")

    plt.show()

# Запуск алгоритма
genetic_algorithm(train_data, test_data)
