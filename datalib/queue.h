#ifndef STACKLIB_QUEUE_H
#define STACKLIB_QUEUE_H

#include <iostream>

using namespace std;


template<class T>
class Queue {
private:
    // Front index
    int fidx;
    // Back index
    int bidx;
    // Element count in the current queue
    int elCount;

    // Current data size
    int dataSize;
    // Data array
    T *data;

    // Returns true if it was possible to allocate the memory
    bool duplicateDataSize();

    // Returns a pointer of T with the given size
    T *allocateArray(int size);

    // Dynamic update of the indexes, forming a "circular array"
    void updateBidx(bool increment);

    void updateFidx(bool increment);

    // Dynamically increments a index, looping it out
    void incrementIdx(int *value);

public:
    Queue(int startSize);

    // Returns true if the element was added
    bool enqueue(T el);

    // Returns null if there is no element to be removed
    T dequeue();

    // Returns null if there is no element
    T peek();

    // Returns elements count
    int count();

    // Returns the data size
    int queueSize();

    // Returns if it is empty
    bool empty();

    // Returns if it is full
    bool full();

    // Prints the queue, used to debug
    void printQueue();
};

#endif //STACKLIB_QUEUE_H
