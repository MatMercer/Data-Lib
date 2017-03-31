#include "queue.h"
#include <iostream>

template<class T>
Queue<T>::Queue(int startSize) {
    this->dataSize = startSize;
}

template<class T>
bool Queue<T>::duplicateDataSize() {
    // TODO: Implement this
    return false;
}

template<class T>
bool Queue<T>::enqueue(T el) {
    // TODO: Implement this
    return false;
}

template<class T>
T Queue<T>::dequeue(){
    // TODO: Implement this
    return NULL;
}

template<class T>
T Queue<T>::peek() {
    // TODO: Implement this
    return NULL;
}

template <class T>
int Queue<T>::count() {
    // TODO: Implement this
    return 0;
}

template <class T>
int Queue<T>::queueSize() {
    // TODO: Implement this
    return 0;
}

template <class T>
bool Queue<T>::empty() {
    // TODO: Implement this
    return false;
}

template <class T>
bool Queue<T>::full() {
    // TODO: Implement this
    return false;
}

// Explicit instantiations of all the templates used in the file
template
class Queue<int>;
