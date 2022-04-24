#include <iostream>
using namespace std;

int f(int n) {
  return (n > 2)? (n + f(n-1)): n;
}
