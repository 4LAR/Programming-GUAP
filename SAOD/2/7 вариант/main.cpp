/*
  7 вариант


*/

#include <iostream>
using namespace std;

#include <cmath>
#include <time.h>
#include <iomanip>

/* --------------------------------------------------- */

// длинна списка
int n = 0;

// элемент списка
struct list {
  int a; // значение
  struct list *next = NULL; // указатель на следующий элемент
  struct list *back = NULL; // указатель на предыдущий элемент

};

// создать список (голову)
list *create(int a) {

  list *tmp = (list*)malloc(sizeof(list));

  tmp -> a = a;

  tmp -> next = NULL;
  tmp -> back = NULL;

  n = 0;

  return tmp;
}

// добавить элемент в конец списка
void add_element_end(int a, list *head) {
  list *tmp = (list*)malloc(sizeof(list));
  tmp -> a = a;
  list *p = head;
  list *back = NULL;

  for (int i = 0; i < n; i++) {
    back = p;
    p = p -> next;
  }
  p -> next = tmp;
  p -> back = back;

  n++;
}

// удаление элемента из спика
list *del_element(list *tmp, int id) {
  list* new_list = NULL;

  int length = n;

  for (int i = 0; i < length + 1; i++) {
    if (i != id) {
      if (new_list == NULL) {
        new_list = create(tmp -> a);
      } else {
        add_element_end(tmp -> a, new_list);
      }
    }
    tmp = tmp -> next;
  }
  return new_list;
}

/* --------------------------------------------------- */

// вывести список (в строку)
void draw_list(list *tmp) {

  for (int i = 0; i < n + 1; i++) {
    cout << tmp -> a << setw(3);
    tmp = tmp -> next;
  }
  cout << endl;

}

// вывести список (таблицей)
void draw_table(list *tmp) {

  cout << "| ID | A  |\n";

  for (int i = 0; i < n + 1; i++) {
    cout << "| " << setw(3) << i;
    cout << "| " << setw(3) << tmp -> a;
    cout << "|" << endl;
    tmp = tmp -> next;
  }

}

// проверка ввода (чисто для вида)
int read_int(const char* promt="") {
	int x;
  cout << promt;
  while ( (scanf("%d",&x) ) != 1 ) {
    printf("Неверное введенное значение, попробуйте еще: ");
    while(getchar() != '\n');
  }
  return x;
}

// сортировка списка
void sort_list(list *head) {
  list* p_i = head;
  list* p_j = head;

  int temp;
  for (int i = 0; i < n - 1; i++) {
    p_i = head;
    p_j = head;
    for (int j = 0; j < n - i; j++) {
      p_j = p_j -> next;
      if (p_i -> a > p_j -> a) {
        // меняем элементы местами
        temp = p_i -> a;
        p_i -> a = p_j -> a;
        p_j -> a = temp;
      }
      p_i = p_i -> next;
    }
  }

}

/* --------------------------------------------------- */

int menu() {
  while (true) {
    cout << "1) Добавить элемент в список" << endl;
    cout << "2) Удалить элемент из списока" << endl;
    cout << "3) Сортировать список (задание)" << endl;
    cout << "0) Выход" << endl;
    int id = read_int(" >>> ");
    if (0 <= id <= 3) {
      return id;

    } else {
      cout << "Этого нет в меню" << endl;

    }
  }

}

/* --------------------------------------------------- */

int main() {

  list* sequence = NULL;

	// смена кодировки
  system("chcp 65001");

  // вводим размер списка
  int length = read_int("Введите N: ");

  int a = 0;
  for (int i = 0; i < length; i++) {
    cout << "A(" << i << "):";
    a = read_int();
    if (sequence == NULL) {
      sequence = create(a);
    } else {
      add_element_end(a, sequence);
    }
  }

  int id;
  int menu_i;
  while (true) {
    draw_list(sequence);
    menu_i = menu();

    switch (menu_i) {
      case (0):
        return 0;
        break;

      case (1):
        a = read_int("a: ");
        add_element_end(a, sequence);
        draw_table(sequence);
        break;

      case (2):
        draw_table(sequence);
        id =  read_int("ID: ");
        sequence = del_element(sequence, id);
        break;

      case (3):
        sort_list(sequence);
        break;
    }
  }

	return 0;
}
