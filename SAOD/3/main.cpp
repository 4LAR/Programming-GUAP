/*
  26 вариант

  Стек – статический; очередь – динамическая
  7 Задание

  Генератор -> Стек -> Процессор 0 -> Очередь -> Процессор 1

*/


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


int main() {
	// смена кодировки
  system("chcp 65001");

  srand(time(NULL));

  /*
    Стек - последный вошёл, первый вышел
  */
  Task *stack = (Task*)malloc(size_TaskList * sizeof(Task));
  
  Task *buf;
  for (int i = 0; i < size_TaskList; i++) {
    buf = generate_task();
    stack[i].priority = buf->priority;
    stack[i].taskTime = buf->taskTime;
    stack[i].durationTime = buf->durationTime;
  }

  /*
    Очередь - первый вошёл, первый вышел
  */
  Task *queue = NULL;
  int queue_size = 0;

  draw_stack(queue, queue_size);
  draw_line();
  queue = append(queue, buf, &queue_size);
  queue = append(queue, buf, &queue_size);
  queue = append(queue, buf, &queue_size);
  draw_stack(queue, queue_size);
  draw_line();

  draw_stack(stack, size_TaskList);
  draw_line();




  // симулятор процессора
  //processorLoop(stack, queue);

	return 0;
}
