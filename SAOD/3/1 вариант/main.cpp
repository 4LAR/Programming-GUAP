/*
  1 вариант

  Стек – статический; очередь – статический
  1 Задание

  Генератор -> Очередь x3 -> Процессор <-> Стек

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
#define size_stack 5
#define size_queue 5

// количемтво генерируемых задач
#define count_generator_tasks 20

int main() {
	// смена кодировки
  system("chcp 65001");

  srand(time(NULL));

  /* Стек - последный вошёл, первый вышел */
  MYList *stack = new MYList(size_stack);

  /* Очередь - первый вошёл, первый вышел */
  MYList *queue1 = new MYList(size_queue);
  MYList *queue2 = new MYList(size_queue);
  MYList *queue3 = new MYList(size_queue);

  /* Генератор */
  Generator *generator = new Generator(count_generator_tasks, AUTO);

  /* Процессоры */
  Processors processors(stack, size_stack, queue1, queue2, queue3, size_queue, generator);
  processors.loop();

  delete stack;
  delete queue1;
  delete queue2;
  delete queue3;
  delete generator;

	return 0;
}
