/*
  Написать программу, которая считывает текст из файла и записывает его в другой файл, добавляя
  после каждого предложения, сколько раз встретилось в нѐм введѐнное с клавиатуры слово.
*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>
#include <fstream>
#include <cctype>

#include "libs/simple_char.h"

#include "fstream_files.h"

int main() {
  system("chcp 65001");

  //clear_scr();

  char *input_file_name;
  char *output_file_name;

  // вводим имена файлов (с проверкой)
  input_file_name = get_file_name("Имя входного файла: ", "Невозможно прочитать файл. Возможно его не существует.");
  output_file_name = get_file_name("Имя выходного файла: ", "Невозможно записать или создать файл.", true);

  draw_line(20);
  int len;
  // вводим слово для поиска
  char *str = check_char(&len, "Слово для поиска: ");

  // подсчитываем найденые слова
  check_words(input_file_name, output_file_name, str, len, false);

  draw_line(20);

  cout << "В файл " << output_file_name << " был успешно записан результат." << endl;

  return 0;
}
