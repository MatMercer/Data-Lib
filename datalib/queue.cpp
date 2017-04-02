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
    updateBidx(true);

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
        updateFidx(true);

        // Decrement the elCount
        this->elCount -= 1;
    }
    return el;
}

template<class T>
T Queue<T>::peek() {
    if (!this->empty()) {
        return this->data[this->fidx];
    }
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

// TODO: Implement a general function that updates the indexes
//template <class T>
//void Queue<T>::updateIdx(bool frontOrBack);
template<class T>
void Queue<T>::updateBidx(bool increment) {
    if (increment) {
        // Increment the idx
        bidx += 1;
    } else {
        // Deincrement idx
        bidx -= 1;
    }

    // If the idx is less than 0, go to the last idx
    if (bidx < 0) {
        bidx = dataSize - 1;
    }
        // If larger than the last idx, go to the first idx (eg 0)
    else if (bidx == dataSize) {
        bidx = 0;
    }
}

template<class T>
void Queue<T>::updateFidx(bool increment) {
    if (increment) {
        // Increment the idx
        fidx += 1;
    } else {
        // Deincrement idx
        fidx -= 1;
    }

    // If the idx is less than 0, go to the last idx
    if (fidx < 0) {
        fidx = dataSize - 1;
    }
        // If larger than the last idx, go to the first idx (eg 0)
    else if (fidx == dataSize) {
        fidx = 0;
    }
}

// Explicit instantiations of all the templates used in the file
template
class Queue<int>;

template
class Queue<string>;
