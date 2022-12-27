/*
  14 вариант

    Разработать на языке программирования высокого уровня программу,
  которая должна выполнять следующие функции:
  - добавлять элементы в сбалансированное дерево поиска;
  - удалять элементы из сбалансированного дерева поиска;
  - искать элементы в дереве поиска с выводом количества шагов, за которое осуществляется поиск;
  - выводить дерево на экран (любым способом доступным для восприятия);
  - выводить список, соответствующий обходу вершин, в соответствии
  с вариантом задания;

		Обойти дерево в соответствии с вариантом и найти
	максимальную глубину листа. Циклично добавлять элементы
	в дерево, пока высота всех листов дерева не будет одинакова,
	но не превысит изначально найденного максимального
	значения

	Порядок обхода: Обратный

*/

#include <iostream>
using namespace std;

#include <iomanip>

#include "tree.h"

#define RANDOM_FILL_TREE false

#define RANDOM_MIN -100
#define RANDOM_MAX 100

// проверка ввода
double read_double(){
	double x;
  while ( (scanf("%lf",&x) ) != 1 ) {
    printf("Неверное введенное значение, попробуйте еще: ");
    while(getchar() != '\n');
  }
  return x;
}

// рандом
int random_int(int a, int b) {
  return a + (rand() % ( b - a + 1 ) );
}

// вывод и ввод элементов меню
int menu() {
  while (true) {
    cout << "1) Вывести дерево" << endl;
    cout << "2) Добавить элемент" << endl;
    cout << "3) Добавить несколько элементов (random)" << endl;
    cout << "4) Удалить элемент" << endl;
    cout << "5) Поиск" << endl;
    cout << "6) Обход дерева (Обратный - PostOrder)" << endl;
    cout << "7) Вывод глубин листов (minh, maxh)" << endl;
    cout << "8) Выровнять листы (minh == maxh)" << endl;
    cout << "0) Выход" << endl;
    cout << "[menu] > ";
    int id = read_double();
    if (0 <= id <= 8) {
      return id;

    } else {
      cout << "Этого нет в меню" << endl;
    }
  }
}

int main() {
  // смена кодировки
  system("chcp 65001"); // для VS заменить на setlocale(LC_ALL, "Russian");

  Tree tree;

  int menu_i;
  while (true) {
    menu_i = menu();

    switch (menu_i) {
      case (0):
        return 0;
        break;

      case (1):
        tree.show();
        break;

      case (2): {
        double a;
        while (true) {
          cout << "Новый элемент: ";
          a = read_double();
          if (!tree.append(a)) {
            cout << "Такой элемент уже существует." << endl;
          } else break;
        }
        break;
      }

      case (3): {
        cout << "Количество новых элементов: ";
        double a = read_double();
        for (int i = 0; i < a; i++) {
          tree.append(random_int(RANDOM_MIN, RANDOM_MAX));
        }
        break;
      }

      case (4): {
        cout << "Удаляемый элемент: ";
        double a = read_double();
        tree.remove_elem(a);
        break;
      }

      case (5): {
        cout << "Элемент: ";
        double a = read_double();
        Node* find_element = tree.find(a);
        if (find_element != NULL) {
          tree.print_recursion(find_element, NULL, false);
        } else cout << "Такого элемента не существет." << endl;
        break;
      }

      case (6): {
        tree.PostOrder(tree.get_root());
        cout << endl;
        break;
      }

      case (7): {
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
        break;
      }

      case (8): {
        vector<double*> v;
        int max_id;
        bool ok;
				double a;

        while (true) {
          v = tree.get_height();

          max_id = 0;
          for (int i = 0; i < v.size(); i++) {
						if (v.at(i)[1] > v.at(max_id)[1]) {
              // ok = false;
              max_id = i;
            }
          }

					ok = true;
					for (int i = 0; i < v.size(); i++) {
						if (v.at(i)[1] < v.at(max_id)[1]) {
              ok = false;
            }
          }

          if (ok) break;

          for (int i = 0; i < v.size(); i++) {
            if (v.at(max_id)[1] > v.at(i)[1]) {
							if (RANDOM_FILL_TREE) {
								tree.append(random_int(RANDOM_MIN, RANDOM_MAX));
							} else {
								tree.show();
				        while (true) {
				          cout << "Новый элемент для выравнивая дерева: ";
				          a = read_double();
				          if (!tree.append(a)) {
				            cout << "Такой элемент уже существует." << endl;
				          } else break;
				        }
							}
            }
          }
        }
        break;
      }

    }
  }

  return 0;
}
