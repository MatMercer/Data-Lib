#include <iostream>
#include "../datalib/list.h"

using namespace std;

int main() {
    List<string> list = List(2);

    cout << "This is a test of compilation" << endl;
    return 0;
}

// Explicit instantiations of all the templates used in the file
template class List<int>;

template
template class List<string>;
