/*
  1 вариант (20 mod 10) + 1

    Создайте класс stopwatch для имитации работы секундомера. Используйте конструктор
  для начальной установки секундомера в нуль. Образуйте две функции-члена
  класса start() и stop() соответственно для запуска и остановки секундомера. Включите в
  класс и функцию-член show() для вывода на экран величины истекшего промежутка
  времени (время привести в секундах). Также используйте деструктор для автоматического
  вывода на экран времени, прошедшего с момента создания объекта класса stopwatch до
  его удаления.

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>
#include <unistd.h>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

#include "timer.h"

int main() {
	// смена кодировки
  system("chcp 65001");

  StopWatch *stopwatch = new StopWatch();

  stopwatch -> show("1: ");
  stopwatch -> start();
  sleep(2);

  stopwatch -> show("2: ");
  stopwatch -> stop();
  sleep(2);

  //StopWatch *stopwatch2 = stopwatch;
  //delete stopwatch;

  stopwatch -> show("3: ");
  stopwatch -> start();
  sleep(1);

  stopwatch -> show("4: ");

  delete stopwatch;

	return 0;
}
