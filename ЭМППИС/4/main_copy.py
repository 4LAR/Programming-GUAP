import random
import numpy as np
import matplotlib.pyplot as plt

# Параметры алгоритма
params = {
    'generations': 100,        # Количество поколений
    'population_size': 200,    # Размер популяции
    'max_depth': 6,            # Максимальная глубина дерева
    'mutation_chance': 0.2,    # Вероятность мутации
    'n': 9                     # Размерность функции
}

# Определение функции
def target_function(x):
    return sum(i * x[i - 1] ** 2 for i in range(1, params['n'] + 1))

# Границы поиска
bounds = [(-5.12, 5.12)] * params['n']

# Класс для узлов дерева
class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    def evaluate(self, variables):
        try:
            if self.value in ['+', '-', '*', '/', 'sin', 'cos', 'exp', 'abs']:
                left_value = self.left.evaluate(variables) if self.left else 0
                right_value = self.right.evaluate(variables) if self.right else 0

                # Ограничение значений
                if self.value in ['sin', 'cos'] and (np.isnan(left_value) or np.isinf(left_value)):
                    return 0
                if self.value == 'exp' and left_value > 20:  # Ограничение экспоненты
                    return np.exp(20)

                # Операции
                if self.value == '+':
                    return left_value + right_value
                elif self.value == '-':
                    return left_value - right_value
                elif self.value == '*':
                    return left_value * right_value
                elif self.value == '/':
                    return left_value / right_value if right_value != 0 else 0
                elif self.value == 'sin':
                    return np.sin(left_value)
                elif self.value == 'cos':
                    return np.cos(left_value)
                elif self.value == 'exp':
                    return np.exp(left_value)
                elif self.value == 'abs':
                    return abs(left_value)
            elif isinstance(self.value, (int, float)):
                return self.value
            elif self.value.startswith('x'):
                idx = int(self.value[1:]) - 1
                return variables[idx]
        except Exception:
            return 0  # Возврат 0 при ошибке
        return 0

# Генерация случайного дерева
def generate_tree(max_depth, current_depth=0):
    if current_depth < max_depth:
        func = random.choice(['+', '-', '*', '/', 'sin', 'cos', 'exp', 'abs'])
        left = generate_tree(max_depth, current_depth + 1)
        right = generate_tree(max_depth, current_depth + 1)
        return Node(func, left, right)
    else:
        terminal = random.choice(['x' + str(i + 1) for i in range(params['n'])] + [random.uniform(-5.12, 5.12)])
        return Node(terminal)

# Скрещивание
def crossover(parent1, parent2):
    if random.random() < 0.5:
        return parent1
    else:
        return parent2

# Мутация
def mutate(individual, max_depth):
    if random.random() < params['mutation_chance']:
        return generate_tree(max_depth)
    return individual

# Фитнесс-функция
def fitness(individual, real_minimum):
    """Фитнесс-функция оценивает разницу между текущим значением и реальным минимумом."""
    try:
        # Генерируем случайные переменные
        variables = np.random.uniform(-5.12, 5.12, params['n'])
        value = individual.evaluate(variables)

        # Проверяем, не содержит ли дерево некорректные значения
        if value is None or np.isnan(value) or np.isinf(value):
            return 0

        # Возвращаем фитнесс (чем ближе к real_minimum, тем лучше)
        return 1 / (1 + abs(value - real_minimum))
    except Exception:
        return 0


def genetic_programming():
    """Основная функция генетического программирования."""
    # Инициализация начальной популяции
    population = [generate_tree(params['max_depth']) for _ in range(params['population_size'])]
    best_fitnesses = []
    errors = []
    found_minima = []

    # Реальный минимум целевой функции
    real_minimum = target_function([0] * params['n'])

    best_overall_individual = None
    best_overall_fitness = 0

    for generation in range(params['generations']):
        # Вычисляем фитнесс для каждой особи
        fitness_values = [fitness(ind, real_minimum) for ind in population]

        # Ищем лучшего в текущем поколении
        best_idx = np.argmax(fitness_values)
        best_individual = population[best_idx]
        best_fitness = fitness_values[best_idx]

        # Проверяем, есть ли улучшение
        if best_fitness > best_overall_fitness:
            best_overall_fitness = best_fitness
            best_overall_individual = best_individual

        # Логируем результаты
        best_value = best_individual.evaluate([0] * params['n'])
        error = abs(best_value - real_minimum)
        best_fitnesses.append(best_fitness)
        errors.append(error)
        found_minima.append(best_value)

        print(f"Generation {generation + 1}: Best Fitness = {best_fitness:.4f}, Error = {error:.4f}")

        # Создаем новое поколение
        new_population = []
        for _ in range(params['population_size'] // 2):
            # Выбираем родителей на основе фитнесса
            parent1, parent2 = random.choices(population, weights=fitness_values, k=2)

            # Создаем потомков с кроссовером и мутацией
            child1 = mutate(crossover(parent1, parent2), params['max_depth'])
            child2 = mutate(crossover(parent2, parent1), params['max_depth'])

            new_population.extend([child1, child2])

        # Обновляем популяцию
        population = new_population

    # Построение графиков
    plt.figure(figsize=(15, 5))

    plt.subplot(1, 3, 1)
    plt.plot(best_fitnesses, label='Best Fitness')
    plt.xlabel('Generation')
    plt.ylabel('Fitness')
    plt.title('Fitness Progress')
    plt.grid()
    plt.legend()

    plt.subplot(1, 3, 2)
    plt.plot(errors, label='Error', color='orange')
    plt.xlabel('Generation')
    plt.ylabel('Error')
    plt.title('Error Progress')
    plt.grid()
    plt.legend()

    plt.subplot(1, 3, 3)
    plt.plot(found_minima, label='Found Minima', color='green')
    plt.axhline(real_minimum, color='red', linestyle='--', label='Real Minimum')
    plt.xlabel('Generation')
    plt.ylabel('Value')
    plt.title('Minima Progress')
    plt.grid()
    plt.legend()

    plt.tight_layout()
    plt.show()

# Запуск алгоритма
genetic_programming()
