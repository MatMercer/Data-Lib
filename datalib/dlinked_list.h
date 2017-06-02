#ifndef DATALIB_DLINKED_LIST_H
#define DATALIB_DLINKED_LIST_H

#include "dnode.h"

template<class T>
class DLinkedList {
private:
    // List data
    DNode<T> *head;
    DNode<T> *tail;

    // -1 when empty
    int count;

    // Returns the node pointer of the element at i pos, returns the last element if invalid pos
    DNode<T> *elAtPos(int i);

public:
    DLinkedList();

    // Adds a element to an idx
    bool add(int idx, T el);

    // Remove an element from an idx
    T remove(int idx);

    // Update an element in a index
    T update(int idx, T newEl);

    // Is empty?
    bool empty();

    // Print it for me
    void printLinkedList();

    // Insertion sort
    void sort();
};


#endif //DATALIB_DLINKED_LIST_H
