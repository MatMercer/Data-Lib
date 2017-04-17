#include <iostream>
#include "../datalib/list.h"

using namespace std;

int main() {
    List<int> list = List<int>(2);

    for (int i = 0; i < 1000; i++) {
        list.add(i, i * 2);
    }

    return 0;
}

// Explicit instantiations of all the templates used in the file
template class List<int>;
template class List<string>;
