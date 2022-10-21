
#include <iostream>
using namespace std;

struct Task {
  unsigned int priority; // приоритет
  unsigned int taskTime; // момент поступления
  unsigned int durationTime; // длительность выполнения
};

// вывод стека или очереди
void draw_stack(Task *stack, int size) {
  if (stack != NULL) {
    for (int i = 0; i < size; i++) {
      cout << "Время поступления " << stack[i].taskTime;
      cout << " Приоритет " << stack[i].priority;
      cout << " Такты " << stack[i].durationTime;
      cout << endl;
    }
  } else {
    cout << "Пусто" << endl;
  }
  
}

int get_size_task(Task *stack) {
  return sizeof(stack) / sizeof(Task);
}

// удаление из стека или очереди
Task *pop(Task *stack, Task *out, int *size = 0, bool end = false, bool static_flag = false) {
  Task *buf;
  if (static_flag) {
    if (end) {
      for (int i = (*size); i > 0; i--) {
        if (stack[i] != NULL) {
          (*out) = stack[(*size) - 1];
          stack[(*size) - 1] = None;
          return stack;
        }
      }
      
    }
  } else {
    if (end) {
      (*out) = stack[0];
      stack = (Task*) realloc(stack, ((*size) - 1) * sizeof(Task));

      return stack;

    } else {

    }
  }
}

// добавление в конец стека или очереди
Task *append(Task *stack, Task *buf, int *size = 0, bool static_flag = false) {
  if (static_flag) {
    return stack;
    
  } else {
    // stack = (Task*)malloc(get_size_task() * sizeof(Task));
    if (stack == NULL) {
      stack = (Task*)malloc(sizeof(Task));
      (*size) = 0;
    } else {
      stack = (Task*) realloc(stack, ((*size) + 1) * sizeof(Task));
    }
    int i = (*size);
    stack[i].priority = buf->priority;
    stack[i].taskTime = buf->taskTime;
    stack[i].durationTime = buf->durationTime;

    (*size)++;

    return stack;

  }
}
