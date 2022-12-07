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
// #include "balance.h"

int main() {
  // смена кодировки
  system("chcp 65001");

  Tree tree;
  tree.append(11);
  tree.append(20);
  tree.append(20);
  tree.append(30);
  tree.append(40);
  tree.append(50);
  tree.append(60);
  tree.append(70);
  tree.append(25);
  tree.append(12);
  tree.append(4);
  tree.append(5);
  tree.append(2);
  tree.append(1);
  tree.append(3);

  cout << "Высота дерева: " << tree.get_height(tree.get_root()) << endl;

  tree.show();

  return 0;
}
