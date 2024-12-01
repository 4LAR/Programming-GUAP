import random
import numpy as np
import matplotlib.pyplot as plt

def protected_div(left, right):
    if right == 0:
        return 1
    result = left / right
    return np.clip(result, -1e10, 1e10)  # Ограничение результата

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    def evaluate(self, *inputs):
        if isinstance(self.value, (int, float)):
            return self.value
        if isinstance(self.value, str) and self.value.startswith("x"):
            return inputs[int(self.value[1:]) - 1]

        left_val = self.left.evaluate(*inputs) if self.left else 0
        right_val = self.right.evaluate(*inputs) if self.right else 0

        # Проверяем значения перед применением функций
        left_val = np.clip(left_val, -1e10, 1e10)
        right_val = np.clip(right_val, -1e10, 1e10)

        if self.value == "+":
            return left_val + right_val
        elif self.value == "-":
            return left_val - right_val
        elif self.value == "*":
            return left_val * right_val
        elif self.value == "/":
            return protected_div(left_val, right_val)
        elif self.value == "sin":
            return np.sin(left_val)
        elif self.value == "cos":
            return np.cos(left_val)
        elif self.value == "exp":
            return np.clip(np.exp(left_val), -1e10, 1e10)  # Ограничение exp
        return 0

# Генерация случайного дерева
def generate_tree(variables, max_depth, current_depth=0):
    if current_depth < max_depth:
        func = random.choice(["+", "-", "*", "/", "sin", "cos", "exp"])
        return Node(func, generate_tree(variables, max_depth, current_depth + 1),
                    generate_tree(variables, max_depth, current_depth + 1))
    else:
        if random.random() < 0.5:
            return Node(random.choice(variables))
        return Node(random.uniform(-10, 10))

# Функция ошибки (MSE)
def evaluate_fitness(individual, inputs, targets):
    predictions = [individual.evaluate(*x) for x in inputs]
    return np.mean((targets - predictions) ** 2)

# Кроссинговер (обмен поддеревьями)
def crossover(parent1, parent2):
    if random.random() < 0.5:
        return parent1, parent2
    if parent1.left and parent2.left:
        parent1.left, parent2.left = parent2.left, parent1.left
    return parent1, parent2

# Мутация (замена поддерева)
def mutate(individual, variables, max_depth):
    if random.random() < 0.2:
        return generate_tree(variables, max_depth)
    if individual.left:
        individual.left = mutate(individual.left, variables, max_depth - 1)
    if individual.right:
        individual.right = mutate(individual.right, variables, max_depth - 1)
    return individual

# Эволюция
def genetic_programming():
    variables = ["x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9"]
    max_depth = 5
    population_size = 100
    generations = 40

    # Инициализация популяции
    population = [generate_tree(variables, max_depth) for _ in range(population_size)]

    # Данные
    inputs = np.random.uniform(-5.12, 5.12, (100, 9))
    targets = np.sum([i * inputs[:, i - 1] ** 2 for i in range(1, 10)], axis=0)

    fitness_progress = []
    minima_progress = []
    error_probabilities = []
    global_min = float('inf')

    for gen in range(generations):
        # Оценка
        fitnesses = [evaluate_fitness(ind, inputs, targets) for ind in population]
        best_fitness = min(fitnesses)
        average_error = np.mean(fitnesses)

        # Обновление глобального минимума
        if best_fitness < global_min:
            global_min = best_fitness

        fitness_progress.append(best_fitness)
        minima_progress.append(global_min)
        error_probabilities.append(average_error)

        print(f"Generation {gen + 1}: Best Fitness = {best_fitness:.4f}, Avg Error = {average_error:.4f}")

        # Отбор
        selected = random.choices(population, weights=[1 / f for f in fitnesses], k=population_size)

        # Кроссинговер и мутация
        next_population = []
        for i in range(0, population_size, 2):
            parent1, parent2 = selected[i], selected[i + 1]
            child1, child2 = crossover(parent1, parent2)
            next_population.extend([mutate(child1, variables, max_depth),
                                    mutate(child2, variables, max_depth)])

        population = next_population

    return fitness_progress, minima_progress, error_probabilities

# Построение графиков
def plot_progress(fitness_progress, minima_progress, error_probabilities):
    generations = range(1, len(fitness_progress) + 1)

    fig, axs = plt.subplots(1, 3, figsize=(18, 5))

    # Fitness Progress
    axs[0].plot(generations, fitness_progress, label="Best Fitness", color='blue')
    axs[0].set_title("Fitness Progress")
    axs[0].set_xlabel("Generations")
    axs[0].set_ylabel("Fitness")
    axs[0].legend()

    # Minima Progress
    axs[1].plot(generations, minima_progress, label="Global Minimum", color='orange')
    axs[1].set_title("Minima Progress")
    axs[1].set_xlabel("Generations")
    axs[1].set_ylabel("Fitness")
    axs[1].legend()

    # Error Probability Progress
    axs[2].plot(generations, error_probabilities, label="Error Probability", color='green')
    axs[2].set_title("Error Probability Progress")
    axs[2].set_xlabel("Generations")
    axs[2].set_ylabel("Average Error")
    axs[2].legend()

    plt.tight_layout()
    plt.show()

# Запуск
if __name__ == "__main__":
    fitness_progress, minima_progress, error_probabilities = genetic_programming()
    plot_progress(fitness_progress, minima_progress, error_probabilities)
