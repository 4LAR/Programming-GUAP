class TuringMachine:
    def __init__(self, tape, transitions, alphabet):
        # Заполнение ленты до 100 символов
        self.tape = list(tape) + ['_'] * (100 - len(tape))
        self.tape = self.tape[:100]
        self.head = 0
        self.state = 'q0'  # Начальное состояние
        self.transitions = transitions
        self.alphabet = alphabet
        self.steps = 0

    def step(self):
        current_symbol = self.tape[self.head]
        command = self.transitions.get((self.state, current_symbol))

        if (current_symbol == "_"):
            print(self.steps, current_symbol, command)

        if command is None:
            raise Exception(f"Нет перехода для состояния {self.state} и символа {current_symbol}")

        new_state, new_symbol, direction = command

        self.tape[self.head] = new_symbol
        self.state = new_state
        if new_state == 'q00':
            raise Exception(f"Завершение программы")

        if direction == '>':
            self.head += 1
        elif direction == '<':
            self.head -= 1

        self.steps += 1

        # Проверка выхода за границы ленты
        if self.head < 0 or self.head >= len(self.tape):
            raise Exception("Головка вышла за границы ленты")

    def run(self, output_file):
        with open(output_file, 'w', encoding='utf-8') as f:
            while True:
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
