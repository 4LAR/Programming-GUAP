/*
  5 вариант


*/

#include <iostream>
using namespace std;

#include <cmath>
#include <time.h>
#include <iomanip>

/* --------------------------------------------------- */

// длинна списка (это нужно для винды)
int n = 0;

// элемент списка
struct list {
  int a;
  struct list *next = NULL;

};

// создать список
list *create(int a) {

  list *tmp = (list*)malloc(sizeof(list));

  tmp -> a = a;

  tmp -> next = NULL;

  n = 0;
  
  return tmp;
}

// добавить элемент в конец списка
void add_element_end(int a, list *head) {
  list *tmp = (list*)malloc(sizeof(list));
  tmp -> a = a;
  list *p = head;

  for (int i = 0; i < n; i++) {
    p = p -> next;
  }
  p -> next = tmp;

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

// вывести список таблицей
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

// получить среднее арифметическое извсего списка
double get_sr(list *tmp) {
  double sum = 0;
  for (int i = 0; i < n + 1; i++) {
    sum += tmp -> a;
    tmp = tmp -> next;
  }

  return sum / (n + 1);
}

// находим минимальное по формуле
double get_min(list* tmp) {
  double min = 0;
  bool start = true;
  double sr = get_sr(tmp);

  double buf = 0;

  for (int i = 0; i < n + 1; i++) {
    buf = abs((tmp -> a) - sr);
    if ((buf < min) || (start)) {
      min = buf;
      start = false;
    }
  }

  return min;

}

/* --------------------------------------------------- */

int menu() {
  while (true) {
    cout << "1) Добавить элемент в список" << endl;
    cout << "2) Удалить элемент из списока" << endl;
    cout << "0) Выход" << endl;
    int id = read_int(" >>> ");
    if (0 <= id <= 2) {
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
    cout << "Среднее арифметическое: " << get_sr(sequence) << endl;
    cout << "Минимальное по формуле: " << get_min(sequence) << endl;
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
        draw_table(sequence);
        break;

    }

  }
  
	return 0;
}
