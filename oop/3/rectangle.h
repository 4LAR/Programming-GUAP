
#include <iostream>
using namespace std; 

class Rectangle {
public:
  Rectangle();
  Rectangle(double, double, double, double);
  ~Rectangle();

  double get_area();
  void info();

  bool operator > (const Rectangle& rectangle_2);
  bool operator < (const Rectangle& rectangle_2);
  bool operator == (const Rectangle& rectangle_2);

  bool operator * (const Rectangle& rectangle);

private:
  double x, y, width, height;

};

// конструктор по умолчанию
Rectangle::Rectangle() {
  x = 0;
  y = 0; 
  width = 10;
  height = 10;
}

// констрктор с параметрами
Rectangle::Rectangle(double X, double Y, double Width, double Height) {
  x = X;
  y = Y;
  width = Width;
  height = Height;
}

Rectangle::~Rectangle() {
  cout << "Деструктор." << endl; 
}

double Rectangle::get_area() {
  return width * height;
}

// вывод информации о треугольнике
void Rectangle::info() {
  cout << "X: " << x << endl;
  cout << "Y: " << y << endl;
  cout << "Ширина: " << width << endl;
  cout << "Высота: " << height << endl;
}

// сравнение
bool operator > (Rectangle& rectangle_1, Rectangle& rectangle_2) {
  return rectangle_1.get_area() > rectangle_2.get_area(); 
}

bool operator < (Rectangle& rectangle_1, Rectangle& rectangle_2) {
  return rectangle_1.get_area() < rectangle_2.get_area(); 
}

bool operator == (Rectangle& rectangle_1, Rectangle& rectangle_2) {
  return rectangle_1.get_area() == rectangle_2.get_area(); 
}

// пересечение
bool Rectangle::operator * (const Rectangle& rectangle) {

  // double x1 = this->x;
  // double x2 = this->x + this->width;
  // double x3 = rectangle.x;
  // double x4 = rectangle.x + rectangle.width;

  // double y1 = this->y;
  // double y2 = this->y + this->height;
  // double y3 = rectangle.y;
  // double y4 = rectangle.y + rectangle.height;

  // double left = std::max(x1, x3);
  // double top = std::min(y2, y4);
  // double right = std::min(x2, x4);
  // double bottom = std::max(y1, y3);

  ////////////////////////////////////////

  // double left = max(this->x + this->height, rectangle.x + rectangle.height);
  // double top = min(this->y + this->width, rectangle.y + rectangle.width);
  // double right = min(this->x + this->width, rectangle.x + rectangle.width);
  // double bottom = max(this->y + this->height, rectangle.y + rectangle.height);

  // double width_buf = right - left;
  // double height_buf = top - bottom;

  // cout << "Площадь пересечения: " << width * height << endl;

  // if (width < 0 || height < 0)
  //   return false;

  // return true;

  ////////////////////////////////////////
  
}