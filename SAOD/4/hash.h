
#include <iostream>
using namespace std;

#include <cstdio>

struct hash_struct {
  int hash;
  char* key;
};

class My_hash {
public:
  My_hash(const char* Key_example, int Size_key, int Count_sigments);
  ~My_hash();

  int hash(char*);
  char* generate(bool);

  void draw_hash_list();
  void clear_hash_list();

  bool chek_key(char*);

  bool find_by_hash(int);
  bool find_by_key(char*);

  void export_to_file(char*);

private:
  void append_list(char*);

  const char* key_example;
  int size_key;

  int count_sigments;

  int size_list = 0;
  hash_struct* hash_list;
};

My_hash::My_hash(const char* Key_example, int Size_key, int Count_sigments = 2000) {
  key_example = Key_example;
  // size_key = get_size_char((char*)key_example);
  size_key = Size_key;
  hash_list = (hash_struct*)malloc(sizeof(hash_struct));

  count_sigments = Count_sigments;
}

My_hash::~My_hash() {
  free(hash_list);
}

int My_hash::hash(char* key) {
  int value = 1;
  for (int i = 0; i < size_key; i++) {
    value += (int)key[i] * (int)key[i];
  }
  return (value % count_sigments);
}

char* My_hash::generate(bool random = true) {
  char* key = (char*) malloc(size_key * sizeof(char));
  int length;
  while (true) {
    if (random) {
      for (int i = 0; i < size_key; i++) {
        if (key_example[i] == 'i') key[i] = 48 + rand() % 10;
        if (key_example[i] == 'c') key[i] = 65 + rand() % 26;
      }
    } else {
      while (true) {
        cout << "Введите ключ формата " << key_example << ": ";
        key = get_string(&length);

        if (length != size_key || !chek_key(key)) {
          cout << "ключ не соответствует формату." << endl;
        } else break;
      }

    }
    if (!find_by_key(key)) break;
  }

  append_list(key);

  return key;
}

bool My_hash::chek_key(char* key) {
  for (int i = 0; i < size_key; i++) {
    if (key_example[i] == 'i' && !(key[i] >= 48 && key[i] <= 57)) {return false;}
    if (key_example[i] == 'c' && !(toupper(key[i]) >= 65 && toupper(key[i]) <= 90)) {return false;}
  }
  return true;
}

void My_hash::append_list(char* key) {
  hash_list = (hash_struct*)realloc(hash_list, (++size_list) * sizeof(hash_struct));
  hash_list[size_list -1].key = (char*) malloc(size_key * sizeof(char));
  hash_list[size_list -1].key = key;
  // cout << hash_list[size_list -1].key << endl;

  int hash_bool = hash(key);
  while (true) {
    if (!find_by_hash(hash_bool)) {
      hash_list[size_list -1].hash = hash_bool;
      break;
    }
    hash_bool++;
  }

}

bool My_hash::find_by_hash(int hash) {
  for (int i = 0; i < size_list; i++) {
    if (hash == hash_list[i].hash) {
      // cout << "1" << endl;
      return true;
    }
  }
  return false;
}

bool My_hash::find_by_key(char* key) {
  for (int i = 0; i < size_list; i++) {
    if (key == hash_list[i].key) {
      // cout << "2" << endl;
      return true;
    }
  }
  return false;
}

void My_hash::clear_hash_list() {
  hash_list = (hash_struct*)malloc(sizeof(hash_struct));
  size_list = 0;
}

void My_hash::draw_hash_list() {
  for (int i = 0; i < size_list; i++) {
    cout << i << " " << hash_list[i].hash << " ";
    draw_char_array(hash_list[i].key, size_key);
    //cout << hash_list[i].key;
    cout << endl;
  }
}

void My_hash::export_to_file(char* file_name) {
  FILE *output_file;

  output_file = fopen(file_name, "w");

  for (int i = 0; i < size_list; i++) {
    fprintf(output_file, "%d %d ", i, hash_list[i].hash);
    for (int j = 0; j < size_key; j++)
      fprintf(output_file, "%c", hash_list[i].key[j]);
    //fprintf(output_file, "%s", hash_list[i].key);
    fprintf(output_file, "\n");
  }

  fclose(output_file);
}
