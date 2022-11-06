
#include <iostream>
using namespace std;


// B1
class B1 {
public:
  B1(int);
  ~B1();

  void show_b1();
protected:
  int b1;
};

B1::B1(int x) {
  b1 = x;
}

B1::~B1() {
  cout << "Деструктор B1" << endl;
}

void B1::show_b1() {
  cout << "B1 = " << b1 << endl;
}

// B2
class B2 {
public:
  B2(int);
  ~B2();

  void show_b2();
public:
  int b2;
};

B2::B2(int x) {
  b2 = x;
}

B2::~B2() {
  cout << "Деструктор B2" << endl;
}

void B2::show_b2() {
  cout << "B2 = " << b2 << endl;
}

// B3
class B3 {
public:
  B3(int);
  ~B3();

  void show_b3();
protected:
  int b3;
};

B3::B3(int x) {
  b3 = x;
}

B3::~B3() {
  cout << "Деструктор B3" << endl;
}

void B3::show_b3() {
  cout << "B3 = " << b3 << endl;
}
