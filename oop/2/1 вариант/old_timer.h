#include <iostream>
using namespace std;

#include <thread>

#include <unistd.h>

#define SECOND 1

class StopWatch {

public:
  StopWatch(int);
  ~StopWatch();

  void set(int);
  void start();
  void stop();
  void show();

private:
  void calculate();

  int seconds = 0;
  bool run = false;

};

// конструктор
StopWatch::StopWatch(int a = 0) {
  seconds = a;
}

// деструктор
StopWatch::~StopWatch() {
  show();
}

// звпутсить таймер
void StopWatch::start() {
  run = true;
  thread thr(&StopWatch::calculate, this);
  thr.join();
}

// остановить таймер
void StopWatch::stop() {
  run = false;
}

// остановить таймер
void StopWatch::set(int a = 0) {
  seconds = a;
}

// отсчёт
void StopWatch::calculate() {
  while (run) {
    show();
    seconds -= 1;
    if (seconds <= 0) stop();

    sleep(SECOND);
    //delay(SECOND);
    //Sleep(SECOND);
  }
}

// вывод значений таймера (оставшейся время)
void StopWatch::show() {
  int d_hours{seconds / 3600};
  int d_minuts{seconds / 60 % 100};
  int d_seconds{seconds % 60};

  d_hours -= d_hours >= 24 ? 24 : 0;
  d_minuts -= d_minuts >= 60 ? 60 : 0;

  cout << d_hours << ":" << d_minuts << ":" << d_seconds << endl;
}
