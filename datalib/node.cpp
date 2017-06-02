#include "node.h"

template <class T>
Node<T>::Node(T nodeEl, Node<T> *nextNode) {
    this->currentEl = nodeEl;
    this->nextNode = nextNode;
}

template <class T>
T Node<T>::getValue() {
    return currentEl;
}

template <class T>
void Node<T>::setValue(T newEl) {
    currentEl = newEl;
}


template <class T>
Node<T> *Node<T>::getNext() {
    return nextNode;
}

template <class T>
void Node<T>::setNext(Node<T> *newNextNode) {
    nextNode = newNextNode;
}

template <class T>
Node<T>::Node() {
    this->nextNode = nullptr;
}

template
class Node<string>;
template
class Node<int>;
