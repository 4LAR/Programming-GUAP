import re
import json

# Функция для проверки строки на наличие символов, не входящих в алфавит
def check_alphabet(input_str, alphabet):
    for char in input_str:
        if char not in alphabet:
            raise ValueError(f"Ошибка: Найден символ '{char}', который не входит в алфавит.")

# Функция для проверки строк на наличие переменных, не входящих в заданное множество
def check_variables(input_str, variables):
    found_vars = re.findall(r'[a-zA-Z]+\d*', input_str)  # Найти все переменные
    for var in found_vars:
        if var not in variables:
            raise ValueError(f"Найдена переменная, не входящая в заданное множество: {var}")

# Функция для проверки формата аксиомы
def check_axiom_format(axiom):
    pattern = r'^\d+\*\d+-\d+=$'
    if not re.match(pattern, axiom):
        raise ValueError("Ошибка: Аксиома должна иметь формат число*число-число=.")

# Функция для проверки правил на наличие недопустимых переменных
def check_rules_variables(rules, variables):
    for rule in rules:
        parts = rule['replacement'].split('->')
        for part in parts:
            check_variables(part.strip(), variables)

# Функция для применения правил с использованием регулярных выражений
def apply_rules(start_str, rules):
    current_str = start_str
    result_log = []

    while True:
        applied = False
        for rule in rules:
            pattern = rule['pattern']
            replacement = rule['replacement']
            match = re.search(pattern, current_str)
            if match:
                result_log.append(f"Исходная строка: {current_str}")
                result_log.append(f"Применяемое правило: {rule['name']}")
                current_str = re.sub(pattern, replacement, current_str, count=1)
                result_log.append(f"Результат применения: {current_str}\n")
                applied = True
                break

        if not applied:
            break

    return current_str, result_log

# Основная функция программы
def main(input_file, output_file):
    try:
        # Чтение входных данных из файла
        with open(input_file, 'r', encoding='utf-8') as f:
            data = json.load(f)

        example = data['example']
        alphabet = data['alphabet']
        variables = data['variables']
        axioms = data['axioms']
        rules = data['rules']

        # Проверка примера на соответствие алфавиту и множеству переменных
        check_alphabet(example, alphabet)
        check_variables(example, variables)
        check_axiom_format(example)  # Проверка формата аксиомы
        check_rules_variables(rules, variables)

        # Применение правил вывода к аксиоме
        current_str, log = apply_rules(example, rules)

        # Запись результата в файл
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write("Результаты применения правил:\n")
            for line in log:
                f.write(line + '\n')

            if not log:
                f.write(f"Ни одно правило не было применено для примера: {example}\n")

        print("Вычисление прошло успешно.")

    except ValueError as ve:
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write(f"В ходе вычисления произошла ошибка: {ve}\n")
        print(f"В ходе вычисления произошла ошибка: {ve}")
    except Exception as e:
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write(f"Ошибка: {e}\n")
        print(f"Ошибка: {e}")

# использование программы
if __name__ == '__main__':
    input_file = 'input.json'  # Файл для чтения входных данных
    output_file = 'output.txt'  # Файл для сохранения результата
    main(input_file, output_file)
