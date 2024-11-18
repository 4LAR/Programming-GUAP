import random
import time
import matplotlib.pyplot as plt
from matplotlib import animation
import numpy as np

# Константы генетического алгоритма
POPULATION_SIZE = 50  # количество индивидуумов в популяции
MAX_GENERATIONS = 50  # максимальное количество поколений
P_CROSSOVER = 0.9  # вероятность скрещивания
P_MUTATION = 0.1  # вероятность мутации
N_VECTOR = 2  # размерность задачи (количество генов в хромосоме)
LIMIT_VALUE_TOP = 5.12  # верхняя граница области поиска
LIMIT_VALUE_DOWN = -5.12  # нижняя граница области поиска
RANDOM_SEED = 42  # для воспроизводимости
random.seed(RANDOM_SEED)

class Individual(list):
    """Класс для представления индивидуумов популяции"""
    def __init__(self, *args):
        super().__init__(*args)
        # print(args)
        self.value = 0

# Функция приспособленности (De Jong's function 1)
def fitness_function(f):
    return sum(x**2 for x in f)

# Создание индивидуумов и популяции
def individual_creator():
    return Individual([random.uniform(LIMIT_VALUE_DOWN, LIMIT_VALUE_TOP) for _ in range(N_VECTOR)])

def population_creator(n=0):
    return [individual_creator() for _ in range(n)]

# Начальная популяция
population = population_creator(POPULATION_SIZE)
fitness_values = list(map(fitness_function, population))
for individual, fitness_value in zip(population, fitness_values):
    individual.value = fitness_value

# Для статистики
min_fitness_values = []
mean_fitness_values = []

# Сортировка начальной популяции по значению приспособленности
population.sort(key=lambda ind: ind.value)

def clone(individual):
    """Клонирование индивидуума"""
    clone_ind = Individual(individual[:])
    clone_ind.value = individual.value
    return clone_ind

def selection(population, n=POPULATION_SIZE):
    """Турнирная селекция"""
    offspring = []
    for _ in range(n):
        participants = random.sample(population, 4)
        winner = min(participants, key=lambda ind: ind.value)
        offspring.append(winner)
    return offspring

def crossover(parent1, parent2):
    """Одноточечное скрещивание"""
    point = random.randint(1, len(parent1) - 1)
    parent1[point:], parent2[point:] = parent2[point:], parent1[point:]

def mutate(individual, mutation_prob=1.0 / N_VECTOR):
    """Мутация гена"""
    for i in range(len(individual)):
        if random.random() < mutation_prob:
            individual[i] += random.uniform(-0.5, 0.5)
            individual[i] = max(min(individual[i], LIMIT_VALUE_TOP), LIMIT_VALUE_DOWN)

# Анимация процесса оптимизации
generation_counter = 0

def animate(frame):
    global generation_counter, population

    ax.clear()
    ax.plot_wireframe(X, Y, Z, rstride=10, cstride=10, alpha=0.3)
    ax.set_title(f"Поколение: {generation_counter}", fontsize=10)
    ax.set_xlabel("X")
    ax.set_ylabel("Y")
    ax.set_zlabel("Fitness")

    # Отображение текущих индивидов популяции
    for ind in population:
        ax.scatter(ind[0], ind[1], ind.value, color='red', s=20)

    # Вывод значений x и y для каждого индивидуума
    if generation_counter % 5 == 0:  # Выводить каждые 5 поколений
        print(f"Поколение {generation_counter}:")
        for ind in population:
            # print(ind)
            # print(f"  Индивидуум: x={ind[0]:.6f}, y={ind[1]:.6f}, Fitness={ind.value:.2f}")
            print(f"  Индивидуум: x={ind[0]:.6f}, y={ind[1]:.6f}, z={ind.value:.6f}")

    # Селекция, кроссовер и мутация
    offspring = selection(population)
    offspring = list(map(clone, offspring))

    for child1, child2 in zip(offspring[::2], offspring[1::2]):
        if random.random() < P_CROSSOVER:
            crossover(child1, child2)

    for mutant in offspring:
        if random.random() < P_MUTATION:
            mutate(mutant)

    # Вычисление новой функции приспособленности
    fresh_fitness_values = list(map(fitness_function, offspring))
    for ind, fitness_value in zip(offspring, fresh_fitness_values):
        ind.value = fitness_value

    # Обновление популяции
    population[:] = offspring

    # Сбор статистики
    fitness_values = [ind.value for ind in population]
    std_fitness = np.std(fitness_values)
    min_fitness = min(fitness_values)
    mean_fitness = sum(fitness_values) / len(fitness_values)
    min_fitness_values.append(min_fitness)
    mean_fitness_values.append(mean_fitness)

    if generation_counter % 5 == 0:
        print(f"Минимальная приспособле нность: {min_fitness:.6f}\nСредняя приспособленность: {mean_fitness:.6f}\nСтандартное отклонение: {std_fitness:.6f}")

    generation_counter += 1

# Создание сетки для визуализации функции
X = np.linspace(LIMIT_VALUE_DOWN, LIMIT_VALUE_TOP, 100)
Y = np.linspace(LIMIT_VALUE_DOWN, LIMIT_VALUE_TOP, 100)
X, Y = np.meshgrid(X, Y)
Z = X**2 + Y**2

# Настройка графиков
fig = plt.figure(figsize=(12, 6))
ax = fig.add_subplot(1, 1, 1, projection='3d')

ani = animation.FuncAnimation(fig, animate, frames=MAX_GENERATIONS, interval=50, repeat=False)
plt.show()
