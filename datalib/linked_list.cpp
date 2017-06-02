#include "linked_list.h"

template<class T>
LinkedList<T>::LinkedList() {
    count = -1;
}

template<class T>
bool LinkedList<T>::add(int idx, T el) {
    if (empty()) {
        /* Empty list? Just make a new head and tail */
        head = new Node<T>(el, nullptr);
        tail = head;
    } else if (idx == 0) {
        /* Add it as a new head */
        Node<T> *newHead = new Node<T>(el, head);
        head = newHead;
    } else if (idx > count) {
        /* Add to the last part of the list */
        Node<T> *newTail = new Node<T>(el, nullptr);
        tail->setNext(newTail);
        tail = newTail;
    } else if (idx < count && idx > 0) {
        /* Take the elements that are on the left and right of the new el */
        Node<T> *rightEl = elAtPos(idx);
        Node<T> *leftEl = elAtPos(idx - 1);

        /* Pad the element and add the new one */
        Node<T> *newEl = new Node<T>(el, rightEl);
        leftEl->setNext(newEl);
        newEl->setNext(rightEl);
    } else {
        /* Invalid pos */
        cerr << "Tried to add an element at invalid index '" << idx << "'. The current list have " << count + 1
             << " elements." << endl;
        return false;
    }

    /* Continue the count */
    count += 1;

    return true;
}

template<class T>
T LinkedList<T>::remove(int idx) {
    T foundEl;

    if (empty()) {
        /* Empty list? Can't do it.. */
        cerr << "You tried to remove an element from an empty list!" << endl;
        return NULL;
    } else if (idx == 0) {
        /* Gets the head value & delete it */
        Node<T> *oldHead = head;
        foundEl = oldHead->getValue();

        /* Sets the new head when possible */
        if (count > 0) {
            head = oldHead->getNext();
        }

        delete oldHead;
    } else if (idx >= count) {
        /* Gets the tail value & delete it */
        foundEl = tail->getValue();
        delete tail;

        /* Sets the new tail when possible */
        if (count > 0) {
            tail = elAtPos(count - 1);
            tail->setNext(nullptr);
        }

    } else if (idx < count && idx > 0) {
        /* Take the elements that are on the left and right of the old el */
        Node<T> *rightEl = elAtPos(idx + 1);
        Node<T> *middleEl = elAtPos(idx);
        Node<T> *leftEl = elAtPos(idx - 1);

        /* Change the pointers */
        leftEl->setNext(rightEl);

        /* Get the middle el value & deletes it */
        foundEl = middleEl->getValue();
        delete middleEl;
    } else {
        /* Invalid pos */
        cerr << "Tried to remove an element at invalid index '" << idx << "'. The current list have " << count + 1
             << " elements.";
        return NULL;
    }

    /* Updates the count */
    count -= 1;

    return foundEl;
}

template<class T>
bool LinkedList<T>::empty() {
    return count == 0;
}

template<class T>
void LinkedList<T>::printLinkedList() {
    if (!empty()) {
        int aux = count;
        Node<T> *auxNode = head;

        while (aux > 0) {
            cout << auxNode->getValue() << " ";
            aux--;
            auxNode = auxNode->getNext();
        }

        cout << "\n";
    }
}

template<class T>
Node<T> *LinkedList<T>::elAtPos(int i) {
    /* 'i' var go backwards, el go forwards */
    Node<T> *el = head;
    while (i != 0) {
        el = el->getNext();
        i--;
    }

    return el;
}

// Explicit instantiations of all the templates used in the file
template
class LinkedList<string>;

template
class LinkedList<int>;
