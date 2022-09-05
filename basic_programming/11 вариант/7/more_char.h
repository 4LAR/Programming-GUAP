#include <iostream>
using namespace std;

// функция для нахождения строки
int get_last(char *str, int len, char *other_char_str, int other_len) {

  int get_index = other_len - 1;

  // обратный цикл по всей строке
  for (int i = (len - 1); i > 0; i--) {
    if (str[i] == other_char_str[get_index]) {
      get_index--;
    } else {
      get_index = other_len - 1;
    }

    // если нашли строку, то возвращаем её индекс
    if (get_index < 0) return i;
  }

  // если не нашли, возрвщаем -1
  return -1;
}
