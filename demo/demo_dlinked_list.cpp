#include <iostream>
#include "../datalib/dlinked_list.h"

using namespace std;

int main() {
    DLinkedList<int> list = DLinkedList<int>();

    for (int i = 1; i <= 10; i++) {
        list.add(i - 1, i * 2);
    }

    cout << "Current list:" << endl;
    list.printLinkedList();


    list.add(5, -1);
    cout << "Current list with -1 added to index 5:" << endl;
    list.printLinkedList();

    list.add(7, -1);
    cout << "Current list with -1 added to index 7:" << endl;
    list.printLinkedList();

    for (int i = 3; i < 6; i++) {
        list.add(i, -7);
    }
    cout << "Added three -7 elements with the 4 index as a start..." << endl;
    list.printLinkedList();

    list.add(0, 99);
    cout << "Current list with 99 added to index 0:" << endl;
    list.printLinkedList();

    return 0;
}

// Explicit instantiations of all the templates used in the file
template class DLinkedList<int>;
template class DLinkedList<string>;
