#include <iostream>
using namespace std;

// узел дерева
struct Node {
  double elem;     // содержимое узла
  int height;   // высота узла

  // Node *Prev;   // указатель на предка
  Node *left = NULL;   // указатель на меньшего потомка
  Node *right = NULL;  // указатель на большего потомка
};

#include "balance.h"


class Tree {
public:
  Tree();

  void append(double);
  void remove(Node*, double);
  void pop();
  void show();
  Node *get_root();
  int get_height(Node* ptr);
  Node* balance_node(Node* ptr);
  void print_recursion(string prefix, Node* ptr, bool isLeft);

private:
  Node *tree = NULL;

};

// конструктор
Tree::Tree() {}

// доавление элемента
void Tree::append(double elem) {
  if (tree == NULL) {
    tree = new Node;
    tree -> elem = elem;
    tree -> height = 1;
  } else {
    Node *root = tree;
    int height = 1;
    while (true) {
      if (tree -> elem == elem) {
        break;
      } else if (tree -> elem > elem) {
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
  // show();
}

void Tree::remove(Node *ptr, double elem) {

}

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

Node *Tree::get_root() {
  return tree;
}

int Tree::get_height(Node* ptr) {
  if (ptr != NULL) {
    int left = get_height(ptr -> left);
    int right = get_height(ptr -> right);
    return ((left > right)? left: right) + 1;
  } else {
    return 0;
  }
}

//
void Tree::show() {
  print_recursion("", tree, false);
}

//
void Tree::print_recursion(string prefix, Node* ptr, bool isLeft) {
  if (ptr != NULL) {
    cout << prefix;
    cout << (isLeft ? "├──" : "└──" );
    cout << ptr-> elem << endl;
    print_recursion(prefix + ((isLeft) ? "│  " : "   "), ptr -> left, true);
    print_recursion(prefix + ((isLeft) ? "│  " : "   "), ptr -> right, false);
  }
}
