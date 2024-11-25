class TuringMachine:
    def __init__(self, tape, transitions, alphabet):
        self.tape = list(tape)  # Лента, создается из входных данных
        self.head = 0  # Положение головки
        self.state = 'q0'  # Начальное состояние
        self.transitions = transitions  # Таблица переходов
        self.alphabet = alphabet  # Алфавит
        self.steps = 0  # Счётчик шагов

    def step(self):
        # Расширение ленты, если головка выходит за текущие границы
        if self.head < 0:
            self.tape.insert(0, '_')  # Добавить пробел в начало ленты
            self.head = 0  # Переместить головку в начало
        elif self.head >= len(self.tape):
            self.tape.append('_')  # Добавить пробел в конец ленты

        current_symbol = self.tape[self.head]
        command = self.transitions.get((self.state, current_symbol))

        if command is None:
            raise Exception(f"Нет перехода для состояния {self.state} и символа {current_symbol}")

        # Получаем новые состояние, символ и направление
        new_state, new_symbol, direction = command

        # Обновляем символ под головкой
        self.tape[self.head] = new_symbol

        # Обновляем состояние машины
        self.state = new_state
        if new_state == 'q00':  # Конечное состояние
            raise Exception(f"Завершение программы")

        # Двигаем головку
        if direction == '>':
            self.head += 1
        elif direction == '<':
            self.head -= 1

        self.steps += 1  # Увеличиваем счётчик шагов

    def run(self, output_file):
        with open(output_file, 'w', encoding='utf-8') as f:
            while True:
                # Расширение ленты на всякий случай
                if self.head < 0:
                    self.tape.insert(0, '_')
                    self.head = 0
                elif self.head >= len(self.tape):
                    self.tape.append('_')

                # Запись состояния перед выполнением команды
                f.write(''.join(self.tape) + '\n')
                f.write(' ' * self.head + '^' + '\n')
                f.write(f"{self.state} -> {self.transitions.get((self.state, self.tape[self.head]), 'Нет команды')} \n")

                try:
                    self.step()
                except Exception as e:
                    f.write(f"{e}\n")
                    break

def read_file(filename):
    with open(filename, 'r') as f:
        return f.read().strip()

def read_transitions(filename):
    transitions = {}
    with open(filename, 'r') as f:
        for line in f:
            state, symbol, new_state, new_symbol, direction = line.strip().split()
            transitions[(state, symbol)] = (new_state, new_symbol, direction)
    return transitions

def main():
    tape = read_file('tape.txt')
    alphabet = read_file('alphabet.txt').split()
    transitions = read_transitions('transitions.txt')

    # Проверка алфавита
    for symbol in tape:
        if symbol not in alphabet:
            raise Exception(f"Символ '{symbol}' не в алфавите")

    tm = TuringMachine(tape, transitions, alphabet)
    tm.run('output.txt')

if __name__ == "__main__":
    main()
