#ifndef DATALIB_LIST_H
#define DATALIB_LIST_H

template <class T>
class List {
private:
    // Adds an space to an idx
    // addSpace(1) will shift everything to the right and leave 1 empty
    bool addSpace(int idx);

    // Returns true if it was possible to allocate the memory
    bool duplicateDataSize();

    // Returns a pointer of T with the given size
    T *allocateArray(int size);

public:
    List(int startSize);

    // Adds a element to an idx
    bool add(int idx, T el);

    // Remove an element from an idx
    T remove(int idx);
};

#endif //DATALIB_LIST_H
