import numpy as np
import matplotlib.pyplot as plt
from scipy.spatial.distance import cdist

# --- Настройки алгоритма ---
COORDINATES = [
    (20833.3333, 17100.0000), (20900.0000, 17066.6667), (21300.0000, 13016.6667),
    (21600.0000, 14150.0000), (21600.0000, 14966.6667), (21600.0000, 16500.0000),
    (22183.3333, 13133.3333), (22583.3333, 14300.0000), (22683.3333, 12716.6667),
    (23616.6667, 15866.6667), (23700.0000, 15933.3333), (23883.3333, 14533.3333),
    (24166.6667, 13250.0000), (25149.1667, 12365.8333), (26133.3333, 14500.0000),
    (26150.0000, 10550.0000), (26283.3333, 12766.6667), (26433.3333, 13433.3333),
    (26550.0000, 13850.0000), (26733.3333, 11683.3333), (27026.1111, 13051.9444),
    (27096.1111, 13415.8333), (27153.6111, 13203.3333), (27166.6667, 9833.3333),
    (27233.3333, 10450.0000), (27233.3333, 11783.3333), (27266.6667, 10383.3333),
    (27433.3333, 12400.0000), (27462.5000, 12992.2222)
]
OPTIMAL_ROUTE = [0, 1, 5, 6, 10, 15, 20, 25, 28, 22, 18, 11, 3, 8, 13, 16, 21, 24, 27, 23, 19, 14, 9, 2, 4, 7, 12, 17, 26]
N_ANTS = 20
N_ITERATIONS = 100
ALPHA = 1
BETA = 5
EVAPORATION_RATE = 0.1
PHEROMONE_CONSTANT = 100

# --- Шаг 1: Вычисление матрицы расстояний ---
def calculate_distance_matrix(coords):
    return cdist(coords, coords, metric='euclidean')

distance_matrix = calculate_distance_matrix(COORDINATES)

# --- Шаг 2: Реализация муравьиного алгоритма ---
def ant_colony_optimization(coords, dist_matrix, n_ants, n_iterations, alpha, beta, evaporation_rate, pheromone_constant):
    n_cities = len(dist_matrix)
    pheromone = np.ones((n_cities, n_cities))  # начальные феромоны
    best_route = None
    best_distance = float('inf')
    all_best_routes = []

    for iteration in range(n_iterations):
        routes = []
        route_lengths = []

        for ant in range(n_ants):
            visited = np.zeros(n_cities, dtype=bool)
            current_city = np.random.randint(0, n_cities)
            route = [current_city]
            visited[current_city] = True
            total_distance = 0

            while len(route) < n_cities:
                probabilities = calculate_transition_probabilities(current_city, visited, pheromone, dist_matrix, alpha, beta)
                next_city = np.random.choice(range(n_cities), p=probabilities)
                route.append(next_city)
                total_distance += dist_matrix[current_city, next_city]
                current_city = next_city
                visited[current_city] = True

            # Замкнуть маршрут
            total_distance += dist_matrix[route[-1], route[0]]
            route_lengths.append(total_distance)
            routes.append(route)

        # Обновление феромонов
        pheromone *= (1 - evaporation_rate)
        for i, route in enumerate(routes):
            for j in range(len(route) - 1):
                pheromone[route[j], route[j+1]] += pheromone_constant / route_lengths[i]

        # Поиск лучшего маршрута
        min_length = min(route_lengths)
        if min_length < best_distance:
            best_distance = min_length
            best_route = routes[route_lengths.index(min_length)]

        # Сохранение лучшего маршрута текущего поколения
        all_best_routes.append((best_route, best_distance))

    return best_route, best_distance, all_best_routes

# --- Шаг 3: Вычисление вероятностей перехода ---
def calculate_transition_probabilities(current_city, visited, pheromone, dist_matrix, alpha, beta):
    probabilities = []
    for j in range(len(visited)):
        if visited[j]:
            probabilities.append(0)
        else:
            pheromone_level = pheromone[current_city, j] ** alpha
            visibility = (1 / dist_matrix[current_city, j]) ** beta
            probabilities.append(pheromone_level * visibility)
    probabilities = probabilities / np.sum(probabilities)
    return probabilities

# --- Шаг 4: Визуализация ---
def visualize_routes(coords, all_best_routes, final_best_route, optimal_route):
    fig, axes = plt.subplots(1, 2, figsize=(12, 6))
    # fig, axes = plt.subplots(1, 3, figsize=(18, 6))

    # График 1: Лучшие маршруты по поколениям
    for i, (route, distance) in enumerate(all_best_routes):
        route_coords = np.array([coords[city] for city in route + [route[0]]])
        axes[0].plot(route_coords[:, 0], route_coords[:, 1], marker='o', linestyle='-', label=f"Gen {i+1}" if i < 5 else "")
    axes[0].set_title("Лучшие маршруты по поколениям")
    axes[0].set_xlabel("X")
    axes[0].set_ylabel("Y")

    # График 2: Лучший маршрут среди всех
    best_route_coords = np.array([coords[city] for city in final_best_route + [final_best_route[0]]])
    axes[1].plot(best_route_coords[:, 0], best_route_coords[:, 1], marker='o', linestyle='-', color='red')
    axes[1].set_title("Лучший маршрут среди всех поколений")
    axes[1].set_xlabel("X")
    axes[1].set_ylabel("Y")

    # График 3: Оптимальный маршрут
    # optimal_route_coords = np.array([coords[city] for city in optimal_route + [optimal_route[0]]])
    # axes[2].plot(optimal_route_coords[:, 0], optimal_route_coords[:, 1], marker='o', linestyle='-', color='blue')
    # axes[2].set_title("Оптимальный маршрут из условия задачи")
    # axes[2].set_xlabel("X")
    # axes[2].set_ylabel("Y")
    #
    plt.tight_layout()
    plt.show()

# --- Шаг 5: Запуск алгоритма ---
best_route, best_distance, all_best_routes = ant_colony_optimization(
    COORDINATES, distance_matrix, N_ANTS, N_ITERATIONS, ALPHA, BETA, EVAPORATION_RATE, PHEROMONE_CONSTANT
)

# Вывод результатов
print("Лучший маршрут, найденный алгоритмом:", best_route)
print("Длина найденного маршрута:", best_distance)

# Визуализация маршрутов
visualize_routes(COORDINATES, all_best_routes, best_route, OPTIMAL_ROUTE)
