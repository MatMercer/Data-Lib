#include "linked_queue.h"

using namespace std;

template<class T>
LinkedQueue<T>::LinkedQueue() {
    head = new Node<T>();
    tail = head;
    elCount = 0;
}

template<class T>
bool LinkedQueue<T>::enqueue(T el) {
    if (elCount == 0) {
        head->setValue(el);
    } else {
        Node<T> *oldLastNode = tail;
        Node<T> *newLastNode = new Node<T>(el, nullptr);


        oldLastNode->setNext(newLastNode);

        tail = newLastNode;
    }

    elCount += 1;

    return true;
}

template<class T>
T LinkedQueue<T>::dequeue() {
    if (elCount > 0) {
        /* Deletes the old head and stores the value of it */
        T returnedEl = head->getValue();
        delete head;

        if (elCount > 1) {
            /* Assigns a new head if avaible */
            Node<T> *newHead = head->getNext();
            head = newHead;
        }

        elCount--;

        return returnedEl;
    }
    return NULL;
}

template<class T>
T LinkedQueue<T>::peek() {
    if (elCount > 0) {
        return head->getValue();
    }

    return NULL;
}

template<class T>
int LinkedQueue<T>::count() {
    return elCount;
}

template<class T>
bool LinkedQueue<T>::empty() {
    return elCount == 0;
}

template<class T>
void LinkedQueue<T>::printLinkedQueue() {
    if (elCount != 0) {
        int aux = elCount;
        Node<T> *auxNode = head;

        while (aux > 0) {
            cout << auxNode->getValue() << " ";
            aux--;
            auxNode = auxNode->getNext();
        }

        cout << "\n";
    }
}

// Explicit instantiations of all the templates used in the file

template
class LinkedQueue<string>;

template
class Node<string>;
