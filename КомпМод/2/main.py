import numpy as np
from matplotlib import pyplot as plt

def generate_paysson_process(lmbda, T):
    T0 = 0
    events = []
    while True:
        xi = np.random.rand()
        t_i = -np.log(xi) / lmbda

        if len(events) == 0:
            T_j = T0 + t_i
        else:
            T_j = events[-1] + t_i

        if T_j > T:
            break

        events.append(T_j)
    return events

# Исходные данные
N = 17
T1 = N
T2 = N + 100
lam1 = (N + 8) / (N + 24)  # Теоретическое значение λ1
lam2 = (N + 9) / (N + 25)  # Теоретическое значение λ2

T = T2 - T1

# Генерация пуассоновских потоков
paysson_events1 = generate_paysson_process(lam1, T)
paysson_events2 = generate_paysson_process(lam2, T)

# Суммарный поток
sum_events = np.sort(np.concatenate((paysson_events1, paysson_events2)))

# Вывод последовательностей событий
print("События первого пуассоновского процесса:")
print(paysson_events1)

print("\nСобытия второго пуассоновского процесса:")
print(paysson_events2)

print("\nСуммарный поток событий:")
print(sum_events)
