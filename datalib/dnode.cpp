#include "dnode.h"

template <class T>
DNode<T>::DNode(T nodeEl, DNode<T> *nextDNode) {
    this->currentEl = nodeEl;
    this->nextNode = nextDNode;
}

template <class T>
DNode<T>::DNode(T nodeEl, DNode *nextDNode, DNode *previousDNode) {
    this->currentEl = nodeEl;
    this->nextNode = nextDNode;
    this->previousNode = previousDNode;
}

template <class T>
T DNode<T>::getValue() {
    return currentEl;
}

template <class T>
void DNode<T>::setValue(T newEl) {
    currentEl = newEl;
}


template <class T>
DNode<T> *DNode<T>::getNext() {
    return nextNode;
}

template <class T>
void DNode<T>::setNext(DNode<T> *newNextNode) {
    nextNode = newNextNode;
}

template <class T>
DNode<T>::DNode() {
    this->nextNode = nullptr;
}

template <class T>
DNode<T> *DNode<T>::getPrevious() {
    return previousNode;
}

template <class T>
void DNode<T>::setPrevious(DNode<T> *newPreviousNode) {
    previousNode = newPreviousNode;
}


template
class DNode<string>;
template
class DNode<int>;
