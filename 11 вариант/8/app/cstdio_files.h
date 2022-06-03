
// основные комментарии к алгоритме находятся в файле <<fstream_files.h>>

#include <iostream>
using namespace std;

#include <cmath>
#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cctype>

#define NUMS_CHAR_LEN 10

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

      input_file = fopen(input_file_name, "rw"); // если выдаёт ошибку поставь "r" вместо "rw"

      if (input_file == NULL) {
        cout << error_promt << endl;
        ok = false;
      }

      fclose(input_file);

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

void check_words(char *input_file_name, char *output_file_name) {

  FILE *input_file;
  FILE *output_file;

  input_file = fopen(input_file_name, "r");
  output_file = fopen(output_file_name, "w");

  char c;
  int symb;

  int nums_count = 0;
  int str_len = 0;
  // массив для сохранения считанной строки
  char *str = (char*) malloc(sizeof(char));

  while (!feof(input_file)) {
    fscanf(input_file, "%c", &c);

    if (c == '\n' || feof(input_file)) {
      if (nums_count != 2) {
        str[str_len] = '\0';
        fprintf(output_file, "%s\n", str);
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

  fclose(input_file);
  fclose(output_file);

}
