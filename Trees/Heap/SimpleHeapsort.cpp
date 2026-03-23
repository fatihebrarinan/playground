// Simple Heapsort Algorithm -  O(nlogn) to build a heap, O(nlogn) to get items from heap to array.

#include <iostream>
#include "Heap.h"

using namespace std;

void heapSort(HeapItemType arr[], int size)
{
    Heap myHeap;

    // 1. Add every element to heap
    for (int i = 0; i < size; i++)
    {
        myHeap.heapInsert(arr[i]);
    }

    // 2. Transfer items one by one to array
    HeapItemType maxItem;
    for (int i = size - 1; i >= 0; i--)
    {
        myHeap.heapDelete(maxItem);
        arr[i] = maxItem;
    }
}

int main()
{
    int arr[] = {62, 14, 85, 27, 91, 53};
    int n = 6;

    cout << "Sirasiz Dizi: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // HeapSort'u çağır
    heapSort(arr, n);

    cout << "Sirali Dizi (HeapSort): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}