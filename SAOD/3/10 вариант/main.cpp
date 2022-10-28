/*
  10 вариант

  Стек – статический; очередь – динамическая
  3 Задание

  Генератор -> Очередь x3 -> Процессор -> Стек -> Процессор 1

*/

#define AUTO false

#include <iostream>
using namespace std;

#include <cmath>
#include <time.h>
#include <iomanip>

#include "structs.h"
#include "generator.h"
#include "processor.h"

// размер статического стека
#define size_TaskList 5

// количемтво генерируемых задач
#define count_generator_tasks 30

int main() {
	// смена кодировки
  system("chcp 65001");

  srand(time(NULL));

  /* Стек - последный вошёл, первый вышел */
  MYList *stack = new MYList(-1);

  /* Очередь - первый вошёл, первый вышел */
  MYList *queue1 = new MYList(size_TaskList);
  MYList *queue2 = new MYList(size_TaskList);
  MYList *queue3 = new MYList(size_TaskList);

  /* Генератор */
  Generator *generator = new Generator(count_generator_tasks, AUTO);

  /* Процессоры */
  Processors processors(stack, size_TaskList, queue1, queue2, queue3, generator);
  processors.loop();

  delete stack;
  delete queue1;
  delete queue2;
  delete queue3;
  delete generator;

	return 0;
}
