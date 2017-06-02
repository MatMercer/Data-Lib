#ifndef DATALIB_DNODE_H
#define DATALIB_DNODE_H

#include <iostream>

using namespace std;

template<class T>
class DNode {
private:
    /* Current element of this node */
    T currentEl;

    /* Pointer to the next node */
    DNode<T> *nextNode;

    /* Pointer to the previous node */
    DNode<T> *previousNode;
public:
    /* Receives the current element and the next node pointer */
    DNode(T nodeEl, DNode<T> *nextDNode);

    DNode(T nodeEl, DNode<T> *nextDNode, DNode<T> *previousDNode);

    DNode();

    /* Returns current element value */
    T getValue();

    /* Sets current element value */
    void setValue(T newEl);

    /* Returns the next pointed node object, null if not pointed */
    DNode<T> *getNext();

    /* Sets the next pointed node object pointer */
    void setNext(DNode<T> *newNextDNode);

    /* Returns the next pointed node object, null if not pointed */
    DNode<T> *getPrevious();

    /* Sets the next pointed node object pointer */
    void setPrevious(DNode<T> *newPreviousNode);

};

#endif //DATALIB_NODE_H
