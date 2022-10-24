
#include <iostream>
using namespace std;

class D1: public B1, protected B2 {
  D1(int, int, int);
  void show_D1();
private:
  int d1;
};

class D2: protected D1 {
  D2(int, int, int);
  void show_D2();
private:
  int d2;
};


/* Основные классы */
class D3: private D2 {
  D3(int);
  void show_D3();
private:
  int d3;
};

class D4: public D2 {
  D4(int);
  void show_D4();
private:
  int d4;
};

/* D1 */
D1::D1(int x, int y, int z): B1(y), B2(z){
  d1 = x;
}

void D1::show_D1() {
  cout << "D1 = " << d1;
}

/* D2 */
D2::D2(int x) {
  d2 = x;
}

void D2::show_D2() {
  cout << "D2 = " << d2;
}

/* D3 */
D3::D3(int x) {
  d3 = x;
}

void D3::show_D3() {
  cout << "D3 = " << d3;
}

/* D4 */
D4::D4(int x) {
  d4 = x;
}

void D4::show_D4() {
  cout << "D4 = " << d4;
}
