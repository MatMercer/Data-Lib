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
    cout << "Select a option: " << endl;
    while (choice != 'q') {
        cout << "A -> Adds a string to the stack." << endl;
        cout << "R -> Removes and return a string from the stack." << endl;
        cout << "Q -> Prints the stack and exit." << endl;
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
                    cout << "Removed the '" + stack.pop() << "' element." << endl;
                }
                else {
                    cout << "The stack is empty!" << endl;
                }

                break;

            case 'q':
            case 'Q':
                cout << endl << "The elements of the stack: " << endl;

                for(int i = stack.top(); i > 0; i--) {
                    cout << i << ". '" << stack.pop() << "' ." << endl;
                }

                cout << "Bye." << endl;

                break;
            default:
                cout << "Invalid choice '" << choice << "'." << endl;
        }
    }
}

// Explicit instantiations of all the templates used in the file
template class Stack<string>;
