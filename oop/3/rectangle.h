
#include <iostream>
using namespace std;

class Rectangle {
public:
  Rectangle();
  Rectangle(double, double, double, double);
  ~Rectangle();

  double get_area();
  void info();

  friend bool operator > (const Rectangle& rectangle_1, const Rectangle& rectangle_2);
  friend bool operator < (const Rectangle& rectangle_1, const Rectangle& rectangle_2);
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
  return(
    (
      (
        ( (this->x)>=(rectangle.x) && (this->x)<=(rectangle.x + rectangle.width) )||( (this->x + this->width)>=(rectangle.x) && (this->x + this->width)<=(rectangle.x + rectangle.width)  )
      ) && (
        ( (this->y)>=(rectangle.y) && (this->y)<=(rectangle.y + rectangle.height) )||( (this->y + this->height)>=(rectangle.y) && (this->y + this->height)<=(rectangle.y + rectangle.height) )
      )
    )||(
      (
        ( (rectangle.x)>=(this->x) && (rectangle.x)<=(this->x + this->width) )||( (rectangle.x + rectangle.width)>=(this->x) && (rectangle.x + rectangle.width)<=(this->x + this->width)  )
      ) && (
        ( (rectangle.y)>=(this->y) && (rectangle.y)<=(this->y + this->height) )||( (rectangle.y + rectangle.height)>=(this->y) && (rectangle.y + rectangle.height)<=(this->y + this->height) )
      )
    )
  )||(
    (
      (
        ( (this->x)>=(rectangle.x) && (this->x)<=(rectangle.x + rectangle.width) )||( (this->x + this->width)>=(rectangle.x) && (this->x + this->width)<=(rectangle.x + rectangle.width)  )
      ) && (
        ( (rectangle.y)>=(this->y) && (rectangle.y)<=(this->y + this->height) )||( (rectangle.y + rectangle.height)>=(this->y) && (rectangle.y + rectangle.height)<=(this->y + this->height) )
      )
    )||(
      (
        ( (rectangle.x)>=(this->x) && (rectangle.x)<=(this->x + this->width) )||( (rectangle.x + rectangle.width)>=(this->x) && (rectangle.x + rectangle.width)<=(this->x + this->width)  )
      ) && (
        ( (this->y)>=(rectangle.y) && (this->y)<=(rectangle.y + rectangle.height) )||( (this->y + this->height)>=(rectangle.y) && (this->y + this->height)<=(rectangle.y + rectangle.height) )
      )
    )
  );

}
