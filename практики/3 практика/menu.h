#include <iostream>
using namespace std;

void draw_text_for_menu() {
    cout << "0 - Выход" << endl;
    cout << endl;
    cout << "1 - Пирамида" << endl;
    cout << "2 - Квадрат" << endl;
    cout << "3 - стрелка" << endl;
    cout << "4 - нарисовать всё" << endl;
}

void menu() {
    int width, height;

    bool run = true;
    while (run) {
      draw_text_for_menu();
      int menu_select;
      while (true) {
          menu_select = read_value(" >> ", false, false, false);
          if (5 > menu_select && 0 <= menu_select) {
            break;
          } else {
            cout << "Такого пункта в меню нет." << endl;
          }
      }
      
      draw_line(20);
      switch(menu_select) {
        case(0):
          run = false;
          break;
        case(1):
          triangle(
            read_value("Высота пирамиды: ", false, false, false)
          );
          break;
        case(2):
          square(
            read_value("Ширина квадрата: ", false, false, false),
            read_value("Высота квадрата: ", false, false, false)
          );
          break;
        case(3):
          arrow(
            read_value("Высота наконечкника: ", false, false, false),
            read_value("Высота палки: ", false, false, false)
          );
          break;
        case(4):
          triangle(10);
          draw_line(20);
          square(10, 10);
          draw_line(20);
          arrow(3, 6);
          break;
        }
        draw_line(20);
    }
}
