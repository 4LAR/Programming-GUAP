/*
  3 вариант (26 % 24 + 1)

    Разработать на языке программирования высокого уровня программу,
  которая должна выполнять следующие функции:
  - добавлять элементы в сбалансированное дерево поиска;
  - удалять элементы из сбалансированного дерева поиска;
  - искать элементы в дереве поиска с выводом количества шагов, за которое осуществляется поиск;
  - выводить дерево на экран (любым способом доступным для восприятия);
  - выводить список, соответствующий обходу вершин, в соответствии
  с вариантом задания;

    Вывести глубину самого верхнего листа дерева (maxh) и
  самого нижнего листа (ов) дерева (minh), а так же их
  значения. Удалить элементы и перебалансировать дерево.
  Процедуру повторять до тех пор, пока не выполнится условие
  maxh = minh
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

#include "tree.h"

#define RANDOM_MIN -100
#define RANDOM_MAX 100

int menu() {
  while (true) {
    cout << "1) Добавить элемент" << endl;
    cout << "2) Добавить несколько элементов (random)" << endl;
    cout << "3) Удалить элемент" << endl;
    cout << "4) Поиск" << endl;
    cout << "5) Обход дерева (симетрично - inOrder)" << endl;
    cout << "6) Вывод глубин листов (minh, maxh)" << endl;
    cout << "7) Выровнять листы (minh == maxh)" << endl;
    cout << "0) Выход" << endl;
    int id = read_value(" >>> ", false, false, false);
    if (0 <= id <= 7) {
      return id;

    } else {
      cout << "Этого нет в меню" << endl;
    }
  }
}

int main() {
  // смена кодировки
  system("chcp 65001");

  Tree tree;

  int menu_i;
  while (true) {
    clear_scr();
    tree.show();
    draw_line(30);
    menu_i = menu();

    switch (menu_i) {
      case (0):
        return 0;
        break;

      case (1): {
        while (true) {
          if (!tree.append(read_value("Новый элемент: ", true, true, false))) {
            cout << "Такой элемент уже существует." << endl;
          } else break;
        }
        break;
      }

      case (2): {
        double a = read_value("Количество новых элементов: ", true, true, false);
        for (int i = 0; i < a; i++) {
          tree.append(random_int(RANDOM_MIN, RANDOM_MAX));
        }
        break;
      }

      case (3): {
        double a = read_value("Удаляемый элемент: ", true, true, false);
        tree.remove_elem(a);
        break;
      }

      case (4): {
        double a = read_value("Элемент: ", true, true, false);
        Node* find_element = tree.find(a);
        if (find_element != NULL) {
          tree.print_recursion("", find_element, false);
        } else cout << "Такого элемента не существет." << endl;
        cout << "Нажмите enter для продолжения..." << endl;
        getchar();
        break;
      }

      case (5): {
        tree.inOrder(tree.get_root());
        cout << endl << "Нажмите enter для продолжения..." << endl;
        getchar();
        break;
      }

      case (6): {
        vector<double*> v = tree.get_height();
        int min_id = 0;
        int max_id = 0;
        cout << "Все листы: ";
        for (int i = 0; i < v.size(); i++) {
          cout << setw(4) << v.at(i)[0] << ":" << v.at(i)[1] << " ";
          if (v.at(i)[1] > v.at(min_id)[1])
            min_id = i;
          if (v.at(i)[1] < v.at(max_id)[1])
            max_id = i;
        }
        cout << endl;
        cout << "minh = " << v.at(min_id)[0] << ":" << v.at(min_id)[1] << endl;
        cout << "maxh = " << v.at(max_id)[0] << ":" << v.at(max_id)[1] << endl;
        cout << endl << "Нажмите enter для продолжения..." << endl;
        getchar();
        break;
      }

      case (7): {
        vector<double*> v;
        int min_id;
        bool ok;
        while (true) {
          v = tree.get_height();

          min_id = 0;
          ok = true;
          for (int i = 0; i < v.size(); i++) {
            if (v.at(i)[1] < v.at(min_id)[1]) {
              ok = false;
              min_id = i;
            }
          }
          
          if (ok) break;

          for (int i = 0; i < v.size(); i++) {
            if (v.at(min_id)[1] != v.at(i)[1]) {
              tree.remove_elem(v.at(i)[0]);
            }
          }
        }
        break;
      }

    }
  }

  return 0;
}
