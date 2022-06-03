
#include <iostream>
using namespace std;

#include <cmath>
#include <time.h>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>

#define NUMS_CHAR_LEN 10

// функция для проверка файла на существование
char *get_file_name(const char *promt = "", const char *error_promt = "", bool new_file = false) {

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
        if (new_file) {
          ofstream ost(input_file_name);
        } else {
          cout << error_promt << endl;
          ok = false;
        }

      }

      input_file.close();

    }
  }

  return input_file_name;
}

// функция для определения цифры
int check_num(char str) {
  char nums_char[NUMS_CHAR_LEN] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  for (int i = 0; i < NUMS_CHAR_LEN; i++) {
    if (nums_char[i] == str) {
      return i;
    }
  }
  return -1;
}

// функция для подсчёта слов
void check_words(char *input_file_name, char *output_file_name) {

  ifstream input_file;
  ofstream output_file;

  // открываем файлы
  input_file.open(input_file_name);
  output_file.open(output_file_name);

  // буферная переменная для хранения считанного символа
  char c;

  int nums_count = 0;
  int str_len = 0;
  // массив для сохранения считанной строки
  char *str = (char*) malloc(sizeof(char));

  // цикл по всему файлу
  while (input_file) {

    // берём из файла 1 символ
    c = input_file.get();

    // записываем строку, если это конец строки или файла
    if (c == '\n' || !input_file) {
      if (nums_count != 2) {
        str[str_len] = '\0';
        output_file << str << endl;
      }

      // обнуляем все переменные
      nums_count = 0;
      str_len = 0;
      str = (char*) malloc(sizeof(char));

    } else {
      // зписываем строку в массив
      str = (char*) realloc(str, (++str_len + 1) * sizeof(char));
      str[str_len - 1] = c;
      // если в строке есть цифра, то прибавляем к счётсчику 1
      if (check_num(c) != -1) nums_count++;

    }

  }

  // закрываем файлы
  input_file.close();
  output_file.close();

}
