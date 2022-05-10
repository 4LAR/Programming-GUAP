#include <iostream>
using namespace std;


char *clear_char(char *char_str, int *len, int start_pos, int count) {

  int len_new = 0;
  char *str = (char*) malloc(sizeof(char));

  for (int i = 0; i < (*len); i++) {
    if ((i < start_pos) || (i >= (start_pos + count))) {
      str = (char*) realloc(str, (len_new + 2) * sizeof(char));
      str[len_new++] = char_str[i];
    }
  }
  str[len_new] = '\0';

  *len = len_new;

  free(char_str);

  return str;
}

/*------------------------------------------------------------------*/

int get_start_pos(int len) {
  int start_pos;
  while (true) {
    cout << "С какой позиции удалять символы (от 1): ";
    start_pos = read_int();

    if ((start_pos >= len) || (start_pos < 0)) {
      cout << "Нельзя удалять символы вне строки. (" << len << ")" << endl;
    } else {
      break;
    }
  }

  return start_pos;
}

int get_count(int len, int start_pos) {
  int count;
  while (true) {
    cout << "Сколько символов удалить (" << (len - (start_pos-1)) << "): ";
    count = read_int();

    if ((count >= (len - (start_pos-1))) || (count < 0)) {
      cout << "Нельзя удалять символы вне строки."<< endl;
    } else {
      break;
    }
  }

  return count;
}
