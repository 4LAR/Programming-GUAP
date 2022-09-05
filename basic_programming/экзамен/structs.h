
#include <iostream>
using namespace std;

struct list {
    char *slovo;
    int size;
    struct list *next = NULL;

};

list *create(char *num, int size) {

    list *tmp = (list*)malloc(sizeof(list));

    tmp -> slovo = num;
    tmp -> size = size;

    tmp -> next = NULL;
    return tmp;
}

void add_element_end(char *num, int size, list *head) {
    list *tmp = (list*)malloc(sizeof(list));
    tmp -> slovo = num;
    tmp -> size = size;
    list *p = head;
    while (p -> next != NULL)
    p = p -> next;
    p -> next = tmp;

}

void draw_list(list *number_list, int type) {
    while (number_list != NULL){
        if (number_list -> size != -1)
            cout << number_list -> slovo << endl;
            //draw_str(number_list -> slovo, number_list -> size, type);
        number_list = number_list -> next;
  }
}