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

#include "more_char.h"

int main() {
	// смена кодировки
  system("chcp 65001");

  // очистка терминала
  //clear_scr();

  int len, other_len;
  char *char_str, *other_char_str;

  // вводим строки
  char_str = check_char(&len, "Введите строку: ");
  other_char_str = check_char(&other_len, "Введите подстроку: ");

  draw_line(20);

  // вызов функции для поиска строки
  int last_index = get_last(char_str, len, other_char_str, other_len);
  if (last_index != -1) {
    cout << "Начало найденной строки (индекс): " << last_index << endl;

    // вывод строки (в скобках будет показана найденная строка)
    for (int i = 0; i < len; i++) {
      cout << ((i == last_index)? "[": "") << char_str[i] << ((i == last_index + (other_len - 1))? "]": "");
    }
    cout << endl;
  } else {
    cout << "Ничего не найдено" << endl;
  }

  // очищаем память
  free(char_str);
  free(other_char_str);

	return 0;
}
