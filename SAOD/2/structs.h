
#include <iostream>
using namespace std;

struct list {
    int n;
    int a;
    struct list *next = NULL;

};

list *create(int n, int a) {

    list *tmp = (list*)malloc(sizeof(list));

    tmp -> n = n;
    tmp -> a = a;

    tmp -> next = NULL;
    return tmp;
}

void add_element_end(int n, int a, list *head) {
    list *tmp = (list*)malloc(sizeof(list));
    tmp -> n = n;
    tmp -> a = a;
    list *p = head;
    while (p -> next != NULL)
    p = p -> next;
    p -> next = tmp;

}

void draw_list(list *number_list) {
    while (number_list != NULL){
        cout << number_list -> n << "|" << number_list -> a << endl;
        number_list = number_list -> next;
  }
}
