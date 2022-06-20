
#include <iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>

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

      input_file = fopen(input_file_name, "rw");

      if (input_file == NULL) {
        cout << error_promt << endl;
        ok = false;
      }

      fclose(input_file);

    }
  }

  return input_file_name;
}

int check_num(char str) {
  char nums_char[NUMS_CHAR_LEN] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  for (int i = 0; i < NUMS_CHAR_LEN; i++) {
    if (nums_char[i] == str) {
      return i;
    }
  }
  return -1;
}
