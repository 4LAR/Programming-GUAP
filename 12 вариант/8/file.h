
#include <iostream>
using namespace std;

#include <cmath>
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <cctype>

char *get_file_name(const char *promt = "", const char *error_promt = "") {
  
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
        cout << error_promt << endl;
        ok = false;
      }

      input_file.close();

    }
  }

  return input_file_name;
}

