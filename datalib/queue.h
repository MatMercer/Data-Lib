#ifndef STACKLIB_QUEUE_H
#define STACKLIB_QUEUE_H


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
};

#endif //STACKLIB_QUEUE_H
