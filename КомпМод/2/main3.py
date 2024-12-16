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
lam1 = (N + 8) / (N + 24)
lam2 = (N + 9) / (N + 25)

T = T2 - T1
print(f"Теоретические lam1 и lam2: {lam1, lam2}")

# Генерация событий
paysson_events1 = generate_paysson_process(lam1, T)
paysson_events2 = generate_paysson_process(lam2, T)

# Практические значения λ
practical_lam1 = len(paysson_events1) / T
practical_lam2 = len(paysson_events2) / T

print(f"Практические lam1 и lam2: {practical_lam1:.4f}, {practical_lam2:.4f}")

# Графики потоков
plt.figure(figsize=(10, 8))

# График 1: Первый пуассоновский процесс
plt.subplot(311)
plt.scatter(paysson_events1, y=[0]*len(paysson_events1), color='b')
plt.title('Пуассоновский процесс 1')
plt.xlim(0, T)
plt.xlabel('Время')
plt.ylabel('События')

# График 2: Второй пуассоновский процесс
plt.subplot(312)
plt.scatter(paysson_events2, y=[0]*len(paysson_events2), color='r')
plt.title('Пуассоновский процесс 2')
plt.xlim(0, T)
plt.xlabel('Время')
plt.ylabel('События')

# Наложенный график
plt.subplot(313)
plt.scatter(paysson_events1, y=[0]*len(paysson_events1), alpha=0.5, color='b', label='Процесс 1')
plt.scatter(paysson_events2, y=[0]*len(paysson_events2), alpha=0.5, color='r', label='Процесс 2')
plt.title('Наложенные пуассоновские процессы')
plt.xlim(0, T)
plt.xlabel('Время')
plt.ylabel('События')
plt.legend()

plt.tight_layout()
plt.show()
