#include <iostream>
#include <cmath> // для pow (возведение в степень)

using namespace std;

// функция для сбора
unsigned short code(int c, int u, int e, int b) {
  if (
    (c >= 0 && c < pow(2, 3)) &&
    (u >= 0 && u < pow(2, 5)) &&
    (e >= 0 && e < pow(2, 6)) &&
    (b >= 0 && b < pow(2, 1))
  ) {
    return 0 | b << 0 | e << 2 | u << 8 | c << 13;
  } else {
    cout << "Числа не входят в диапазон" << endl;
    exit(0);
  }
}

void decode(unsigned short x) {
  int c = (x>>13)&0x7;
  int u = (x>>8)&0x1F;
  int e = (x>>2)&0x3F;
  int b = (x>>0)&0x1;

  draw_line(20);
  cout << dec << "Номер канала: " << c << endl;
  cout << dec << "Номер устройства в канале: " << u << endl;
  cout << dec << "Код состояния: " << e << endl;
  cout << dec << "Признак занятости устройства: " << b << endl;
  draw_line(20);
}
