/*
  10 вариант

  Стек – статический; очередь – динамическая
  4 Задание

*/

#define AUTO true

#include <iostream>
using namespace std;

#include <cmath>
#include <time.h>
#include <iomanip>

#include "structs.h"
#include "generator.h"
#include "processor.h"

// размер статического стека
#define size_TaskList 10

// количемтво генерируемых задач
#define count_generator_tasks 30

int main() {
	// смена кодировки
  system("chcp 65001");

  srand(time(NULL));

  /* Стек - последный вошёл, первый вышел */
  MYList *stack = new MYList(size_TaskList);

  /* Очередь - первый вошёл, первый вышел */
  MYList *queue = new MYList(-1);

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
