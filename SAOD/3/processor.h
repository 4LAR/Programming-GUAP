
#include <iostream>
#include <conio.h>
using namespace std;

// класс реализующий работу 2х процессоров и их логику
class Processors {
public:
  int tick_num = 0;

  Task buf1 = {0, 0, 0};
  int durationTime1 = 0;
  bool run1 = false;
  bool last_sended = false;

  Task buf2 = {0, 0, 0};
  int durationTime2 = 0;
  bool run2 = false;

  Stack *stack;
  int size_stack;
  Stack *queue;
  Generator *generator;

  bool run = true;

  Processors(Stack *stack1, int size_stack1, Stack *queue1, Generator* generator1);
  void tick();
  void loop();
};

// конструктор
Processors::Processors(Stack *stack1, int size_stack1, Stack* queue1, Generator* generator1) {
  stack = stack1;
  size_stack = size_stack1;
  queue = queue1;
  generator = generator1;

  Task buf;
  int count = (size_stack < generator -> get_size())? size_stack: generator -> get_size();
  for (int i = 0; i < count; i++) {
    buf = generator -> get();
    stack -> append(
      buf.priority,
      buf.taskTime,
      buf.durationTime
    );
  }

  run = true;
}

// цикл процессора
void Processors::loop() {
  char c;
  while (run) {
    draw_line();
    tick();

    // 13 Enter
    // 27 escape
    // 8 backspace
    // 32 space
    c = getch();
    if (c == 8) run = false;
  }
}

// итерция процессора
void Processors::tick() {
  tick_num++;
  cout << tick_num << " такт" << endl;

  if ((stack -> get_size() < size_stack) && (generator -> get_size() > 0)) {
    Task buf;
    buf = generator -> get();
    stack -> append(
      buf.priority,
      buf.taskTime,
      buf.durationTime
    );
  }

  if (durationTime1 <= 0) {
    if (run1)
      queue -> append(
        buf1.priority,
        buf1.taskTime,
        buf1.durationTime
      );

    if (stack -> get_size() > 0) {
      buf1 = stack -> pop((stack -> get_size()) - 1);
      durationTime1 = buf1.durationTime;
    } else {
      buf1 = {0, 0, 0};
    }
  }

  if (durationTime2 <= 0) {
    if (queue -> get_size() > 0) {
      buf2 = queue -> pop(0);
      durationTime2 = buf2.durationTime;
    } else {
      buf2 = {0, 0, 0};
    }
  }

  // работа 1 процессора
  if ((durationTime1 > 0)) {
    run1 = true;
    durationTime1 -= 1;
  } else {
    run1 = false;
  }

  // работа 2 процессора
  if ((durationTime2 > 0)) {
    run2 = true;
    durationTime2 -= 1;
  } else {
    run2 = false;
  }

  if ((stack -> get_size() <= 0) && (queue -> get_size() <= 0) && !run1 && !run2)
    run = false;

  cout << "Процессор 1: ";
  draw_task(buf1, durationTime1);

  cout << "Процессор 2: ";
  draw_task(buf2, durationTime2);

  cout << "Стек:" << endl;
  draw_stack(stack -> get_all(), stack -> get_size());
  cout << "Очередь:" << endl;
  draw_stack(queue -> get_all(), queue -> get_size());

}
