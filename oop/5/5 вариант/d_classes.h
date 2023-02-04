
#include <iostream>
using namespace std;

class D1: public B1, public B2 {
public:
  D1(int, int, int);
  ~D1();
  void show_D1();

public:
  int d1;

};

D1::D1(int x, int y, int z): B1(y), B2(z) {
  d1 = x;
  cout << "Конструктор с аргументами D1" << endl;
}

D1::~D1() {
  cout << "Деструктор D1" << endl;
}

void D1::show_D1() {
  cout << "D1 = " << d1 << endl;
  show_B1();
  show_B2();

}

/*----------------------------------------------------------------------------*/

class D2 {
public:
  D2(int);
  ~D2();
  void show_D2();

public:
  int d2;

};

D2::D2(int x) {
  d2 = x;
  cout << "Конструктор с аргументами D2" << endl;
}

D2::~D2() {
  cout << "Деструктор D2" << endl;
}

void D2::show_D2() {
  cout << "D2 = " << d2 << endl;
}

/*----------------------------------------------------------------------------*/

class D3: public D1, public D2 {
public:
  D3(int, int, int, int, int);
  ~D3();
  void show_D3();

public:
  int d3;

};

D3::D3(int x, int y, int z, int i, int j): D1(y, z, i), D2(j) {
  d3 = x;
  cout << "Конструктор с аргументами D3" << endl;
}

D3::~D3() {
  cout << "Деструктор D3" << endl;
}

void D3::show_D3() {
  cout << "D3 = " << d3 << endl;
  show_D1();
  show_D2();
}

/*----------------------------------------------------------------------------*/

class D4: public D3 {
public:
  D4(int, int, int, int, int, int);
  ~D4();
  void show_D4();

public:
  int d4;

};

D4::D4(int x, int y, int z, int i, int j, int k): D3(y, z, i, j, k) {
  d4 = x;
  cout << "Конструктор с аргументами D4" << endl;
}

D4::~D4() {
  cout << "Деструктор D4" << endl;
}

void D4::show_D4() {
  cout << "D4 = " << d4 << endl;
  show_D3();
}

/*----------------------------------------------------------------------------*/
