
#include <iostream>
using namespace std;

class My_hash {
public:
    My_hash(const char* Key_example);
    ~My_hash();

    char* generate();

private:
    const char* key_example;
    int size_key;
};

My_hash::My_hash(const char* Key_example) {
    key_example = Key_example;
    size_key = get_size_char((char*)key_example);
}

My_hash::~My_hash() {
    
}

char* My_hash::generate() {
    char* key = (char*) malloc(size_key * sizeof(char));
    for (int i = 0; i < size_key; i++) {
        if (key_example[i] == 'i') key[i] = 48 + rand() % 10;
        if (key_example[i] == 'c') key[i] = 65 + rand() % 26;
    }

    return key;
}