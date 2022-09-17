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
  for (int i = n - 1; i >= 0; i--) {
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

void draw_func(list *tmp, const char *promt = "") {
  cout << promt;
  bool first = true;
  while (tmp != NULL) {
    if (tmp -> a != 0) {
      if (!first)
        cout << " + ";
      else first = false;


      cout << tmp -> a;

      if (tmp -> n != 0) cout << "x^" << tmp -> n;

    }

    tmp = tmp -> next;
  }
  cout << endl;
}

int get_size_list(list *tmp) {
  int size = 0;
  while (tmp != NULL) {
    size++;
    tmp = tmp -> next;
  }
  return size;
}

list *merge_func(list *a, list *b) {
  list *tmp = NULL;

  int size_a = get_size_list(a);
  int size_b = get_size_list(b);

  if (size_b > size_a) {
    list *buf = a;
    a = b;
    b = buf;
  }

  while (a != NULL) {
    if (b != NULL && ((b -> n) == (a -> n))) {

      if (tmp == NULL) {
        tmp = create(a -> n, (a -> a) + (b -> a));
      } else {
        add_element_end(a -> n, (a -> a) + (b -> a), tmp);
      }
      b = b -> next;

    } else {

      if (tmp == NULL) {
        tmp = create(a -> n, a -> a);
      } else {
        add_element_end(a -> n, a -> a, tmp);
      }
    }

    a = a -> next;
  }

  return tmp;
}

int main() {
	// смена кодировки
  system("chcp 65001");

  list *q_list = NULL;
  list *r_list = NULL;
  list *p_list = NULL;

  int n_q = read_value("Введите размер многочлена Q: ", true, true, false);
  int n_r = read_value("Введите размер многочлена R: ", true, true, false);

  q_list = get_func(n_q, q_list, "A");
  r_list = get_func(n_r, r_list, "B");

  draw_func(q_list, "Q(x) = ");
  draw_func(r_list, "R(x) = ");

  p_list = merge_func(q_list, r_list);
  draw_func(p_list, "P(x) = ");

	return 0;
}
