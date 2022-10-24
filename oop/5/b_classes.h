
#include <iostream>
using namespace std;

class B1 {
  B1(int);
  void show_B1();
public:
  int b1;
};

class B2 {
  B2(int);
  void show_B2();
protected:
  int b2;
};

/* B1 */
B1::B1(int x) {
  b1 = x;
}

void B1::show_B1() {
  cout << "B1 = " << b1;
}

/* B2 */
B2::B2(int x, int y, int z): B1(y), B2(z) {
  b2 = x;
}

void B2::show_B2() {
  cout << "B2 = " << b2;
}
