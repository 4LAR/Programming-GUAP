/*
  26 вариант

  Стек – статический; очередь – динамическая
  7 Задание

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

#define size_TaskList 10

int main() {
	// смена кодировки
  system("chcp 65001");

  Task *stack = (Task*)malloc(size_TaskList * sizeof(Task));
  Task *queue = None;

  processorLoop(stack, queue);

	return 0;
}
