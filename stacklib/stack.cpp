#include "stack.h"

#include <iostream>

template <class T>
Stack<T>::Stack(unsigned int size) {
    // Cursor not set
    cursor = -1;

    max_size = size;

    // Creates the data array
    data = new T[size];
}

template <class T>
bool Stack<T>::push(T element) {
    // Returns false if the stack is already filled out
    if (this->cursor == max_size) {
        return false;
    }

    // Adds the element to the next position
    data[++cursor] = element;

    return true;
}

template <class T>
T Stack<T>::pop() {
    // Returns NULL if can't pop the element
    if (cursor == -1) {
        return NULL;
    }

    // Returns the previous element
    return data[cursor--];
}

template <class T>
int Stack<T>::top() {
    return cursor + 1;
}

template <class T>
bool Stack<T>::isEmpty() {
    return cursor == -1;
}

template <class T>
bool Stack<T>::isFull() {
    return (cursor == max_size - 1);
}

template <class T>
int Stack<T>::size() {
    return max_size;
}

// Explicit instantiations of all the templates used in the file
template class Stack<std::string>;
