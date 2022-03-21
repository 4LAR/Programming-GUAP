#include <iostream>
#include <cmath> // для pow (возведение в степень)

using namespace std;

// функция для сбора в команду сложения
unsigned short code(int s, int m, int h) {
  if (
    (s >= 0 && s < pow(2, 5)) &&
    (m >= 0 && m < pow(2, 6)) &&
    (h >= 0 && h < pow(2, 5))
  ) {
    return 0 | h << 0 | m << 5 | s << 11;
  } else {
    cout << "Числа не входят в диапазон" << endl;

    exit(0);
    //return 0;
  }
}

void decode(unsigned short x) {
  int h = (x>>0)&0x1F;
  int m = (x>>5)&0x3F;
  int s = (x>>11)&0x1F;

  draw_line(20);
  cout << dec << "Секунды: " << s << endl;
  cout << dec << "Секунды (Помноженное на 2): " << s * 2<< endl;
  cout << dec << "Минуты: " << m << endl;
  cout << dec << "Часы: " << h << endl;
  draw_line(20);
}
