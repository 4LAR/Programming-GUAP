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
  draw_line();

  StopWatch sw_default;
  StopWatch sw_params(10);
  StopWatch sw_copy_default = sw_default;

  draw_line();

  cout << "Вывод времени без запуска." << endl;
  sw_default.show("Без параметров: ");
  sw_params.show("С параметрами: ");
  sw_copy_default.show("Скопированный: ");
  draw_line();

  sw_default.start();
  sw_params.start();
  sw_copy_default.start();

  sleep(2);

  cout << "Спустя 2 секунды работающих таймеров." << endl;
  sw_default.show("Без параметров: ");
  sw_params.show("С параметрами: ");
  sw_copy_default.show("Скопированный: ");
  draw_line();

  sw_default.stop();
  sw_params.stop();
  sw_copy_default.stop();

  sleep(4);

  cout << "Спустя 4 секунды остановленных таймеров." << endl;
  sw_default.show("Без параметров: ");
  sw_params.show("С параметрами: ");
  sw_copy_default.show("Скопированный: ");
  draw_line();

	return 0;
}
