/*
  26 вариант

  26 % 25 + 1 = 2

  Линейное опрабирование

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>
#include <iomanip>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

//
#include "hash.h"

int menu() {
  while (true) {
    cout << "1) Сгенерировать ключ" << endl;
    cout << "2) Сгенерировать список ключей" << endl;
    cout << "3) Вывести списко ключей" << endl;
    cout << "4) Экспортировать в файл" << endl << endl;
    cout << "0) Выход" << endl;
    int id = read_value(" >>> ", false, false, false);
    if (0 <= id < 5) {
      return id;

    } else {
      cout << "Этого нет в меню" << endl;

    }
  }

}

int main() {
  // смена кодировки
  system("chcp 65001");

  srand(time(NULL));

  /*
    i (int) = число
    c (char) = буква
  */

  My_hash my_hash("iiiccii");
  
  int menu_i;
  while (true) {
    menu_i = menu();

    switch (menu_i) {
    case (1):
      
      break;
    }
    
  }

  cout << my_hash.generate() << endl;

  return 0;
}