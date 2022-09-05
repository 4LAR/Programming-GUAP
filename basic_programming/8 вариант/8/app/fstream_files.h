
#include <iostream>
using namespace std;

#include <cmath>
#include <time.h>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>

#define NUMS_CHAR_LEN 10

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

void check_words(char *input_file_name, char *output_file_name, bool data = false) {

  ifstream input_file;
  ofstream output_file;

  input_file.open(input_file_name);
  output_file.open(output_file_name);

  if (data) {
    draw_line(20);
    cout << "Отладочная информация." << endl;
    draw_line(20);
  }

  bool state = false;
  char c;

  while (input_file) {
    c = input_file.get();
    if (c == '\"' || c == '\'') {
      state = !state;
      if (!state) {
        if (data) cout << endl;
        output_file << "\n";
      }
    } else if (state) {
      if (data) cout << c;
      output_file << c;
    }
  }

  input_file.close();
  output_file.close();

}
