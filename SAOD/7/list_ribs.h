
#include <iostream>
using namespace std;

#include <vector>
#include <iomanip>

#define TABLE_ELEM_SIZE 4

class List_ribs {
public:
  List_ribs(int, int);

  bool link(int, int, int, int);
  bool check();
  bool check_link(int*);
  void show_list();
  void show_image();
  bool check_loop(int*);
  vector<int*> fill();
private:
  vector<int*> links;
  int width;
  int height;
};

List_ribs::List_ribs(int Width, int Height) {
  width = Width;
  height = Height;
}

bool List_ribs::link(int link_xu, int link_yu, int link_xw, int link_yw) {
  if (((link_xu >= width) || (link_yu >= height) || (link_xw >= width) || (link_yw >= height)) || ((link_xu == link_xw) && (link_yu == link_yw)))
    return false;

  for (int i = 0; i < links.size(); i++) {
    if (links.at(i)[0] == link_xu && links.at(i)[1] == link_yu && links.at(i)[2] == link_xw && links.at(i)[3] == link_yw)
      return false;
  }

  int* arr = new int[4];
  arr[0] = link_xu;
  arr[1] = link_yu;
  arr[2] = link_xw;
  arr[3] = link_yw;

  links.push_back(arr);

  return true;
}

bool List_ribs::check_link(int* link) {
  bool ok;
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      if ((link[0] == x && link[1] == y) || (link[2] == x && link[3] == y)) {
        return true;
      }
    }
  }
  return false;
}

bool List_ribs::check() {
  bool ok;
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      ok = false;
      for (int i = 0; i < links.size(); i++) {
        if ((links.at(i)[0] == x && links.at(i)[1] == y) || (links.at(i)[2] == x && links.at(i)[3] == y)) {
          ok = true;
        }
      }
      if (!ok) return false;
    }
  }
  return true;
}

void List_ribs::show_list() {
  cout << "|" << setw(TABLE_ELEM_SIZE * 2) << "U" << " |" << setw(TABLE_ELEM_SIZE * 2) << "W" << " |" << endl;
  cout << "|" << setw(TABLE_ELEM_SIZE) << "x" << "|" << setw(TABLE_ELEM_SIZE) << "y" << "|";
  cout << setw(TABLE_ELEM_SIZE) << "x" << "|" << setw(TABLE_ELEM_SIZE) << "y" << "|" << endl;
  for (int i = 0; i < links.size(); i++) {
    cout << "|" << setw(TABLE_ELEM_SIZE) << links.at(i)[0];
    cout << "|" << setw(TABLE_ELEM_SIZE) << links.at(i)[1];
    cout << "|" << setw(TABLE_ELEM_SIZE) << links.at(i)[2];
    cout << "|" << setw(TABLE_ELEM_SIZE) << links.at(i)[3] << "|" << endl;
  }
}

bool List_ribs::check_loop(int* list) {
  int* current_list = list;
  bool ok;
  while (true) {
    ok = false;
    for (int i = 0; i < links.size(); i++) {
      if ((list[0] == current_list[2]) && (list[1] == current_list[3])) return true;
      if ((current_list[2] == links.at(i)[0]) && (current_list[3] == links.at(i)[1])) {
        current_list = links.at(i);
        ok = true;
        break;
      }

    }
    if (!ok) return false;
  }
}

vector<int*> List_ribs::fill() {
  vector<int*> fill_list;
  bool ok;
  int* current_list;
  for (int l = 0; l < links.size(); l++) {
    if (check_loop(links.at(l))) {
      current_list = links.at(l);
      fill_list.push_back(current_list);
      ok = true;
      while (ok) {
        ok = false;
        for (int i = 0; i < links.size(); i++) {
          if ((links.at(l)[0] == current_list[2]) && (links.at(l)[1] == current_list[3])) ok = false;
          if ((current_list[2] == links.at(i)[0]) && (current_list[3] == links.at(i)[1])) {
            current_list = links.at(i);
            fill_list.push_back(current_list);
            break;
          }
        }
      }
    }
  }

  return fill_list;
}

void List_ribs::show_image() {
  int** arr = new int*[width];
  int i, j, x, y;
  for (i = 0; i < width; i++) {
    arr[i] = new int[height];
    for (j = 0; j < height; j++)
      arr[i][j] = 0;
  }

  for (i = 0; i < links.size(); i++) {
    arr[links.at(i)[0]][links.at(i)[1]] = 1;
    arr[links.at(i)[2]][links.at(i)[3]] = 1;
  }

  // cout << check_loop(links.at(0)) << endl;
  vector<int*> fill_list = fill();
  for (i = 0; i < fill_list.size(); i++) {
    arr[fill_list.at(i)[0]][fill_list.at(i)[1]] = 2;
  }

  for (x = 0; x < width; x++) {
    for (y = 0; y < height; y++) {
      if (arr[x][y] == 0)
        cout << "░░";

      if (arr[x][y] == 1)
        cout << "▒▒";

      if (arr[x][y] == 2)
        cout << "▓▓";
    }
    cout << endl;
  }
}
