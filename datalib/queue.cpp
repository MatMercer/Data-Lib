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
    // TODO: Implement this
    return false;
}

template<class T>
bool Queue<T>::enqueue(T el) {
    // TODO: Implement duplicate data size
    if (!this->full()) {
        // Add the element
        data[bidx] = el;

        // Update the back index, incrementing it
        updateBidx(true);

        // Increments the element count
        elCount += 1;

        return true;
    }

    // If the queue is full
    return false;
}

template<class T>
T Queue<T>::dequeue(){
    // Returns null if can't dequeue
    T el;
    if(!this->empty()) {
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
    if(!this->empty()) {
        return this->data[this->fidx];
    }
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

// TODO: Implement a general function that updates the indexes
//template <class T>
//void Queue<T>::updateIdx(bool frontOrBack);
template <class T>
void Queue<T>::updateBidx(bool increment) {
    if (increment) {
        // Increment the idx
        bidx += 1;
    }
    else {
        // Deincrement idx
        bidx -= 1;
    }

    // If the idx is less than 0, go to the last idx
    if (bidx < 0) {
        bidx = dataSize - 1;
    }
    // If larger than the last idx, go to the first idx (eg 0)
    else if (bidx == dataSize){
        bidx = 0;
    }
}

template <class T>
void Queue<T>::updateFidx(bool increment) {
    if (increment) {
        // Increment the idx
        fidx += 1;
    }
    else {
        // Deincrement idx
        fidx -= 1;
    }

    // If the idx is less than 0, go to the last idx
    if (fidx < 0) {
        fidx = dataSize - 1;
    }
    // If larger than the last idx, go to the first idx (eg 0)
    else if (fidx == dataSize){
        fidx = 0;
    }
}

// Explicit instantiations of all the templates used in the file
template
class Queue<int>;
template
class Queue<string>;
