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

    if (len_new <= len) {
      cout << "Длинна новой строки должна быть больше старой строки (" << len << ")." << endl;
    } else break;
  }

  draw_line(20);

  int j = 1;
  int i = 0;
  int capacity = 1;
  // основной код
  while (len < len_new) {
    // если встречаем пробел или мы на первом символе
    if (char_str[i] == ' ' || i == 0) {
      len++;

      capacity *= 2;

      char_str = (char*) realloc(char_str, len * sizeof(char));
      for (int k = len; k > i; k--) {
        char_str[k] = char_str[k-1];
      }
      char_str[i] = ' ';

      i += j;
    }

    // счётсчики
    i++;
    if (i >= len) {
      i = 0;
      j++;
    }
  }

  // выводим новую строку
  cout << char_str << endl;
  draw_line(20);
  cout << "Длинна новой строки: " << len << endl;

  free(char_str);

	return 0;
}
