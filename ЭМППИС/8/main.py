import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import random

import matplotlib.pyplot as plt

# Загрузка данных
data = pd.DataFrame({
    "Номер проекта": [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18],
    "L": [90.2, 46.2, 46.5, 54.5, 31.1, 67.5, 12.8, 10.5, 21.5, 3.1, 4.2, 7.8, 2.1, 5.0, 78.6, 9.7, 12.5, 100.8],
    "Me": [30.0, 20.0, 19.0, 20.0, 35.0, 29.0, 26.0, 34.0, 31.0, 26.0, 19.0, 31.0, 28.0, 29.0, 35.0, 27.0, 27.0, 34.0],
    "Ef": [115.8, 96.0, 79.0, 909.8, 39.6, 98.4, 18.9, 10.3, 28.5, 7.0, 9.0, 7.3, 5.0, 8.4, 98.7, 15.6, 23.9, 138.3]
})

# Разделение данных на обучающее и тестовое множества
train_data = data.iloc[:13]
test_data = data.iloc[13:]

# Параметры алгоритма
population_size = 300
generations = 50
mutation_rate = 0.3

# Генерация случайного дерева
def generate_tree(depth=3):
    if depth == 0 or (depth > 1 and random.random() > 0.7):
        return random.choice(["L", "Me", random.uniform(1, 100)])
    operation = random.choice(["+", "-", "*", "/"])
    return [operation, generate_tree(depth - 1), generate_tree(depth - 1)]

# Оценка приспособленности дерева
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

# Вычисление RMS ошибки
def fitness(tree, data_subset):
    predictions = data_subset.apply(lambda row: evaluate_tree(tree, row), axis=1)
    error = np.sqrt(np.mean((predictions - data_subset["Ef"]) ** 2))
    return -error

# Кроссовер
def crossover(tree1, tree2):
    # Если оба дерева являются терминальными узлами, выбираем случайное
    if isinstance(tree1, (int, float, str)) or isinstance(tree2, (int, float, str)):
        return tree1 if random.random() < 0.5 else tree2

    # Проверка на случай, если дерево1 или дерево2 не является списком
    if not isinstance(tree1, list) or not isinstance(tree2, list):
        return tree1 if random.random() < 0.5 else tree2

    # Рекурсивно выполняем кроссовер для дочерних узлов
    return [
        tree1[0] if random.random() < 0.5 else tree2[0],  # Оператор
        crossover(tree1[1], tree2[1]),                   # Левое поддерево
        crossover(tree1[2], tree2[2])                    # Правое поддерево
    ]


# Мутация (усечение или рост)
def mutate(tree, depth=3):
    if isinstance(tree, (int, float, str)) or depth == 0:  # Проверяем терминальные узлы
        if random.random() < mutation_rate:
            return generate_tree(depth)  # Генерируем новое поддерево
        return tree  # Без изменений

    if random.random() < mutation_rate:
        return generate_tree(depth)  # Полная замена узла

    # Рекурсивно применяем мутацию к дочерним узлам
    return [tree[0], mutate(tree[1], depth - 1), mutate(tree[2], depth - 1)]

# Ранговая селекция
def rank_selection(population, fitness_values):
    sorted_population = [x for _, x in sorted(zip(fitness_values, population), key=lambda pair: pair[0])]
    return random.choices(sorted_population[-10:], k=1)[0]

# Основной алгоритм
def genetic_algorithm(train_data, test_data):
    population = [generate_tree() for _ in range(population_size)]
    best_tree = None
    best_fitness = -np.inf

    for gen in range(generations):
        fitness_values = [fitness(tree, train_data) for tree in population]

        if max(fitness_values) > best_fitness:
            best_fitness = max(fitness_values)
            best_tree = population[np.argmax(fitness_values)]

        print(f"Поколение {gen + 1}: Лучшее значение приспособленности = {-best_fitness:.4f}")

        new_population = []
        while len(new_population) < population_size:
            parent1 = rank_selection(population, fitness_values)
            parent2 = rank_selection(population, fitness_values)
            child = crossover(parent1, parent2)
            child = mutate(child)
            new_population.append(child)

        population = new_population

    print(f"\nЛучшее дерево: {best_tree}")
    print(f"Наилучшая ошибка RMS: {-best_fitness:.4f}")

# Запуск алгоритма
genetic_algorithm(train_data, test_data)
