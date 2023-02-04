/*
  13 вариант
  Стек – статический; очередь – статическая
  4 Задание
*/

// автоматическая генерация задач
#define AUTO true

#include <iostream>
using namespace std;

#include <cmath>
#include <time.h>
#include <iomanip>

#include "structs.h"
#include "generator.h"
#include "processor.h"

// количемтво генерируемых задач
#define count_generator_tasks 30
// размер статического стека
#define size_stack 10
// размер статической очереди
#define size_queue 10

int main() {
	// смена кодировки
  system("chcp 65001"); // для VS заменить на setlocale(LC_ALL, "Russian");

  srand(time(NULL));

  /* Стек - последный вошёл, первый вышел */
  MYList *stack = new MYList(size_stack);

  /* Очередь - первый вошёл, первый вышел */
  MYList *queue = new MYList(size_queue);

  /* Генератор */
  Generator *generator = new Generator(count_generator_tasks, AUTO);

  /* Процессоры */
  Processors processors(stack, size_stack, queue, size_queue, generator);
  processors.loop();

  delete stack;
  delete queue;
  delete generator;

	return 0;
}
