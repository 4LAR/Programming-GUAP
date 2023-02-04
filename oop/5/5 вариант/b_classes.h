
#include <iostream>
using namespace std;

class B1 {
public:
  B1(int x);
  B1();
  ~B1();
  void show_B1();
  void set_B1(int);

public:
  int b1;

};

B1::B1(int x) {
  b1 = x;
  cout << "Конструктор с аргументами B1" << endl;
}

B1::B1() {
  b1 = 0;
  cout << "Конструктор по умолчанию B1" << endl;
}


B1::~B1() {
  cout << "Деструктор B1" << endl;
}

void B1::show_B1() {
  cout << "B1 = " << b1 << endl;
}

void B1::set_B1(int x) {
  b1 = x;
}

/*************************/
class B2 {
public:
  B2(int x);
  ~B2();
  void show_B2();
  void set_B2(int);

public:
  int b2;

};

B2::B2(int x) {
  b2 = x;
  cout << "Конструктор с аргументами B2" << endl;
}

B2::~B2() {
  cout << "Деструктор B2" << endl;
}

void B2::show_B2() {
  cout << "B2 = " << b2 << endl;
}

void B2::set_B2(int x) {
  b2 = x;
}
