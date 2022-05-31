
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

void check_words(char *input_file_name, char *output_file_name, char *str, int len, bool data = false) {

  FILE *input_file;
  FILE *output_file;

  input_file = fopen(input_file_name, "r");
  output_file = fopen(output_file_name, "w");

  char c;
  int symb;

  if (data) {
    draw_line(20);
    cout << "Отладочная информация." << endl;
    draw_line(20);
  }

  int find_count = 0;
  int find_index = 0;

  while (!feof(input_file)) {
    fscanf(input_file, "%c", &c);

    if (c == '.' || c == '?' || c == '!') {
      if (data) cout << c << "(" << find_count << ") ";
      fprintf(output_file, "%c(%d) ", c, find_count);
      find_count = 0;
    } else {
      if (str[find_index] == c) {
        if (find_index >= (len - 1)) {
            find_index = 0;
            find_count++;
        } else {
          find_index++;
        }
      } else {
        find_index = 0;
      }
      fprintf(output_file, "%c", c);
    }
  }

  fclose(input_file);
  fclose(output_file);

}
