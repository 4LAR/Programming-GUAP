/*
  6 вариант

    Разработать на языке программирования высокого уровня программу,
  которая должна выполнять следующие функции:
  - добавлять элементы в сбалансированное дерево поиска;
  - удалять элементы из сбалансированного дерева поиска;
  - искать элементы в дереве поиска с выводом количества шагов, за которое осуществляется поиск;
  - выводить дерево на экран (любым способом доступным для восприятия);
  - выводить список, соответствующий обходу вершин, в соответствии
  с вариантом задания;

		Подсчитать среднее арифметическое всех листов дерева.
	Затем вычесть из каждого листа данное значение, затем
	обойти дерево еще раз и удалить все элементы, делящиеся без
	остатка на 3 и перестроить дерево с учетом изменений

	Порядок обхода Обратный
*/

#include <iostream>
using namespace std;

#include <iomanip>


#include "tree.h"

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
		cout << endl;
    cout << "1) Вывести дерево" << endl;
    cout << "2) Добавить элемент" << endl;
    cout << "3) Добавить несколько элементов (random)" << endl;
    cout << "4) Удалить элемент" << endl;
    cout << "5) Поиск" << endl;
    cout << "6) Обход дерева (Обратный - PostOrder)" << endl;
		cout << "7) Удалить элементы которые не делятся на 3 (задание)." << endl;
    cout << "0) Выход" << endl;
    cout << " > ";
    int id = read_double();
    if (0 <= id <= 7) {
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
				cout << "Изначальное дерево." << endl;
			  tree.show();

				double average = tree.average(tree.get_root());
				cout << "Среднее арифметическое всех элементов: " << average << endl;

				tree.transform(tree.get_root(), average);
				tree.delete_non_divisible_3_Delete();
				cout << "Дерево после операции." << endl;
				tree.show();
			}

    }
  }

  return 0;
}
