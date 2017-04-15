
#include "list.h"

template <class T>
bool List<T>::addSpace(int idx) {
    // TODO: Implement this
    duplicateDataSizeToIdx(idx);
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
    // If the idx is too large, duplicate the array exponentially until it is right
    if (idx >= size) {
        if (!duplicateDataSizeToIdx(idx)) {
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
