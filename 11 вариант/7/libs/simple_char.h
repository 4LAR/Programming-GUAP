
#include <iostream>
// фунция для ввода строки
char *get_string(int *len) {
    *len = 0;
    int capacity = 1;
    char *s = (char*) malloc(sizeof(char));
    char c = getchar();
    while (c != '\n') {
        s[(*len)++] = c;
        if (*len >= capacity) {
            capacity *= 2;
            s = (char*) realloc(s, capacity * sizeof(char));
        }
        c = getchar();
    }
    s[*len] = '\0';
    return s;
}

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
