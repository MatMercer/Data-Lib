#include "queue.h"

using namespace std;

template<class T>
Queue<T>::Queue(int startSize) {
    // Sets the start size
    this->dataSize = startSize;

    // Allocates the array
    data = this->allocateArray(this->dataSize);

    fidx = 0;
    bidx = -1;
    elCount = 0;
}

template<class T>
bool Queue<T>::duplicateDataSize() {
    // Creates an array with the double of the latest size
    T *newArray = allocateArray(dataSize * 2);

    int i = fidx;
    int j = 0;
    while (j != elCount) {
        newArray[j] = data[i];
        incrementIdx(&i);
        j += 1;
    }

    // Send the back idx to the last right pos and the fidx to the first post
    fidx = 0;
    bidx = elCount - 1;

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

    // Update the back index, incrementing it
    incrementIdx(&bidx);

    // Add the element
    data[bidx] = el;

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

template<class T>
int Queue<T>::incrementIdx(int *value) {
    // Increments the value
    *value += 1;

    // If the value is larger than the data length, it *must* go to zero
    if (*value == dataSize) {
        *value = 0;
    }

    return *value;
}

template<class T>
void Queue<T>::printQueue() {
    if (!this->empty()) {
        int i = fidx;
        int j = 0;
        while (j != this->elCount) {
            cout << " | " << data[i] << " | ";
            incrementIdx(&i);
            j += 1;
        }
    }

    cout << endl;
}

// Explicit instantiations of all the templates used in the file
template
class Queue<int>;

template
class Queue<string>;
