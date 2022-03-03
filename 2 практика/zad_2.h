#include <iostream>
#include <cmath>

int mod_rad(int i, int x, int type) {
  switch (type) {
    case(1):
      return x += i;
      break;
    case(2):
      return x -= i;
      break;
    case(3):
      return x *= i;
      break;
    default:
      return 0;
  }
}

void zad_2() {
  int i = 0;
  cout << "Задание 2" << endl;
  draw_line(20);
  int v1 = 0;
  while (true){
    cout << "Введите номер задания (целое число от 1 до 3): ";
    v1 = read_int();
    if (4 > v1 > 0)
      break;
  }

  int v2 = 0;
  while (true){
    cout << "Введите номер (целое число от 1 до 3): ";
    v2 = read_int();
    if (4 > v2 > 0)
      break;
  }

  cout << "Введите A: ";
  int a = read_int();

  int x = 1;
  switch (v2) {
    case(1):
      for (int i = 1; i < a; i++)
        x = mod_rad(i, x, v1);
      break;
    case(2):
      i = 1;
      while (i < a) {
        x = mod_rad(i, x, v1);
        i++;
      }
      break;
    case(3):
      i = 1;
      do {
        x = mod_rad(i, x, v1);
        i++;
      } while(i < a);
      break;
  }

  cout << "S = " << x << endl;
}
