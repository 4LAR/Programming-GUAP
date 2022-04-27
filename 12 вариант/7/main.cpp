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

#include "more_char.h"

int main() {
	// смена кодировки
  system("chcp 65001");

  // очистка терминала
  //clear_scr();

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

  // ввод длинны новой строки
  int len_new;
  while (true) {
    len_new = read_value("Введите длинну новой строки: ", false, false, false);

    if (len_new < len) {
      cout << "Длинна новой строки должна быть больше старой строки (" << len << ")." << endl;
    } else break;
  }

  draw_line(20);

  char_str = add_space_char(char_str, &len, len_new);

  // выводим новую строку
  cout << char_str << endl;
  draw_line(20);
  cout << "Длинна новой строки: " << len << endl;

  free(char_str);

	return 0;
}
