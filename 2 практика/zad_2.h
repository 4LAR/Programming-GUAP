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
  int r = random_int(1, 999);

  int i = 0;
  cout << "Задание 2" << endl;
  draw_line(20);
  int v1 = get_N(r, 3);
  int v2 = get_N(r, 3);
  /*while (true){
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
  }*/

  //cout << "Введите A: ";
  //int a = read_int();

  int x = 1;
  switch (v2) {
    case(1):
      for (i = 1; x < r; i++){
        x = mod_rad(i, x, v1);

      }

      break;
    case(2):
      i = 1;
      while (x < r) {
        x = mod_rad(i, x, v1);
        i++;
      }
      break;
    case(3):
      i = 1;
      do {
        x = mod_rad(x, r, v1);
        i++;
      } while(x < r);
      break;
  }
  cout << "R = " << r << endl;
  cout << "S = " << x << endl;
  cout << "M = " << i << endl;
}
