// Implementation file for the array based heap code
#include "Heap.h"

Heap::Heap()
{
    size = 0;
}

bool Heap::heapIsEmpty() const
{
    return size == 0;
}

void Heap::heapInsert(const HeapItemType &newItem)
{

    if (size >= MAX_HEAP)
        return;

    items[size] = newItem;
    int currentLocation = size;
    int parentLocation = (currentLocation - 1) / 2;
    int temp;

    while (currentLocation > 0 && items[currentLocation] > items[parentLocation])
    {
        temp = items[currentLocation];
        items[currentLocation] = items[parentLocation];
        items[parentLocation] = temp;

        currentLocation = parentLocation;
        parentLocation = (currentLocation - 1) / 2;
    }
    size++;
}

void Heap::heapDelete(HeapItemType &rootItem)
{
    if (heapIsEmpty())
        return;

    rootItem = items[0];
    items[0] = items[size - 1];
    size--;
    heapRebuild(0);
}

void Heap::heapRebuild(int root)
{
    int largest = root;
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;
    if ((leftChild) < size && items[leftChild] > items[root])
    {
        largest = leftChild;
    }
    if (rightChild < size && items[rightChild] > items[largest])
    {
        largest = rightChild;
    }

    if (largest != root)
    {
        HeapItemType temp = items[root];
        items[root] = items[largest];
        items[largest] = temp;
        // Check for the child now
        heapRebuild(largest);
    }
}