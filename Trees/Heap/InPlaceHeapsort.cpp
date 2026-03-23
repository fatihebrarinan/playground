// InPlace Heapsort Algorithm -  O(n) to build a heap, O(nlogn) to get items from heap to array.
#include <iostream>

using namespace std;

// Same function with the heapRebuild in Heap.cpp, but this has size as a parameter.
void rebuildHeap(int arr[], int size, int root)
{
    int largest = root;
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;

    if (leftChild < size && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }

    if (rightChild < size && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (largest != root)
    {
        // Swap
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        rebuildHeap(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{
    // 1. Convert array to max-heap
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        rebuildHeap(arr, size, i);
    }

    // 2. Extract max for every item in array
    for (int i = size - 1; i > 0; i--)
    {
        // Swap
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call rebuildHeap with current size
        rebuildHeap(arr, i, 0);
    }
}

int main()
{
    int arr[] = {42, 17, 89, 33, 56, 12, 95, 21};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Sirasiz Dizi: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    heapSort(arr, n);

    cout << "Sirali Dizi : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}