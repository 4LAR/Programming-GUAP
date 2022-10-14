/*
  26 вариант

  Стек – статический; очередь – динамическая
  7 Задание

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

#include "structs.h"

int main() {
	// смена кодировки
  system("chcp 65001");

  Task test = {1, 2, 3, 4};

  TaskList test_list = create(test);

  for (int i = 0; i < 10; i++)
    cout << add_element_end(test, test_list) << endl;

	return 0;
}
