#include <iostream>
#include <cmath>

using namespace std;

void clear_scr() {
  cout << "\e[1;1H\e[2J";
}

void draw_line(int size) {
  for (int i = 0; i < size; i++)
    cout << '-';
  cout << endl;
}
