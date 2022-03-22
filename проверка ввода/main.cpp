 /*
    Демонстрация проверка ввода
 */
#include <iostream>

#include "simple_char.h"
#include "input_validation.h"

using namespace std;

int main() {

  // смена кодировки
  system("chcp 65001");

  cout << "Введите число (double): ";
  cout << read_double() << endl;

  return 0;
}
