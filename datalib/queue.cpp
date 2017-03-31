#include "queue.h"
#include <iostream>

template<class T>
Queue<T>::Queue(int startSize) {
    this->dataSize = startSize;

    // Allocates the array
    this->allocateArray(this->dataSize);
}

template<class T>
bool Queue<T>::duplicateDataSize() {
    // TODO: Implement this
    return false;
}

template<class T>
bool Queue<T>::enqueue(T el) {
    // TODO: Implement duplicate data size
    // TODO: Implement dynamic bindex when there is a free space
    if (!this->full()) {
        // Add the element
        this->data[bidx++] = el;

        // Increments the element count
        elCount += 1;

        return true;
    }

    // If the queue is full
    return false;
}

template<class T>
T Queue<T>::dequeue(){
    if(!this->empty()) {
        this->elCount -= 1;

        return this->[fidx--];
    }
}

template<class T>
T Queue<T>::peek() {
    if(!this->empty()) {
        return this->data[this->fidx];
    }
    return NULL;
}

template <class T>
int Queue<T>::count() {
    return this->elCount;
}

template <class T>
int Queue<T>::queueSize() {
    return this->dataSize;
}

template <class T>
bool Queue<T>::empty() {
    return this->elCount == 0;
}

template <class T>
bool Queue<T>::full() {
    return this->dataSize == this->elCount;
}

template <class T>
T *Queue<T>::allocateArray(int size) {
    return new T[size];
}

// Explicit instantiations of all the templates used in the file
template
class Queue<int>;
