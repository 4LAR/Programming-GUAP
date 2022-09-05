#include <iostream>
#include <cmath> // для pow (возведение в степень)

using namespace std;

// функция для сбора в команду сложения
unsigned short code(int a, int b, int d) {
  if (
    (a >= 0 && a < pow(2, 3)) &&
    (b >= 0 && b < pow(2, 3)) &&
    (d >= 0 && d < pow(2, 1))
  ) {
    return 0 | b << 1 | a << 4 | d << 7;
  } else {
    cout << "Числа не входят в диапазон" << endl;

    exit(0);
    //return 0;
  }
}

void decode(unsigned short x) {
  int d = (x>>7)&0x1;
  int a = (x>>4)&0x7;
  int b = (x>>1)&0x7;

  draw_line(20);
  cout << dec << "Тип операндов: " << d << endl;
  cout << dec << "Регистр - 1 операнд: " << a << endl;
  cout << dec << "Регистр - 2 операнд: " << b << endl;
  draw_line(20);
}
