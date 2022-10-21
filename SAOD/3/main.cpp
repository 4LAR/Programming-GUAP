/*
  26 вариант

  Стек – статический; очередь – динамическая
  7 Задание

  Генератор -> Стек -> Процессор 0 -> Очередь -> Процессор 1

*/

#define AUTO true

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>
#include <iomanip>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

#include "structs.h"
#include "generator.h"
#include "processor.h"

// размер статического стека
#define size_TaskList 10
#define count_generator_tasks 30

int main() {
	// смена кодировки
  system("chcp 65001");

  srand(time(NULL));

  /* Стек - последный вошёл, первый вышел */
  Stack *stack = new Stack(size_TaskList);

  /* Очередь - первый вошёл, первый вышел */
  Stack *queue = new Stack(-1);

  /* Генератор */
  Generator *generator = new Generator(count_generator_tasks, AUTO);

  /* Процессоры */
  Processors processors(stack, size_TaskList, queue, generator);
  processors.loop();

  delete stack;
  delete queue;
  delete generator;

	return 0;
}
