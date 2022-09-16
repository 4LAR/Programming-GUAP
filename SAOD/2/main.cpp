/*
  4 вариант (26 % 23) + 1


*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

#include "structs.h"

list *get_func(int n, list *tmp, const char *promt = "") {
  int a;
  for (int i = n; i > 0; i--) {
    cout << promt << "[" << i << "] = ";
    a = read_value("", true, true, false);
    if (tmp == NULL) {
      tmp = create(i, a);
    } else {
      add_element_end(i, a, tmp);
    }
  }

  return tmp;
}

int main() {
	// смена кодировки
  system("chcp 65001");

  list *q_list = NULL;
  list *r_list = NULL;

  int n_q = read_value("Введите размер многочлена Q: ", true, true, false);
  int n_r = read_value("Введите размер многочлена R: ", true, true, false);

  q_list = get_func(n_q, q_list, "A");
  r_list = get_func(n_r, r_list, "B");

  draw_list(q_list);
  draw_list(r_list);

	return 0;
}
