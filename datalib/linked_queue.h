#ifndef DATALIB_LINKED_QUEUE_H
#define DATALIB_LINKED_QUEUE_H


#include "node.h"

template<class T>
class LinkedQueue {
private:
    /* First element of the queue */
    Node<T> *head;

    /* Last element of the queue */
    Node<T> *tail;

    /* Element count */
    int elCount;

    /* Returns the last node of the queue */
    Node<T> *lastNode();

public:
    LinkedQueue();

    // Returns true if the element was added
    bool enqueue(T el);

    // Returns null if there is no element to be removed
    T dequeue();

    // Returns null if there is no element
    T peek();

    // Returns elements count
    int count();

    // Returns if it is empty
    bool empty();

    // Prints the queue, used to debug
    void printLinkedQueue();
};

#endif //DATALIB_LINKED_QUEUE_H
