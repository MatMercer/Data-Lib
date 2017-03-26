#ifndef STACK_LIB_LIBRARY_H
#define STACK_LIB_LIBRARY_H

#include <iostream>

template <class T>
class Stack {
private:
    T *data;
    int max_size;
    int cursor;

public:
    Stack(unsigned int size);

    bool push(T element);
    T pop();
    int size();
    int top();

    bool isEmpty();
    bool isFull();
};


#endif