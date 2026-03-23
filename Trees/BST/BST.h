// Header file for a pointer based Binary Search Tree data structure.
#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef string KeyType;
typedef string ItemType;

struct TreeNode
{
    ItemType item;
    TreeNode *leftChildPtr;
    TreeNode *rightChildPtr;

    TreeNode(const ItemType &nodeItem, TreeNode *left = nullptr, TreeNode *right = nullptr)
        : item(nodeItem), leftChildPtr(left), rightChildPtr(right) {}
};

class BinarySearchTree
{
public:
    // Constructors & Destructor
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree &tree);
    ~BinarySearchTree();

    bool isEmpty() const;

    // --- Public Interface ---
    void search(KeyType searchKey, ItemType &treeItem) const;
    void insert(const ItemType &newItem);
    void deleteItem(KeyType searchKey);

    // Traversal
    void inorderTraversal(void visit(ItemType &)) const;

private:
    TreeNode *root;

    void insertItem(TreeNode *&treePtr, const ItemType &newItem);
    void findItem(TreeNode *&treePtr, KeyType searchKey);
    void deleteNodeItem(TreeNode *&nodePtr);
    void processLeftmost(TreeNode *&nodePtr, ItemType &treeItem);
    void retrieveItem(TreeNode *treePtr, KeyType searchKey, ItemType &treeItem) const;

    // Destructor ve Copy Constructor helpers
    void copyTree(TreeNode *treePtr, TreeNode *&newTreePtr) const;
    void destroyTree(TreeNode *&treePtr);
    void inorder(TreeNode *treePtr, void visit(ItemType &)) const;
};

#endif