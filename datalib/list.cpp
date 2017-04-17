#include <iostream>
#include "list.h"

using namespace std;

template <class T>
bool List<T>::addSpace(int idx) {
    // Duplicate if full
    if (this->full()) {
        this->duplicateDataSize();
    }

    // Extends the array until the size is good
    duplicateDataSizeToIdx(idx);

    // Sends the rest of the elements to the right of the index
    int i = count;
    while (i-- >= idx) {
        data[i + 1] = data[i];
    }
}

template <class T>
bool List<T>::duplicateDataSize() {
    // Allocate the new array
    T *newArray = allocateArray(size * 2);

    // Cancel the operation if failed to allocate
    if (newArray == nullptr) {
        return false;
    }

    // Copy the content of data to the new array
    for (int i = 0; i <= count; i++) {
        newArray[i] = data[i];
    }

    // Delete old data
    delete [] data;

    // Shift the pointers
    data = newArray;

    // Returns success
    return true;
}

bool List::duplicateDataSizeToIdx(int idx) {
    // While not successful
    while(idx >= size) {
        // If it failed to duplicate, cancel the operation
        if (!duplicateDataSize()) {
            return false;
        }
    }

    return true;
}

template <class T>
T *List<T>::allocateArray(int size) {
    return new T[size];
}

template <class T>
List<T>::List(int initialSize) {
    // Setup internal variables
    size = initialSize;
    count = -1;
    data = allocateArray(size);

}

template <class T>
bool List<T>::add(int idx, T el) {
    // Duplicate if full
    if (full()) {
        if (!duplicateDataSize()) {
            // Cancel the operation if it failed
            return false;
        }
    }

    // If a shift must be made
    if (idx <= count) {
        if (!addSpace(idx)) {
            // Cancel the operation if it failed
            return false;
        }
    }
    else if (idx > count + 1) {
        // Move the index to the last pos of the list
        cerr << "Index to add in the list too large: " << idx << ". Using " << idx + 1 << " index instead." << endl;
        idx = count + 1;
    }

    // Adds the el
    data[idx] = el;

    // Returns success
    return true;
}

template <class T>
T List<T>::remove(int idx) {
    // TODO: Implement this
    return nullptr;
}

template <class T>
bool List<T>::empty() {
    return count == -1;
}

template <class T>
bool List<T>::full() {
    return count + 1 == size;
}
