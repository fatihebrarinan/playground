// Implementation of the Treesort algorithm. O(nlogn) average case, 0(n^2) worst case.
#include <iostream>
#include "BST.h"

using namespace std;

void printItem(ItemType &item)
{
    cout << item << " ";
}

int main()
{
    ItemType arr[] = {"Muz", "Elma", "Cilek", "Armut", "Kivi"};
    int n = 5;

    cout << "Sirasiz Dizi: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    BinarySearchTree myTree;

    for (int i = 0; i < n; i++)
    {
        myTree.insert(arr[i]);
    }
    cout << "Sirali Dizi (TreeSort): ";
    myTree.inorderTraversal(printItem);
    cout << endl;

    return 0;
}