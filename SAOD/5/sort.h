
#include <iostream>
using namespace std;

#define rand_min -10
#define rand_max 10

class Array {
public:
  Array(int, bool, bool);
  ~Array();

  int* sort_arr();
  int* generator();
  void add(int);
  int pop(int);
  void draw(const char* promt);

  int find_el(int);

private:
  int* arr;

  int size;
  bool auto_sort;
  bool random;

};

// конструктор
Array::Array(int Size, bool Auto_sort = true, bool Random = true) {
  size = Size;
  auto_sort = Auto_sort;
  random = Random;

  arr = (int*)malloc(size * sizeof(int));
  if (random) {
    generator();
  } else {
    for (int i = 0; i < size; i++) {
      cout << "Array[" << i << "] = ";
      arr[i] = read_value("", false, false, false);
    }
  }

  draw("Изначальный массив: ");

  if (auto_sort) sort_arr();
}

// деструктор
Array::~Array() {
  free(arr);
}

// вывод массива
void Array::draw(const char* promt = "") {
  cout << promt;
  for (int i = 0; i < size; i++) cout << arr[i] << " ";
  cout << endl;
}

// добавление элемента в массив
void Array::add(int x) {
  arr = (int*)realloc(arr, ++size * sizeof(int));

  arr[size - 1] = x;

  if (auto_sort) sort_arr();
}

int Array::find_el(int x) {
  // for (int i = 0; i < size; i++) {
  //   if (arr[i] == x) return i;
  // }
  // return -1;
  if (x > 0 && x < size)
    return arr[x];
  return 0;
}

// удаление элемента в массиве
int Array::pop(int x) {

  int returned = arr[x];

  int* old_arr = (int*)malloc(size * sizeof(int));
  old_arr = arr;
  arr = (int*)malloc((size - 1) * sizeof(int));

  int i, j = 0;
  for (i = 0; i < size; i++) {
    if (i != x) arr[j++] = old_arr[i];
  }

  size--;
  free(old_arr);

  if (auto_sort) sort_arr();

  return returned;
}

// заполнение массива случайными числами
int* Array::generator() {
  for (int i = 0; i < size; i++) {
    arr[i] = random_int(rand_min, rand_max);
  }
  return arr;
}

// сортировка расчёской
int* Array::sort_arr() {
  int if_count = 0; // количество сравнений
  int swap_count = 0; // количество перестановок

  const double factor = 1.247; // Фактор уменьшения
  double step = size - 1;

  while (step >= 1) {
    for (int i = 0; i + step < size; ++i) {
      if_count++;
      if (arr[i] > arr[(int)(i + step)]) {
        swap_count++;
        swap(arr[i], arr[(int)(i + step)]);
      }
    }
    step /= factor;
  }

  cout << "[Сортировка] " << if_count << " сравнений, " << swap_count << " перестановок" << endl;
  draw("[Сортировка]: ");

  return arr;
}
