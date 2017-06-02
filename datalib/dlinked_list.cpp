#include "dlinked_list.h"

template<class T>
DNode<T> *DLinkedList<T>::elAtPos(int i) {
    /* 'i' var go backwards, el go forwards */
    DNode<T> *el = head;
    while (i != 0) {
        el = el->getNext();
        i--;
    }

    return el;
}

template<class T>
DLinkedList<T>::DLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->count = -1;
}

template<class T>
bool DLinkedList<T>::add(int idx, T el) {
    if (empty()) {
        /* Empty list? Just make a new head and tail */
        head = new DNode<T>(el, nullptr);
        tail = head;
    } else if (idx == 0) {
        /* Add it as a new head */
        DNode<T> *newHead = new DNode<T>(el, head);
        head->setPrevious(newHead);
        head = newHead;
    } else if (idx > count) {
        /* Add to the last part of the list */
        DNode<T> *newTail = new DNode<T>(el, nullptr, tail);
        tail->setNext(newTail);
        tail = newTail;
    } else if (idx < count && idx > 0) {
        /* Take the elements that are on the left and right of the new el */
        DNode<T> *rightEl = elAtPos(idx);
        DNode<T> *leftEl = elAtPos(idx - 1);

        /* Pad the element and add the new one */
        DNode<T> *newEl = new DNode<T>(el, rightEl, leftEl);
        leftEl->setNext(newEl);
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
T DLinkedList<T>::remove(int idx) {
    T foundEl;

    if (empty()) {
        /* Empty list? Can't do it.. */
        cerr << "You tried to remove an element from an empty list!" << endl;
        return NULL;
    } else if (idx == 0) {
        /* Gets the head value & delete it */
        DNode<T> *oldHead = head;
        foundEl = oldHead->getValue();

        /* Sets the new head when possible */
        if (count > 0) {
            head = oldHead->getNext();
        }

        delete oldHead;

        head->setPrevious(nullptr);
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
        DNode<T> *middleEl = elAtPos(idx);

        /* Change the pointers */
        (middleEl->getNext())->setPrevious(middleEl->getPrevious());
        (middleEl->getPrevious())->setNext(middleEl->getNext());

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
bool DLinkedList<T>::empty() {
    return count == -1;
}

template<class T>
void DLinkedList<T>::printLinkedList() {
    if (!empty()) {
        int aux = count;
        DNode<T> *auxNode = head;

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
class DLinkedList<string>;

template
class DLinkedList<int>;
