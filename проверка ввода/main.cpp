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
  
  // read_value(promt, check_dot, check_minus, check_space)
  cout << read_value("Введите число (double): ", true, true, true) << endl;
  //cout << read_value("Введите число (int): ", false, true, true) << endl;

  return 0;
}
