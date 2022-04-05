/*
  Разработать функцию, которая выполняет ту обработку символьной строки, которая
  определена в Вашем индивидуальном задании

  Вариант 12
    Функция доводит длину строки до заданной, вставляя пробелы между словами.

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

int main() {
	// смена кодировки
  system("chcp 65001");

  // очистка терминала
  clear_scr();

  cout << "Введите строку: ";
  char_str = get_string(&len);

	return 0;
}
