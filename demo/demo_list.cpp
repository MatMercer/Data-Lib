#include <iostream>
#include "../datalib/list.h"

using namespace std;

int main() {
    List<int> list = List<int>(2);

    for (int i = 1; i <= 10; i++) {
        list.add(i - 1, i * 2);
    }

    cout << "Current list:" << endl;
    list.printList();


    list.add(5, -1);
    cout << "Current list with -1 added to index 5:" << endl;
    list.printList();

    list.add(7, -1);
    cout << "Current list with -1 added to index 7:" << endl;
    list.printList();

    for (int i = 3; i < 6; i++) {
        list.add(i, -7);
    }
    cout << "Added three -7 elements with the 4 index as a start..." << endl;
    list.printList();

    list.add(0, 99);
    cout << "Current list with 99 added to index 0:" << endl;
    list.printList();

    list.addSorted(-3);
    cout << "Current list with -3 added in a sorted way:" << endl;
    list.printList();

    return 0;
}

// Explicit instantiations of all the templates used in the file
template
class List<int>;

template
class List<string>;
