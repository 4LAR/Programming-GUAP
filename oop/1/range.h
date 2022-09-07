#include <iostream>
using namespace std;

class Range{
  public:
    void rangedraw() {
      cout << "Левая граница: " << left << endl;
      cout << "Правая граница: " << right << endl;
    }

    void rangeset(double set_left, double set_right) {
      left = set_left;
      right = set_right;          
    }

    bool rangecheck(double num) {
      return (left <= num) && (num < right);
    }

  private:
    double left = 0;
    double right = 0;

};