
#include <iostream>
using namespace std;

#include <cmath>
#include <time.h>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>

char *get_file_name(const char *promt = "", const char *error_promt = "") {

  ifstream input_file;

  int len;
  char *input_file_name;

  bool ok = false;
  while (!ok) {
    cout << promt;
    input_file_name = get_string(&len);
    if (len > 0) {
      ok = true;

      input_file.open(input_file_name);

      if (!input_file.good()) {
        cout << error_promt << endl;
        ok = false;
      }

      input_file.close();

    }
  }

  return input_file_name;
}

void check_words(char *input_file_name, char *output_file_name, bool data = false) {

  ifstream input_file;
  ofstream output_file;

  // открываем файлы
  input_file.open(input_file_name);
  output_file.open(output_file_name);

  char c;
  bool space = true;
  bool state = false;

  if (data) {
    draw_line(20);
    cout << "Отладочная информация." << endl;
    draw_line(20);
  }

  while (input_file) {
    c = input_file.get();

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
      output_file << c;

      if (c == '.' || c == '?' || c == '!') { // проверка на конец предложения
        state = false;
        space = false;
        if (data) cout << endl;
        output_file << endl;
      }
    }
  }

  // закрываем файлы
  input_file.close();
  output_file.close();

}
