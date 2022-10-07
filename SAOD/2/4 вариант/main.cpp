/*
  4 вариант (26 % 23) + 1


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

list *get_func(int n, list *tmp, const char *promt = "") {
  int a;
  for (int i = n - 1; i >= 0; i--) {
    cout << promt << "[" << i << "] = ";
    a = read_value("", true, true, false);
    if (a != 0)
      if (tmp == NULL) {
        tmp = create(i, a);
      } else {
        add_element_end(i, a, tmp);
      }
  }

  return tmp;
}

int get_length_list(list *tmp) {
  int length = 0;
  while (tmp != NULL) {
    length++;
    tmp = tmp -> next;
  }
  return length;
}

void draw_table(list *tmp) {
  // int length_A = get_length_list(list_a);
  // int length_B = get_length_list(list_b);

  int i = 0;

  cout << "| ID | X  | A  |\n";

  // for (int i = 0; i < ((length_A > length_B)? length_A: length_B); i++) {
  while (tmp != NULL) {
    cout << "| " << setw(3) << i;
    cout << "| " << setw(3) << tmp -> n;
    cout << "| " << setw(3) << tmp -> a;
    cout << "|" << endl;
    tmp = tmp -> next;
    i++;
  }

}

int menu() {
  while (true) {
    cout << "1) Добавить элемент в список Q" << endl;
    cout << "2) Удалить элемент из списока Q" << endl;
    cout << "3) Добавить элемент в список R" << endl;
    cout << "4) Удалить элемент из списока R" << endl << endl;
    cout << "0) Выход" << endl;
    int id = read_value(" >>> ", false, false, false);
    if (0 <= id < 5) {
      return id;

    } else {
      cout << "Этого нет в меню" << endl;

    }
  }

}

list *delete_element(list *tmp, int id) {
  int i = 0;
  int length = get_length_list(tmp) - 1;
  list *new_list = NULL;

  while (tmp != NULL) {
    if (id != i) {
      if (new_list == NULL) {
        new_list = create(tmp -> n, tmp -> a);
      } else {
        add_element_end(tmp -> n, tmp -> a, new_list);
      }
    }
    tmp = tmp -> next;
    i++;
  }
  return new_list;
}

list *append_element(list *tmp, int n, int a) {
  list *old = tmp;
  while (tmp != NULL) {
    if (tmp -> n == n) {
      tmp -> a = tmp -> a + a;
      return old;
    }
    tmp = tmp -> next;
  }

  add_element_end(n, a, old);
  return old;
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

  int menu_i;

  int id;
  int a;

  while (true) {
    draw_line();
    draw_func(q_list, "Q(x) = ");
    draw_func(r_list, "R(x) = ");
    p_list = merge_func(q_list, r_list);
    draw_func(p_list, "P(x) = ");

    menu_i = menu();
    switch (menu_i) {
      case (0):
        return 0;
        break;

      case (1):
        draw_table(q_list);
        id = read_value("x: ", true, true, false);
        a = read_value("a: ", true, true, false);
        if (a != 0)
          q_list = append_element(q_list, id, a);

        break;

      case (2):
        draw_table(q_list);
        id = read_value("ID: ", true, true, false);
        q_list = delete_element(q_list, id);
        break;

      case (3):
        draw_table(r_list);
        id = read_value("x: ", true, true, false);
        a = read_value("a: ", true, true, false);
        if (a != 0)
          r_list = append_element(r_list, id, a);

        break;

      case (4):
        draw_table(r_list);
        id = read_value("ID: ", true, true, false);
        r_list = delete_element(r_list, id);
        break;
    }
  }

	return 0;
}
