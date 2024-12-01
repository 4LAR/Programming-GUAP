import numpy as np
import operator
import random
from deap import base, creator, gp, tools, algorithms
import matplotlib.pyplot as plt

# Определяем терминальное и функциональное множество
def protected_div(left, right):
    try:
        return left / right
    except ZeroDivisionError:
        return 1

pset = gp.PrimitiveSet("MAIN", 9)  # 9 переменных x1, x2, ..., x9
pset.addPrimitive(operator.add, 2)
pset.addPrimitive(operator.sub, 2)
pset.addPrimitive(operator.mul, 2)
pset.addPrimitive(protected_div, 2)
pset.addPrimitive(np.sin, 1)
pset.addPrimitive(np.cos, 1)
pset.addPrimitive(np.exp, 1)
pset.addTerminal(1)
pset.addTerminal(2)

# Определяем минимизацию
creator.create("FitnessMin", base.Fitness, weights=(-1.0,))
creator.create("Individual", gp.PrimitiveTree, fitness=creator.FitnessMin)

toolbox = base.Toolbox()
toolbox.register("expr", gp.genHalfAndHalf, pset=pset, min_=1, max_=3)
toolbox.register("individual", tools.initIterate, creator.Individual, toolbox.expr)
toolbox.register("population", tools.initRepeat, list, toolbox.individual)

toolbox.register("compile", gp.compile, pset=pset)

# Целевая функция
def eval_func(individual):
    func = toolbox.compile(expr=individual)
    inputs = np.random.uniform(-5.12, 5.12, (100, 9))  # 100 случайных точек
    target = np.sum([i * inputs[:, i - 1] ** 2 for i in range(1, 10)], axis=0)
    predictions = np.array([func(*x) for x in inputs])
    return np.mean((target - predictions) ** 2),  # Ошибка MSE

toolbox.register("evaluate", eval_func)
toolbox.register("select", tools.selTournament, tournsize=3)
toolbox.register("mate", gp.cxOnePoint)
toolbox.register("mutate", gp.mutUniform, expr=toolbox.expr, pset=pset)

toolbox.decorate("mate", gp.staticLimit(key=operator.attrgetter("height"), max_value=17))
toolbox.decorate("mutate", gp.staticLimit(key=operator.attrgetter("height"), max_value=17))

# Эволюционный процесс
def main():
    random.seed(42)
    pop = toolbox.population(n=300)
    hof = tools.HallOfFame(1)
    stats = tools.Statistics(lambda ind: ind.fitness.values)
    stats.register("avg", np.mean)
    stats.register("min", np.min)

    # Сбор данных для графиков
    fitness_progress = []
    minima_progress = []
    error_probabilities = []

    # Эволюция
    generations = 40
    for gen in range(generations):
        offspring = algorithms.varAnd(pop, toolbox, cxpb=0.5, mutpb=0.2)
        fits = toolbox.map(toolbox.evaluate, offspring)

        # Обновление фитнеса
        for fit, ind in zip(fits, offspring):
            ind.fitness.values = fit

        # Сохранение данных
        pop = toolbox.select(offspring, k=len(pop))
        fitness_values = [ind.fitness.values[0] for ind in pop]
        fitness_progress.append(min(fitness_values))
        minima_progress.append(hof[0].fitness.values[0] if len(hof) > 0 else float('inf'))
        error_probabilities.append(np.mean(fitness_values))

        hof.update(pop)

    return fitness_progress, minima_progress, error_probabilities

# Построение графиков
def plot_progress(fitness_progress, minima_progress, error_probabilities):
    generations = range(1, len(fitness_progress) + 1)
    real_minimum = 30  # Настоящий минимум, если известен

    fig, axs = plt.subplots(1, 3, figsize=(15, 5))

    # График прогресса фитнеса
    axs[0].plot(generations, fitness_progress, label="Best Fitness")
    axs[0].set_title("Fitness Progress")
    axs[0].set_xlabel("Generations")
    axs[0].set_ylabel("Best Fitness")
    axs[0].legend()

    # График найденных минимумов
    axs[1].plot(generations, minima_progress, label="Found Minima", color='orange')
    axs[1].axhline(real_minimum, color='red', linestyle='--', label="Real Minimum")
    axs[1].set_title("Minima Progress")
    axs[1].set_xlabel("Generations")
    axs[1].set_ylabel("Function Value")
    axs[1].legend()

    # График вероятности ошибки
    axs[2].plot(generations, error_probabilities, label="Error Probability", color='green')
    axs[2].set_title("Error Probability Progress")
    axs[2].set_xlabel("Generations")
    axs[2].set_ylabel("Error Probability")
    axs[2].legend()

    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    fitness_progress, minima_progress, error_probabilities = main()
    plot_progress(fitness_progress, minima_progress, error_probabilities)
