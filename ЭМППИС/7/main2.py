import numpy as np
import matplotlib.pyplot as plt
import time

# Параметры PSO
population_size = 500          # Количество частиц
max_iterations = 100           # Максимальное количество итераций
w = 0.5                         # Коэффициент инерции
c1 = 1.5                        # Коэффициент когнитивной компоненты (личный опыт)
c2 = 1.5                        # Коэффициент социальной компоненты (опыт группы)
x_min, x_max = 0, 2 * np.pi     # Диапазон для переменных

# Функция Эасома для n-мерного случая
def fEaso(x):
    return -np.prod(np.cos(x)) * np.exp(-np.sum((x - np.pi) ** 2))

# Добавление функции для улучшения инициализации частиц
def initialize_particles(n):
    return np.random.uniform(x_min, x_max, (population_size, n))

def run_pso(n, visualize=False):
    # Инициализация частиц и их скоростей
    particles = initialize_particles(n)
    velocities = np.random.uniform(-1, 1, (population_size, n))

    # Инициализация лучших позиций
    personal_best_positions = np.copy(particles)
    personal_best_scores = np.array([fEaso(p) for p in particles])
    global_best_position = particles[np.argmin(personal_best_scores)]
    global_best_score = np.min(personal_best_scores)

    start_time = time.time()

    # Подготовка графика для n=2
    if visualize and n == 2:
        x1 = np.linspace(x_min, x_max, 200)
        x2 = np.linspace(x_min, x_max, 200)
        X1, X2 = np.meshgrid(x1, x2)
        Z = np.array([[fEaso(np.array([x1, x2])) for x1, x2 in zip(row_x1, row_x2)]
                      for row_x1, row_x2 in zip(X1, X2)])

        fig = plt.figure(figsize=(12, 8))
        ax = fig.add_subplot(111, projection='3d')
        surf = ax.plot_surface(X1, X2, Z, cmap='viridis', alpha=0.8, edgecolor='none')
        ax.set_title("Оптимизация функции Эасома с помощью PSO", fontsize=16)
        ax.set_xlabel("x1", fontsize=14)
        ax.set_ylabel("x2", fontsize=14)
        ax.set_zlabel("f(x)", fontsize=14)
        ax.view_init(30, 240)

        # Создание объекта scatter для частиц
        particle_plot = ax.scatter(particles[:, 0], particles[:, 1],
                                   [fEaso(p) for p in particles],
                                   color='blue', alpha=0.6, s=10)

    # Основной цикл PSO
    for iteration in range(max_iterations):
        for i in range(population_size):
            cognitive_component = c1 * np.random.rand() * (personal_best_positions[i] - particles[i])
            social_component = c2 * np.random.rand() * (global_best_position - particles[i])
            velocities[i] = w * velocities[i] + cognitive_component + social_component
            particles[i] += velocities[i]
            particles[i] = np.clip(particles[i], x_min, x_max)

            fitness = fEaso(particles[i])
            if fitness < personal_best_scores[i]:
                personal_best_scores[i] = fitness
                personal_best_positions[i] = particles[i]

        current_best_index = np.argmin(personal_best_scores)
        if personal_best_scores[current_best_index] < global_best_score:
            global_best_score = personal_best_scores[current_best_index]
            global_best_position = personal_best_positions[current_best_index]

        # Обновление графика для n=2
        if visualize and n == 2:
            particle_plot._offsets3d = (particles[:, 0], particles[:, 1],
                                        [fEaso(p) for p in particles])
            ax.set_title(f"Оптимизация функции Эасома (Итерация {iteration})", fontsize=16)
            plt.pause(0.01)

    execution_time = time.time() - start_time

    if visualize and n == 2:
        # Отображение найденного минимума
        ax.scatter(global_best_position[0], global_best_position[1], global_best_score,
                   color='red', s=100, label='Найденный минимум')
        ax.legend()
        plt.show()

    print(f"Для n = {n}:")
    print(f"Лучшее найденное решение: {global_best_position}")
    print(f"Значение функции в этой точке: {global_best_score:.6f}")
    print(f"Время выполнения: {execution_time:.4f} секунд\n")
    return global_best_position, global_best_score, execution_time

# Запуск для различных значений n
results = {}
for n in [2, 4, 6, 10]:
    visualize = (n == 2)  # Визуализация только для n=2
    results[n] = run_pso(n, visualize=visualize)
