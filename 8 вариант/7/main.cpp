/*
  Разработать функцию, которая выполняет ту обработку символьной строки, которая
  определена в Вашем индивидуальном задании

  Вариант 12
    Функция удаляет из строки заданное количество символов, начиная с заданной позиции.

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>

// проверка ввода
#include "libs/simple_char.h"

#include "clear_char.h"

int main() {
	// смена кодировки
  system("chcp 65001");

  int len;
  char *char_str;

  // ввод строки
  while (true) {
    cout << "Введите строку: ";
    char_str = get_string(&len);

    if (len > 0) {
      break;
    } else {
      cout << "Вы ввели пустую строку." << endl;
    }
  }

  // вывод длинны текущей строки
  draw_line(20);
  cout << "Длинна введённой строки: " << len << endl;
  draw_line(20);

  int start_pos = get_start_pos(len);
  int count = get_count(len, start_pos);

  draw_line(20);

  char *char_str_new = clear_char(char_str, &len, start_pos - 1, count);

  // выводим новую строку
  cout << char_str_new << endl;
  draw_line(20);
  cout << "Длинна новой строки: " << len << endl;

  free(char_str_new);

	return 0;
}
