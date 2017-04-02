#include "queue.h"
#include <iostream>

using namespace std;

template<class T>
Queue<T>::Queue(int startSize) {
    // Sets the start size
    this->dataSize = startSize;

    // Allocates the array
    data = this->allocateArray(this->dataSize);

    bidx = 0;
    fidx = 0;
    elCount = 0;
}

template<class T>
bool Queue<T>::duplicateDataSize() {
    // Creates an array with the double of the latest size
    T *newArray = allocateArray(dataSize * 2);

    // Moves the back index to the last pos of the *new* array
    bidx = dataSize;
    // Assigns all the *used* elements to the new array
    for (int i = fidx; i < bidx; i++) {
        newArray[i] = data[i];
    }

    // Duplicates the datasize
    dataSize *= 2;

    // Deletes the old array
    delete[] data;

    // Assigns the pointer to the new array
    data = newArray;

    return true;
}

template<class T>
bool Queue<T>::enqueue(T el) {
    // Duplicates the data size when full
    if (this->full()) {
        duplicateDataSize();
    }

    // Add the element
    data[bidx] = el;

    // Update the back index, incrementing it
    incrementIdx(&bidx);

    // Increments the element count
    elCount += 1;

    return true;
}

template<class T>
T Queue<T>::dequeue() {
    // Returns null if can't dequeue
    T el;
    if (!this->empty()) {
        el = data[fidx];

        // Increment the front index to the next possible pos
        incrementIdx(&fidx);

        // Decrement the elCount
        this->elCount -= 1;
    }
    return el;
}

template<class T>
T Queue<T>::peek() {
    T el;
    if (!this->empty()) {
        el = this->data[this->fidx];
    }

    return el;
}

template<class T>
int Queue<T>::count() {
    return this->elCount;
}

template<class T>
int Queue<T>::queueSize() {
    return this->dataSize;
}

template<class T>
bool Queue<T>::empty() {
    return this->elCount == 0;
}

template<class T>
bool Queue<T>::full() {
    return this->dataSize == this->elCount;
}

template<class T>
T *Queue<T>::allocateArray(int size) {
    return new T[size];
}

template <class T>
void Queue<T>::incrementIdx(int *value) {
    // Increments the value
    *value += 1;

    // If the value is larger than the data length, it *must* go to zero
    if (*value == dataSize) {
        *value = 0;
    }
}

// Explicit instantiations of all the templates used in the file
template
class Queue<int>;

template
class Queue<string>;
