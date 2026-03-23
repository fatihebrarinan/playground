// Header file for the array based heap implementation
#ifndef HEAP_H
#define HEAP_H

#include <iostream>

using namespace std;

const int MAX_HEAP = 100;
typedef int HeapItemType;

class Heap
{
public:
    Heap();
    bool heapIsEmpty() const;

    void heapDelete(HeapItemType &rootItem);

    void heapInsert(const HeapItemType &newItem);

protected:
    void heapRebuild(int root);

private:
    HeapItemType items[MAX_HEAP];
    int size;
};

#endif