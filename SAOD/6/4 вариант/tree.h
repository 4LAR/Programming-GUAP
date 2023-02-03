#include <iostream>
using namespace std;
#include <vector>

// узел дерева
struct Node {
  double elem;     // содержимое узла
  int height;   // высота узла
  Node *left = NULL;   // указатель на меньшего потомка
  Node *right = NULL;  // указатель на большего потомка
};

// для вывода деревая
struct Trunk {
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

#include "balance.h"

class Tree {
public:
  Tree();

  bool append(double);
  void remove_elem(double);
  void show();
  Node* get_root();
  vector<double*> get_height();
  void get_height_recursion(Node* ptr, int);
  Node* find(double);
  Node* balance_node(Node* ptr);
  // void PostOrder(Node* ptr);
  void bfsearch();
  void print_recursion(Node* ptr, Trunk *prev, bool isLeft);

private:
  Node *tree = NULL;
  vector<double*> height_vector;
  vector<Node*> width_queue;

};

// конструктор
Tree::Tree() {}

// доавление элемента
bool Tree::append(double elem) {
  bool ok = true;
  if (tree == NULL) {
    tree = new Node;
    tree -> elem = elem;
    tree -> height = 1;
  } else {
    Node *root = tree;
    int height = 1;
    while (true) {
      if (tree -> elem == elem) {
        ok = false;
        break;
      } else if (tree -> elem < elem) {
        if (tree -> right != NULL) {
          tree = tree -> right;
        } else {
          tree -> right = new Node;
          tree -> right -> height = height;
          tree -> right -> elem = elem;
          break;
        }
      } else {
        if (tree -> left != NULL) {
          tree = tree -> left;
        } else {
          tree -> left = new Node;
          tree -> left -> height = height;
          tree -> left -> elem = elem;
          break;
        }
      }
      height++;
    }
    tree = root;
    tree = balance_node(tree);
  }

  if (ok)
    return true;
  else
    return false;
}

// удаление дерева
void Tree::remove_elem(double elem) {
  tree = remove(tree, elem);
}

// балансировка всего дерева
Node* Tree::balance_node(Node *ptr) {
  if (ptr -> left != NULL) {
    ptr -> left = balance_node(ptr -> left);
  }
  if (ptr -> right != NULL) {
    ptr -> right = balance_node(ptr -> right);
  }
  ptr = balance(ptr);
  return ptr;
}

// вернуть указатель дерева
Node* Tree::get_root() {
  return tree;
}

// поиск элемента
Node* Tree::find(double elem) {
  Node* find_elem = tree;
  int steps = 0;
  if (tree != NULL) {
    while (true) {
      steps++;
      if (find_elem -> elem < elem) {
        if (find_elem -> right != NULL) {
          find_elem = find_elem -> right;
        } else break;
      } else if (find_elem -> elem > elem) {
        if (find_elem -> left != NULL) {
          find_elem = find_elem -> left;
        } else break;
      } else {
        cout << "Для поисика потребовалось " << steps << " шагов." << endl;
        return find_elem;
      }
    }
  }
  return NULL;
}

// обход дерева в ширину
void Tree::bfsearch() {
  width_queue.clear();
  width_queue.push_back(tree);

  Node* buf = NULL;
  while (width_queue.size() > 0) {
    buf = width_queue.at(0);
    width_queue.erase(width_queue.begin());
    cout << buf -> elem << " ";

    if (buf -> left)
      width_queue.push_back(buf -> left);

    if (buf -> right)
      width_queue.push_back(buf -> right);
  }

}
//
// // обход дерева (Обратный)
// void Tree::PostOrder(Node* ptr) {
//   if (ptr == NULL) return;
//   PostOrder(ptr -> left);
//   PostOrder(ptr -> right);
//   cout << ptr -> elem << " ";
// }


vector<double*> Tree::get_height() {
  height_vector.clear();
  get_height_recursion(tree, 1);
  return height_vector;
}

// получить листы дерева
void Tree::get_height_recursion(Node* ptr, int height = 1) {
  if (ptr != NULL) {
    if (ptr -> left == NULL && ptr -> right == NULL) {
      double* arr = new double[2];
      arr[0] = ptr -> elem;
      arr[1] = height;
      height_vector.push_back(arr);
    }

    else {
      if (ptr -> left != NULL) get_height_recursion(ptr -> left, height + 1);
      if (ptr -> right != NULL) get_height_recursion(ptr -> right, height + 1);
    }
  }
}

// показать дерево
void Tree::show() {
  print_recursion(tree, NULL, false);
}

// Вспомогательная функция для печати ветвей бинарного дерева
void showTrunks(Trunk *p) {
  if (p == nullptr) {
    return;
  }

  showTrunks(p->prev);
  cout << p->str;
}

// вывод дерева (рекурсивно)
void Tree::print_recursion(Node* ptr, Trunk *prev, bool isLeft) {
  if (ptr != NULL) {
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    print_recursion(ptr->right, trunk, true);

    if (!prev) {
      trunk->str = "———";
    } else if (isLeft) {
      trunk->str = ".———";
      prev_str = "   |";
    } else {
      trunk->str = "`———";
      prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << " " << ptr->elem << endl;

    if (prev) {
      prev->str = prev_str;
    }
    trunk->str = "   |";

    print_recursion(ptr->left, trunk, false);
  }
}
