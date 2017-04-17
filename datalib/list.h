#ifndef DATALIB_LIST_H
#define DATALIB_LIST_H

template<class T>
class List {
private:
    // List data
    T *data;

    // Size
    int size;

    // -1 when empty; count +1 == size when full
    int count;

    // Adds an space to an idx
    // addSpace(1) will shift everything to the right and leave 1 index 'empty'
    bool addSpace(int idx);

    // Remove an space from an idx, assuming it doesn't need to be used
    // removeSpace(1) will shift everything to the left and leave 1 index filled up
    bool removeSpace(int idx);

    // Returns true if it was possible to allocate the memory
    bool duplicateDataSize();

    // Returns true if it was possible to allocate the memory to specific idx
    bool duplicateDataSizeToIdx(int idx);

    // Returns a pointer of T with the given size
    T *allocateArray(int size);


public:
    List(int startSize);

    // Adds a element to an idx
    bool add(int idx, T el);

    // Orders the data in a crescent way and add the element
    bool addSorted(T el);

    // Remove an element from an idx
    T remove(int idx);

    // Update an element in a index
    T update(int idx, T newEl);

    // Is empty?
    bool empty();

    // Is full?
    bool full();

    // Print it for me
    void printList();

    // Insertion sort
    void sort();
};

#endif //DATALIB_LIST_H
