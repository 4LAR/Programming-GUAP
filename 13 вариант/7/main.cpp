/*
  Разработать функцию, которая выполняет ту обработку символьной строки, которая
  определена в Вашем индивидуальном задании

  Вариант 17
    Функция находит в строке первый символ, который не входит в другую заданную строку

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>

// проверка ввода
#include "libs/simple_char.h"

#include "more_char.h"

// функция для ввода строки и проверки её
char *check_char(int *len, const char *promt = "") {
  (*len) = 0;
  char *char_str;

  // ввод строки
  while (true) {
    cout << promt;
    char_str = get_string(&(*len));

    if ((*len) > 0) {
      // проверка на пробелы (строка не должна состоять из пробелов)
      bool space_check = false;
      for (int i = 0; i < (*len); i++)
        if (!isspace(char_str[i])) {
          space_check = true;
          break;
        }

      if (space_check)
        break;
      else
        cout << "Строка не может состоять из пробелов." << endl;

    } else {
      cout << "Вы ввели пустую строку." << endl;
    }
  }

  return char_str;
}

int main() {
	// смена кодировки
  system("chcp 65001");

  // очистка терминала
  //clear_scr();

  // здесь будет храниться длинна вводимых строк
  int len_1, len_2;

  // вводим строки
  char *char_str_1 = check_char(&len_1, "Введите первую строку: ");
  char *char_str_2 = check_char(&len_2, "Введите вторую строку: ");

  draw_line(20);

  //
  int find_index = str_find(char_str_1, len_1, char_str_2, len_2);

  if (find_index == -1) {
    cout << "Все символы входят во вторую строку." << endl;
  } else {
    cout << "Первый символ который мы нашли: " << char_str_1[find_index] << endl;
    cout << "Его индекс в первой строке: " << find_index << endl;
  }

  // очищаем память
  free(char_str_1);
  free(char_str_2);

	return 0;
}
