/*
  Разработать функцию, которая выполняет ту обработку символьной строки, которая
  определена в Вашем индивидуальном задании

  Вариант 17
    Функция находит в строке первый символ, который не входить в другую заданную строку

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>

// проверка ввода
#include "libs/simple_char.h"

#include "more_char.h"

char *check_char(int *len, const char *promt = "") {
  (*len) = 0;
  char *char_str;

  // ввод строки
  while (true) {
    cout << promt;
    char_str = get_string(&(*len));

    if ((*len) > 0) {
      break;
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

  int len_1, len_2;
  char *char_str_1 = check_char(&len_1, "Введите первую строку: ");
  char *char_str_2 = check_char(&len_2, "Введите вторую строку: ");

  free(char_str_1);
  free(char_str_2);

	return 0;
}
