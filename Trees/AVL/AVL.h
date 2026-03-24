// Header file for a pointer based AVL implementation
#ifndef AVL_H
#define AVL_H

#include <iostream>

typedef int TreeItemType;

enum BalanceFactor
{
    LH, // Left-High
    EH, // Equal-High
    RH  // Right-High
};

struct AVLNode
{
    TreeItemType item;
    AVLNode *leftChild;
    AVLNode *rightChild;
    BalanceFactor balance;

    // Constructor
    AVLNode(const TreeItemType &nodeItem, AVLNode *left = nullptr, AVLNode *right = nullptr, BalanceFactor bal = EH)
        : item(nodeItem), leftChild(left), rightChild(right), balance(bal) {}
};

class AVL
{
public:
    AVL();
    ~AVL();

    void insert(const TreeItemType &newItem);
    void deleteItem(const TreeItemType &item);
    void inorderTraversal() const;

private:
    AVLNode *root;

    void destroyTree(AVLNode *&treePtr);
    void inorder(AVLNode *treePtr) const;

    // Functions with reference flags, taller for insertion and shorter for deletion
    void insertItem(AVLNode *&treePtr, const TreeItemType &newItem, bool &taller);
    void deleteNode(AVLNode *&treePtr, TreeItemType searchKey, bool &shorter);

    // Rotations
    void rotateLeft(AVLNode *&treePtr);
    void rotateRight(AVLNode *&treePtr);
    void rightLeftRotate(AVLNode *&treePtr);
    void leftRightRotate(AVLNode *&treePtr);

    // Helper functions that call rotation functions if needed
    void insertLeftBalance(AVLNode *&treePtr, bool &taller);
    void insertRightBalance(AVLNode *&treePtr, bool &taller);
    void deleteRightBalance(AVLNode *&treePtr, bool &shorter);
    void deleteLeftBalance(AVLNode *&treePtr, bool &shorter);
};

#endif