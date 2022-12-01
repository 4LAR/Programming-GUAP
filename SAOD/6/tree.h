#include <iostream>
using namespace std;

// узел дерева
struct Node {
  int elem;     // содержимое узла
  int height;   // высота узла

  // Node *Prev;   // указатель на предка
  Node *Left;   // указатель на меньшего потомка
  Node *Right;  // указатель на большего потомка
};

class Tree {
public:
  Tree();

  void balance();
  void append(int);
  void pop();
  void show();

private:
  Node *tree = NULL;

};

// конструктор
Tree::Tree() {}

// доавление элемента
void Tree::append(int elem) {
  if (tree == NULL) {
    tree = new Node;
    tree -> elem = elem;
  } else {
    cout << "loh" << endl;
  }
}
