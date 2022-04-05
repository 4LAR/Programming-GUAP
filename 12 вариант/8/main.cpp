/*

*/
#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <cctype>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

char *get_file_name(const char *promt = "") {
  int len;
  char *input_file_name;
  while (true) {
    input_file_name = get_string(&len);
    if (len > 0) {
      break;
    }
  }

  return input_file_name;
}

int main() {
  // смена кодировки
  system("chcp 65001");

  //string input_file_name;


  draw_line(20);

  // ввод имён файлов
  //cout << "Имя входного файла: ";
  int input_file_name_len, output_file_name;
  char *input_file_name = get_file_name();
  char *output_file_name = get_string(&len);

  cout << "Имя выходного файла: ";
  cin >> output_file_name;

  draw_line(20);

  ifstream input_file;
  ofstream output_file;

  // открываем файлы
  input_file.open(input_file_name);
  output_file.open(output_file_name.c_str());

  // обработка ошибок
  if (!input_file.good()) {
    cout << "Невозможно прочитать файл.\n";
    exit(1);
  }
  if (!output_file.good()) {
    cout << "Невозможно создать или записать файл.\n";
    exit(1);
  }

  char c;
  bool space = false;
  bool state = false;
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
      cout << c;
      output_file << c;

      if (c == '.' || c == '?' || c == '!') { // проверка на конец предложения
        state = false;
        space = false;

        cout << endl;
        output_file << endl;
      }
    }
  }

  draw_line(20);

  // закрываем файлы
  input_file.close();
  output_file.close();

  return 0;
}
