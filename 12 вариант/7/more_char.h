  #include <iostream>
using namespace std;

char *add_space_char(char *char_str, int *len, int len_new) {
  int j = 1;
  int i = 0;
  // основной код
  while ((*len) < len_new) {
    // если встречаем пробел или мы на первом символе
    if (char_str[i] == ' ' || i == 0) {
      (*len)++;

      char_str = (char*) realloc(char_str, (*len+1) * sizeof(char));
      for (int k = (*len); k > i; k--) {
        char_str[k] = char_str[k-1];
      }
      char_str[i] = ' ';

      i += j;
    }

    // счётсчики
    i++;
    if (i >= (*len)) {
      i = 0;
      j++;
    }
  }

  return char_str;
}
