#include <iostream>
#include <ctime>

using namespace std;

int get_now_year() {
  time_t now = time(0);

  tm *ltm = localtime(&now);
  return (1900 + ltm -> tm_year);
}
