#include <iostream>
#include <ctime>
using namespace std;

class StopWatch {

public:
  StopWatch();
  StopWatch(double);
  StopWatch(const StopWatch & ref_StopWatch);
  ~StopWatch();

  void start();
  void stop();
  void show(const char*);

private:
  clock_t start_time;
  clock_t stop_time;

  double delta_sec;

  clock_t create_time;
  clock_t delete_time;
  bool run;

};

// конструктор по умолчанию
StopWatch::StopWatch() {
  run = false;

  delta_sec = 0;
  time(&create_time);

}

// конструктор с дельтой
StopWatch::StopWatch(double delta) {
  run = false;

  delta_sec = delta;
  time(&create_time);

}

// конструктор копирования
StopWatch::StopWatch(const StopWatch & ref_StopWatch) {
  cout << "Класс скопирован." << endl;
  start_time  = ref_StopWatch.start_time;
  stop_time   = ref_StopWatch.stop_time;

  delta_sec   = ref_StopWatch.delta_sec;

  create_time = ref_StopWatch.create_time;
  delete_time = ref_StopWatch.delete_time;

  run = ref_StopWatch.run;
}

// деструктор
StopWatch::~StopWatch() {
  time(&delete_time);
  cout << "Время существования таймера: " << difftime(delete_time, create_time) << endl;
}

// запустить таймер
void StopWatch::start() {
  if (!run) {
    run = true;
    time(&start_time);
  }
}

// остановить таймер
void StopWatch::stop() {
  if (run) {
    run = false;
    time(&stop_time);
  }
}

// вывод значений таймера (оставшейся время)
void StopWatch::show(const char *promt) {
  if (run) time(&stop_time);
  cout << promt << difftime(stop_time, start_time) + delta_sec << "сек." << endl;
}
