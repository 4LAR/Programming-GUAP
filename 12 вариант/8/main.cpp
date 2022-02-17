/*

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

void sentence(istream& in) {
  bool state = false;
  char c;

  while ((c = in.get()) && isspace(c));
  if (c == '-')
    state = true;
  else
    state = false;

  if (state) {
    while ((c = in.get()) && isspace(c));
      cout << c;
    while ((c = in.get()) && state) {
      cout << c;
      if (c == '.' || c == '!' || c == '?')
        state = false;
    }
    cout << endl;
  }
}

int main() {

  system("chcp 65001");

  string file_name;

  cout << "file name: ";
  cin >> file_name;

  ifstream in;
  in.open(file_name.c_str(), ios::in);
  if (!in.good()) {
      cout << "Couldn't read file.\n";
      exit(1);
  }

  while (in)
      sentence(in);

  in.close();

  return 0;
}
