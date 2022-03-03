#include <iostream>
#include <cmath>

using namespace std;

double zad_1_loop(int type, int i, int s) {
  switch (type) {
    case (1):
      return ((pow(-1, i) > 0)? s += i: s *= i);
      break;
    case (2):
      return (s + (pow(-1, i+1) * (1/(double)i)));
      break;
    default:
      return 0;
      break;
  }

}

void zad_1() {
  cout << "Задание 1" << endl;
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
    cout << "Введите номер (целое число от 1 до 2): ";
    v2 = read_int();
    if (3 > v2 > 0)
      break;
  }

  cout << "Введите A: ";
  int a = read_int();
  double x = 0;
  if (v1 == 1 || v1 == 2){
    double i = 1;
    x = 0;
    if (v2 == 1){
      while (i < a + 1) {
        if ((v1 == 1 && i >= 1.5) || v1 == 2)
          x = zad_1_loop(v1, (int)i, x);
        i += (v1 == 1)? 0.5: 1;
      }
    } else {
      for (double i = 1; i < a + 1; i += (v1 == 1)? 0.5: 1)
        x = zad_1_loop(v1, (int)i, x);
    }

    if (v1 == 1)
      x += (a - 1) * a;
    else
      x *= 4;
  } else {
    x = 1;
    cout << "Введите B: ";
    int b = read_int();
    if (v2 == 1){
      int i = 1;
      while (i < b + 1) {
        x *= a;
        i++;
      }
    } else {
      for (int i = 1; i < b + 1; i++)
        x *= a;
    }
  }

  cout << "S = " << x << endl;

}
