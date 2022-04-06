/*
    Написать программу, которая считывает текст из файла и записывает в другой файл
  предложения, начинающиеся с тире, перед которым могут находиться только пробельные
  символы.
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

// набор функций для этой лабы
#include "file.h"

int main() {
  // смена кодировки
  system("chcp 65001");

  // очистка терминала
  clear_scr();

  char *input_file_name;
  char *output_file_name;

  ifstream input_file;
  ofstream output_file;

  input_file_name = get_file_name("Имя входного файла: ", "Невозможно прочитать файл. Возможно его не существует.");
  output_file_name = get_file_name("Имя выходного файла: ", "Невозможно записать или создать файл.");

  // открываем файлы
  input_file.open(input_file_name);
  output_file.open(output_file_name);

  draw_line(20);
  cout << "Отладочная информация." << endl;
  draw_line(20);
  
  char c;
  bool space = true;
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

  cout << "В файл " << output_file_name << " был успешно записан результат." << endl;

  // закрываем файлы
  input_file.close();
  output_file.close();

  return 0;
}
