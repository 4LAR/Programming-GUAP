#include <iostream>
using namespace std;

int count_generated_tasks = 0;

Task *generate_task() {
  Task *buf;

  buf->priority = random_int(0, 3);
  buf->taskTime = ++count_generated_tasks;
  buf->durationTime = random_int(1, 3);
  
  return buf;
}