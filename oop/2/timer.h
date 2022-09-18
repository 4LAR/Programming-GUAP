#include <iostream>
#include <ctime>
using namespace std;

class StopWatch {

public:
  StopWatch();
  ~StopWatch();

  void start();
  void stop();
  void show(const char*);

private:
  int seconds;
  clock_t start_time;
  clock_t stop_time;

  clock_t create_time;
  clock_t delete_time;
  bool run;

};

// конструктор
StopWatch::StopWatch() {
  seconds = 0;
  run = false;

  time(&create_time);

}

// деструктор
StopWatch::~StopWatch() {
  time(&delete_time);
  cout << "Время существования таймера: " << difftime(delete_time, create_time) << endl;
}

// звпутсить таймер
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
  cout << promt << difftime(stop_time, start_time) << endl;
}
