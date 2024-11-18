import numpy as np
import matplotlib.pyplot as plt

# Параметры
N = 10  # Замените на номер студента
T1 = N
T2 = N + 100
lambda1 = (N + 8) / (N + 24)
lambda2 = (N + 9) / (N + 25)

# Генерация пуассоновского потока
def generate_poisson_process(lam, T1, T2):
    events = []
    t = 0
    while t < T2:
        inter_arrival_time = np.random.exponential(1/lam)
        t += inter_arrival_time
        if t < T2:
            events.append(t)
    return events

# Генерация двух потоков
events1 = generate_poisson_process(lambda1, T1, T2)
events2 = generate_poisson_process(lambda2, T1, T2)

# Объединение потоков
combined_events = sorted(events1 + events2)

# Графическая интерпретация
plt.figure(figsize=(10, 6))
plt.step(combined_events, np.arange(1, len(combined_events) + 1), where='post')
plt.title('Пуассоновский поток событий')
plt.xlabel('Время')
plt.ylabel('Количество событий')
plt.grid()
plt.show()
