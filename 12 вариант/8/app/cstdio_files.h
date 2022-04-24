
#include <iostream>
using namespace std;

#include <cmath>
#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cctype>

char *get_file_name(const char *promt = "", const char *error_promt = "") {

  FILE *input_file;

  int len;
  char *input_file_name;

  bool ok = false;
  while (!ok) {
    cout << promt;
    input_file_name = get_string(&len);
    if (len > 0) {
      ok = true;

      input_file = fopen(input_file_name, "rw");

      if (input_file == NULL) {
        cout << error_promt << endl;
        ok = false;
      }

      fclose(input_file);

    }
  }

  return input_file_name;
}

void check_words(char *input_file_name, char *output_file_name, bool data = false) {

  FILE *input_file;
  FILE *output_file;

  // открываем файлы
  input_file = fopen(input_file_name, "r");
  output_file = fopen(output_file_name, "w");

  char c;
  bool space = true;
  bool state = false;

  if (data) {
    draw_line(20);
    cout << "Отладочная информация." << endl;
    draw_line(20);
  }

  while (!feof(input_file)) {
    fscanf(input_file, "%c", &c);

    if (!space) { // проверка на пробел перед тире
      if (isspace(c))
        space = true;
      else
        space = false;
    } else if (!state) { // проверка на тире после пробела
      if (c == '-')
        state = true;
      else
        state = false;
    } else { // записываем предложение в файл
      if (data) cout << c;
      fprintf(output_file, "%c", c);

      if (c == '.' || c == '?' || c == '!') { // проверка на конец предложения
        state = false;
        space = false;
        if (data) cout << endl;
        fprintf(output_file, "%s", "\n");
      }
    }
  }

  // закрываем файлы
  fclose(input_file);
  fclose(output_file);

}
