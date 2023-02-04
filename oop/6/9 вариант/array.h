
#include <iostream>
using namespace std;

#include <iomanip>

#define rand_min -10
#define rand_max 10

/*----------------------------------------------------------------------------*/

// генерирует случайное число в диапазоне от A до B
int random_int(int a, int b) {
  return a + (rand() % ( b - a + 1 ) );
}

// Ввод целого числа с проверкой
int read_int(){
	int x;
  while ( (scanf("%d",&x) ) != 1 ) {
    printf("Неверное введенное значение, попробуйте еще: ");
    while(getchar() != '\n');
  }
  return x;
}

/*----------------------------------------------------------------------------*/

class Array {
public:
  Array(int);
  ~Array();

  void generate(bool);
  void show(const char* separator);
  int* get_arr();
  int get_max_abs();
  int get_sum_positive();
  void my_sort();
private:
  int size;
  int *arr;
};

// конструктор
Array::Array(int Size) {
  size = Size;
  arr = (int*) malloc(size * sizeof(int));
  generate(false);
}

// деструктор
Array::~Array() {
  free(arr);
}

// заполенение массива
void Array::generate(bool random = false) {
  if (random) {
    for (int i = 0; i < size; i++) {
      arr[i] = random_int(rand_min, rand_max);
    }
  } else {
    for (int i = 0; i < size; i++) {
      cout << "Array[" << i << "] = ";
      arr[i] = read_int();

      try {
        exception_func(arr[i]);
      }
      catch (MyException &ex) {

        cout << "Число записалось в массив! " << ex.what() <<endl;
        cout << "Число, из-за которого произошла ошибка = " << ex.GetData() <<endl;
      }

    }
  }
}

// вывод массива на экран
void Array::show(const char* separator = " ") {
  for (int i = 0; i < size; i++) {
    cout << setw(4) << arr[i] << separator;
  }
  cout << endl;
}

// возврат массива
int* Array::get_arr() {
  return arr;
}

// максимальный по модулю элемент массива
int Array::get_max_abs() {
  int max_id = 0;
  for (int i = 1; i < size; i++) {
    if (abs(arr[i]) > abs(arr[max_id])) {
      max_id = i;
    }
  }
  return arr[max_id];
}

// сумма элементов массива расположенных между первым и вторым положительным элементами
int Array::get_sum_positive() {
  int sum = 0;
  int first_pos = -1;
  int second_pos = -1;

  for (int i = 0; i < size; i++) {
    if (arr[i] > 0) {
      if (first_pos < 0) {
        first_pos = i;
      } else if (second_pos < 0) {
        second_pos = i;
      } else break;
    }
  }

  if (first_pos < 0)
    throw runtime_error ("В массиве нет положительных элементов.");

  if (second_pos < 0)
    throw runtime_error ("В массиве только 1 положительный элемент.");

  if (second_pos - first_pos < 2)
    throw runtime_error ("Между положительным элементами нет других элементов.");

  for (int i = first_pos + 1; i < second_pos; i++) {
    sum += arr[i];
  }

  return sum;
}

// сортиовка (сначала все числа кроме 0)
void Array::my_sort() {
  int* new_arr = (int*) malloc(size * sizeof(int));
  int j = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] != 0)
      new_arr[j++] = arr[i];
  }

  for (int i = 0; i < size; i++) {
    if (arr[i] == 0)
      new_arr[j++] = arr[i];
  }

  arr = new_arr;
}
