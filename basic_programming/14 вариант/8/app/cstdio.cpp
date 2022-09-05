/*
Написать программу, которая считывает текст из файла и записывает его в другой файл,
заменив цифры от 0 до 9 на слова «ноль, «один», …, «девять», начиная каждое предложение с
новой строки.
*/
#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>
#include <cstdlib>
#include <cctype>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

// набор функций для этой лабы
#include "cstdio_files.h"

int main() {
  // смена кодировки
  system("chcp 65001");

  // очистка терминала
  clear_scr();

  char *input_file_name;
  char *output_file_name;

  input_file_name = get_file_name("Имя входного файла: ", "Невозможно прочитать файл. Возможно его не существует.");
  output_file_name = get_file_name("Имя выходного файла: ", "Невозможно записать или создать файл.");

  check_words(input_file_name, output_file_name, false);

  draw_line(20);

  cout << "В файл " << output_file_name << " был успешно записан результат." << endl;

  return 0;
}
