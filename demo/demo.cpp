#include <iostream>
#include <iomanip>
#include "../stacklib/stack.h"
using namespace std;

int main() {
    Stack<string> stack = Stack<string>(3);

    // The current choice
    char choice;

    while (choice != 'q') {
        cout << setw(4) << "Test";

        cout << "Your choice: ";
        cin >> choice;
    }
}

// Explicit instantiations of all the templates used in the file
template class Stack<string>;
