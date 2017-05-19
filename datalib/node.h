#ifndef DATALIB_NODE_H
#define DATALIB_NODE_H

#include <iostream>

using namespace std;

template<class T>
class Node {
private:
    /* Current element of this node */
    T currentEl;

    /* Pointer to the new node */
    Node<T> *nextNode;
public:
    /* Receives the current element and the next node pointer */
    Node(T nodeEl, Node<T> *nextNode);

    Node();

    /* Returns current element value */
    T getValue();

    /* Sets current element value */
    void setValue(T newEl);

    /* Returns the next pointed node object, null if not pointed */
    Node<T> *getNext();

    /* Sets the next pointed node object pointer */
    void setNext(Node<T> *newNextNode);
};

#endif //DATALIB_NODE_H
