#include <iostream>
#include "../stacklib/stack.h"
using namespace std;

int main() {
    Stack<string> stack = Stack<string>(3);

    // The current choice
    char choice;

    // The current added string
    string addStr;

    cout << "The current max size of the stack is " << stack.size() << "." << endl;
    while (choice != 'q') {
        cout << "There are " << stack.top() << " elements at the stack." << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch(choice) {
            case 'a':
            case 'A':
                if (!stack.isFull()) {
                    cout << "Insert a string: ";
                    cin >> addStr;
                    stack.push(addStr);
                }
                else {
                    cout << "The stack is full!" << endl;
                }

                break;

            case 'r':
            case 'R':
                if (!stack.isEmpty()) {
                    cout << "Removed the '" + stack.pop(addStr) << "' element." << endl;
                }
                else {
                    cout << "The stack is empty!" << endl;
                }

                break;
            default:
                cout << "Invalid choice '" << choice << "'." << endl;
        }
    }
}

// Explicit instantiations of all the templates used in the file
template class Stack<string>;
