
#include <iostream>
using namespace std;

/*************************/
class D1: virtual protected B1 {
public:
  D1(int x, int y);
  ~D1();
  void show_D1();

public:
  int d1;

};

D1::D1(int x, int y): B1(y) {
  d1 = x;
  set_B1(y);
  cout << "Конструктор с аргументами D1" << endl;
}

D1::~D1() {
  cout << "Деструктор D1" << endl;
}

void D1::show_D1() {
  cout << "D1 = " << d1 << endl;
  show_B1();

}

/*************************/
class D2: virtual public B1 {
public:
  D2(int x, int y);
  ~D2();
  void show_D2();

public:
  int d2;

};

D2::D2(int x, int y): B1(y) {
  d2 = x;
  cout << "Конструктор с аргументами D2" << endl;
}

D2::~D2() {
  cout << "Деструктор D2" << endl;
}

void D2::show_D2() {
  cout << "D2 = " << d2 << endl;
  show_B1();

}

/*************************/
class D3: protected D2, protected B2 {
public:
  D3(int x, int y, int z, int i);
  ~D3();
  void show_D3();

public:
  int d3;

};

D3::D3(int x, int y, int z, int i): D2(y, z), B2(i) {
  d3 = x;
  cout << "Конструктор с аргументами D3" << endl;
}

D3::~D3() {
  cout << "Деструктор D3" << endl;
}

void D3::show_D3() {
  cout << "D3 = " << d3 << endl;
  show_D2();
  show_B2();

}

/*************************/
class D4: public D1, public D3 {
public:
  D4(int x, int y, int z, int i, int j, int k, int o);
  ~D4();
  void show_D4();

public:
  int d4;

};

D4::D4(int x, int y, int z, int i, int j, int k, int o): D1(y, z), D3(i, j, k, o) {
  d4 = x;
  cout << "Конструктор с аргументами D4" << endl;
}

D4::~D4() {
  cout << "Деструктор D4" << endl;
}

void D4::show_D4() {
  cout << "D4 = " << d4 << endl;
  show_D1();
  show_D3();
}
