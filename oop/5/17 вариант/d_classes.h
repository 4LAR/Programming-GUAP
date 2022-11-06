
#include <iostream>
using namespace std;

// D1
class D1: virtual protected B1, virtual public B2 {
public:
  D1(int, int, int);
  ~D1();

  void show_d1();
public:
  int d1;
};

D1::D1(int x, int y, int z): B1(y), B2(z) {
  d1 = x;
}

D1::~D1() {
  cout << "Деструктор D1" << endl;
}

void D1::show_d1() {
  cout << "D1 = " << d1 << endl;
  show_b1();
  show_b2();
}

// D2
class D2: virtual public D1, virtual protected B3 {
public:
  D2(int, int, int, int, int);
  ~D2();

  void show_d2();
public:
  int d2;
};

D2::D2(int x, int y, int z, int i, int j): D1(y, z, i), B1(z), B2(i), B3(j) {
  d2 = x;
}

D2::~D2() {
  cout << "Деструктор D2" << endl;
}

void D2::show_d2() {
  cout << "D2 = " << d2 << endl;
  show_d1();
  show_b3();
}

// D3
class D3: public D2 {
public:
  D3(int, int, int, int, int, int);
  ~D3();

  void show_d3();
public:
  int d3;
};

D3::D3(int x, int y, int z, int i, int j, int k): D2(y, z, i, j, k), D1(z, i, j), B1(i), B2(j), B3(k) {
  d3 = x;
}

D3::~D3() {
  cout << "Деструктор D3" << endl;
}

void D3::show_d3() {
  cout << "D3 = " << d3 << endl;
  show_d2();
}
