// vector::begin/end
#include <iostream>
#include <string>
#include "HashMap.h"

int main () {

    HashMap<int, string> myHashmap;
    for (int i = 0; i < 13; i++)
        myHashmap.add(i, "asdf " + std::to_string(i));
    myHashmap.printf();
}
