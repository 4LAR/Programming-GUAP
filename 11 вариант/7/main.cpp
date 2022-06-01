/*
  Разработать функцию, которая выполняет ту обработку символьной строки, которая
  определена в Вашем индивидуальном задании

  Вариант 11
    Функция находит последнее вхождение в строку заданной подстроки.

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

#include "more_char.h"

int main() {
	// смена кодировки
  system("chcp 65001");

  // очистка терминала
  //clear_scr();

  int len, other_len;
  char *char_str, *other_char_str;

  char_str = check_char(&len, "Введите строку: ");
  other_char_str = check_char(&other_len, "Введите подстроку: ");

  draw_line(20);

  //


  // выводим новую строку
  cout << char_str << endl;
  draw_line(20);
  cout << "Длинна новой строки: " << len << endl;

  free(char_str);
  free(other_char_str);

	return 0;
}
