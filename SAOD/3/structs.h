
#include <iostream>
using namespace std;

#define size_TaskList 5

struct Task {
  unsigned int name;
  unsigned int priority;
  unsigned int taskTime;
  unsigned int durationTime;
};

struct TaskList {
  Task *taskValues;
  struct TaskList *next = NULL;

};

int get_length_list(TaskList *tmp) {
  int length = 0;
  while (tmp != NULL) {
    length++;
    tmp = tmp -> next;
  }
  return length;
}

TaskList *create(Task *newData) {

  TaskList *tmp = (TaskList*)malloc(sizeof(TaskList));

  tmp -> taskValues = newData;

  tmp -> next = NULL;
  return tmp;
}

bool add_element_end(Task *newData, TaskList *head) {
  int size = get_length_list(head);

  if (size < size_TaskList) {
    TaskList *tmp = (TaskList*)malloc(sizeof(TaskList));
    tmp -> taskValues = newData;
    TaskList *p = head;
    while (p -> next != NULL)
    p = p -> next;
    p -> next = tmp;

    return true;

  } else {
    return false;

  }
}
