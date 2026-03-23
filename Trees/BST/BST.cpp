// Implementation file for a pointer based Binary Search Tree data structure.
#include "BST.h"

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &tree)
{
    copyTree(tree.root, root);
}

BinarySearchTree::~BinarySearchTree()
{
    destroyTree(root);
}

bool BinarySearchTree::isEmpty() const
{
    return root == nullptr;
}

void BinarySearchTree::copyTree(TreeNode *treePtr, TreeNode *&newTreePtr) const
{
    if (treePtr == nullptr)
        newTreePtr = nullptr;
    else
    {
        newTreePtr = new TreeNode(treePtr->item);
        copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
        copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
    }
}

void BinarySearchTree::destroyTree(TreeNode *&treePtr)
{
    if (treePtr != nullptr)
    {
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = nullptr;
    }
}

void BinarySearchTree::inorderTraversal(void visit(ItemType &)) const
{
    inorder(root, visit);
}

void BinarySearchTree::inorder(TreeNode *treePtr, void visit(ItemType &)) const
{
    if (treePtr != nullptr)
    {
        inorder(treePtr->leftChildPtr, visit);
        visit(treePtr->item);
        inorder(treePtr->rightChildPtr, visit);
    }
}

void BinarySearchTree::insert(const ItemType &newItem)
{
    insertItem(root, newItem);
}

void BinarySearchTree::insertItem(TreeNode *&treePtr, const ItemType &newItem)
{
    if (treePtr == nullptr)
    {
        treePtr = new TreeNode(newItem, nullptr, nullptr);
        return;
    }
    else if (newItem < treePtr->item)
    {
        insertItem(treePtr->leftChildPtr, newItem);
    }
    else
    {
        insertItem(treePtr->rightChildPtr, newItem);
    }
}

void BinarySearchTree::search(KeyType searchKey, ItemType &treeItem) const
{
    retrieveItem(root, searchKey, treeItem);
}

void BinarySearchTree::retrieveItem(TreeNode *treePtr, KeyType searchKey, ItemType &treeItem) const
{
    if (treePtr == nullptr)
    {
        treeItem = "";
        return;
    }
    else if (searchKey > treePtr->item)
    {
        retrieveItem(treePtr->rightChildPtr, searchKey, treeItem);
    }
    else if (searchKey < treePtr->item)
    {
        retrieveItem(treePtr->leftChildPtr, searchKey, treeItem);
    }
    else
    {
        treeItem = treePtr->item;
        return;
    }
}

void BinarySearchTree::deleteItem(KeyType searchKey)
{
    findItem(root, searchKey);
}

void BinarySearchTree::findItem(TreeNode *&treePtr, KeyType searchKey)
{
    if (treePtr == nullptr)
        return;
    else if (searchKey < treePtr->item)
    {
        findItem(treePtr->leftChildPtr, searchKey);
    }
    else if (searchKey > treePtr->item)
    {
        findItem(treePtr->rightChildPtr, searchKey);
    }
    else
    {
        deleteNodeItem(treePtr);
    }
}

void BinarySearchTree::deleteNodeItem(TreeNode *&nodePtr)
{
    // Case 1, its a leaf node
    if (nodePtr->leftChildPtr == nullptr && nodePtr->rightChildPtr == nullptr)
    {
        delete (nodePtr);
        nodePtr = nullptr;
    }
    // Case 2a, it has a left child
    else if (nodePtr->leftChildPtr != nullptr && nodePtr->rightChildPtr == nullptr)
    {
        TreeNode *temp = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delete (temp);
    }
    // Case 2b, it has a right child
    else if (nodePtr->leftChildPtr == nullptr && nodePtr->rightChildPtr != nullptr)
    {
        TreeNode *temp = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delete (temp);
    }
    // Case 3, it has two child
    else
    {
        ItemType replacementItem;
        // Find leftmost child of the right child of nodePtr
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }
}

void BinarySearchTree::processLeftmost(TreeNode *&nodePtr, ItemType &treeItem)
{
    if (nodePtr->leftChildPtr == nullptr)
    {
        treeItem = nodePtr->item;
        TreeNode *temp = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delete (temp);
    }
    else
    {
        processLeftmost(nodePtr->leftChildPtr, treeItem);
    }
}