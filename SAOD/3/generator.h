#include <iostream>
using namespace std;

// генератор задач
class Generator {
public:
  Stack *list = new Stack(-1);

  Generator(int count, bool Auto_flag);
  ~Generator();
  Task get();
  int get_size();

};

// конструктор
Generator::Generator(int Count, bool Auto_flag = true) {
  if (Auto_flag) {
    for (int i = 0; i < Count; i++) {
      list -> append(
        random_int(1, 3),
        i + 1,
        random_int(1, 3)
      );
    }
  } else {
    Count = read_value("Количество задач: ", false, false, false);

    unsigned int priority;
    unsigned int taskTime;
    unsigned int durationTime;

    for (int i = 0; i < Count; i++) {
      cout << "Задача " << i << endl;

      priority = read_value("Приоритет: ", false, false, false);
      taskTime = read_value("Момент поступления: ", false, false, false);
      durationTime = read_value("Длительность выполнения: ", false, false, false);

      list -> append(
        priority,
        taskTime,
        durationTime
      );
    }
  }


  //draw_stack(list -> get_all(), list -> get_size());
}

// деструктор
Generator::~Generator() {
  delete list;
}

// получить элемент (после получения он удаляется)
Task Generator::get() {
  return list -> pop(list -> get_size() - 1);
}

// получить текущий размер
int Generator::get_size() {
  return list -> get_size();
}
