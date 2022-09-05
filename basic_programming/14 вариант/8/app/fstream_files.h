
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

char *get_symbol(int num) {
  switch (num) {
    case (0):
      return (char*)"ноль";
      break;
    case (1):
      return (char*)"один";
      break;
    case (2):
      return (char*)"два";
      break;
    case (3):
      return (char*)"три";
      break;
    case (4):
      return (char*)"четыре";
      break;
    case (5):
      return (char*)"пять";
      break;
    case (6):
      return (char*)"шесть";
      break;
    case (7):
      return (char*)"семь";
      break;
    case (8):
      return (char*)"восемь";
      break;
    case (9):
      return (char*)"девять";
      break;
  }
  return 0;
}

//
int check_num(char str) {
  char nums_char[NUMS_CHAR_LEN] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  for (int i = 0; i < NUMS_CHAR_LEN; i++) {
    if (nums_char[i] == str) {
      return i;
    }
  }
  return -1;
}

//
void check_words(char *input_file_name, char *output_file_name, bool data = false) {

  ifstream input_file;
  ofstream output_file;

  input_file.open(input_file_name);
  output_file.open(output_file_name);

  char c;
  bool space = true;
  bool state = false;
  int symb;

  if (data) {
    draw_line(20);
    cout << "Отладочная информация." << endl;
    draw_line(20);
  }

  while (input_file) {
    c = input_file.get();
    if (c == '.' || c == '?' || c == '!') {
      if (data) cout << endl;
      output_file << "\n";
    } else {
      symb = check_num(c);
      if (symb != -1) {
        if (data) cout << get_symbol(symb);
        output_file << get_symbol(symb);
      } else {
        if (data) cout << c;
        output_file << c;
      }
    }
  }

  input_file.close();
  output_file.close();

}
