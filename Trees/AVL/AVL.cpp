#include "AVL.h"
#include <iostream>

AVL::AVL() : root(nullptr) {}

AVL::~AVL()
{
    destroyTree(root);
}

void AVL::destroyTree(AVLNode *&treePtr)
{
    if (treePtr != nullptr)
    {
        destroyTree(treePtr->leftChild);
        destroyTree(treePtr->rightChild);
        delete treePtr;
        treePtr = nullptr;
    }
}

void AVL::rotateLeft(AVLNode *&treePtr)
{
    AVLNode *newRoot = treePtr->rightChild;
    treePtr->rightChild = newRoot->leftChild;
    newRoot->leftChild = treePtr;
    treePtr = newRoot;
}

void AVL::rotateRight(AVLNode *&treePtr)
{
    AVLNode *newRoot = treePtr->leftChild;
    treePtr->leftChild = newRoot->rightChild;
    newRoot->rightChild = treePtr;
    treePtr = newRoot;
}

void AVL::rightLeftRotate(AVLNode *&treePtr)
{
    rotateRight(treePtr->rightChild);
    rotateLeft(treePtr);
}

void AVL::leftRightRotate(AVLNode *&treePtr)
{
    rotateLeft(treePtr->leftChild);
    rotateRight(treePtr);
}

void AVL::insertLeftBalance(AVLNode *&treePtr, bool &taller)
{
    AVLNode *leftTree = treePtr->leftChild;

    if (leftTree->balance == LH)
    {
        treePtr->balance = EH;
        leftTree->balance = EH;
        rotateRight(treePtr);
        taller = false;
    }
    else if (leftTree->balance == RH)
    {
        AVLNode *rightTree = leftTree->rightChild;

        if (rightTree->balance == LH)
        {
            treePtr->balance = RH;
            leftTree->balance = EH;
        }
        else if (rightTree->balance == RH)
        {
            treePtr->balance = EH;
            leftTree->balance = LH;
        }
        else
        {
            treePtr->balance = EH;
            leftTree->balance = EH;
        }
        rightTree->balance = EH;
        leftRightRotate(treePtr);
        taller = false;
    }
}

void AVL::insertRightBalance(AVLNode *&treePtr, bool &taller)
{
    AVLNode *rightTree = treePtr->rightChild;

    if (rightTree->balance == RH)
    {
        treePtr->balance = EH;
        rightTree->balance = EH;
        rotateLeft(treePtr);
        taller = false;
    }
    else if (rightTree->balance == LH)
    {
        AVLNode *leftTree = rightTree->leftChild;

        if (leftTree->balance == RH)
        {
            treePtr->balance = LH;
            rightTree->balance = EH;
        }
        else if (leftTree->balance == LH)
        {
            treePtr->balance = EH;
            rightTree->balance = RH;
        }
        else
        {
            treePtr->balance = EH;
            rightTree->balance = EH;
        }
        leftTree->balance = EH;
        rightLeftRotate(treePtr);
        taller = false;
    }
}

void AVL::insert(const TreeItemType &newItem)
{
    bool taller = false;
    insertItem(root, newItem, taller);
}

void AVL::insertItem(AVLNode *&treePtr, const TreeItemType &newItem, bool &taller)
{
    if (treePtr == nullptr)
    {
        treePtr = new AVLNode(newItem, nullptr, nullptr, EH);
        taller = true;
    }
    else if (newItem < treePtr->item)
    {
        insertItem(treePtr->leftChild, newItem, taller);

        if (taller)
        {
            if (treePtr->balance == LH)
            {
                insertLeftBalance(treePtr, taller);
            }
            else if (treePtr->balance == EH)
            {
                treePtr->balance = LH;
            }
            else if (treePtr->balance == RH)
            {
                treePtr->balance = EH;
                taller = false;
            }
        }
    }
    else
    {
        insertItem(treePtr->rightChild, newItem, taller);

        if (taller)
        {
            if (treePtr->balance == RH)
            {
                insertRightBalance(treePtr, taller);
            }
            else if (treePtr->balance == EH)
            {
                treePtr->balance = RH;
            }
            else if (treePtr->balance == LH)
            {
                treePtr->balance = EH;
                taller = false;
            }
        }
    }
}

void AVL::deleteLeftBalance(AVLNode *&treePtr, bool &shorter)
{
    AVLNode *leftTree = treePtr->leftChild;

    if (leftTree->balance == RH)
    {
        AVLNode *rightTree = leftTree->rightChild;
        if (rightTree->balance == RH)
        {
            leftTree->balance = LH;
            treePtr->balance = EH;
        }
        else if (rightTree->balance == LH)
        {
            leftTree->balance = EH;
            treePtr->balance = RH;
        }
        else
        {
            leftTree->balance = EH;
            treePtr->balance = EH;
        }
        rightTree->balance = EH;
        leftRightRotate(treePtr);
    }
    else
    {
        if (leftTree->balance == EH)
        {
            treePtr->balance = LH;
            leftTree->balance = RH;
            shorter = false;
        }
        else
        {
            treePtr->balance = EH;
            leftTree->balance = EH;
        }
        rotateRight(treePtr);
    }
}

void AVL::deleteRightBalance(AVLNode *&treePtr, bool &shorter)
{
    AVLNode *rightTree = treePtr->rightChild;

    if (rightTree->balance == LH)
    {
        AVLNode *leftTree = rightTree->leftChild;
        if (leftTree->balance == LH)
        {
            rightTree->balance = RH;
            treePtr->balance = EH;
        }
        else if (leftTree->balance == RH)
        {
            rightTree->balance = EH;
            treePtr->balance = LH;
        }
        else
        {
            rightTree->balance = EH;
            treePtr->balance = EH;
        }
        leftTree->balance = EH;
        rightLeftRotate(treePtr);
    }
    else
    {
        if (rightTree->balance == EH)
        {
            treePtr->balance = RH;
            rightTree->balance = LH;
            shorter = false;
        }
        else
        {
            treePtr->balance = EH;
            rightTree->balance = EH;
        }
        rotateLeft(treePtr);
    }
}

void AVL::deleteItem(const TreeItemType &item)
{
    bool shorter = false;
    deleteNode(root, item, shorter);
}

void AVL::deleteNode(AVLNode *&treePtr, TreeItemType searchKey, bool &shorter)
{
    if (treePtr == nullptr)
    {
        shorter = false;
        return;
    }

    if (searchKey < treePtr->item)
    {
        deleteNode(treePtr->leftChild, searchKey, shorter);
        if (shorter)
        {
            if (treePtr->balance == LH)
            {
                treePtr->balance = EH;
            }
            else if (treePtr->balance == EH)
            {
                treePtr->balance = RH;
                shorter = false;
            }
            else
            {
                deleteRightBalance(treePtr, shorter);
            }
        }
    }
    else if (searchKey > treePtr->item)
    {
        deleteNode(treePtr->rightChild, searchKey, shorter);
        if (shorter)
        {
            if (treePtr->balance == LH)
            {
                deleteLeftBalance(treePtr, shorter);
            }
            else if (treePtr->balance == EH)
            {
                treePtr->balance = LH;
                shorter = false;
            }
            else
            {
                treePtr->balance = EH;
            }
        }
    }
    else
    {
        if (treePtr->leftChild == nullptr && treePtr->rightChild == nullptr)
        {
            delete treePtr;
            treePtr = nullptr;
            shorter = true;
        }
        else if (treePtr->leftChild == nullptr)
        {
            AVLNode *temp = treePtr;
            treePtr = treePtr->rightChild;
            delete temp;
            shorter = true;
        }
        else if (treePtr->rightChild == nullptr)
        {
            AVLNode *temp = treePtr;
            treePtr = treePtr->leftChild;
            delete temp;
            shorter = true;
        }
        else
        {
            AVLNode *temp = treePtr->leftChild;
            while (temp->rightChild != nullptr)
            {
                temp = temp->rightChild;
            }
            treePtr->item = temp->item;
            deleteNode(treePtr->leftChild, temp->item, shorter);

            if (shorter)
            {
                if (treePtr->balance == LH)
                {
                    treePtr->balance = EH;
                }
                else if (treePtr->balance == EH)
                {
                    treePtr->balance = RH;
                    shorter = false;
                }
                else
                {
                    deleteRightBalance(treePtr, shorter);
                }
            }
        }
    }
}

void AVL::inorderTraversal() const
{
    inorder(root);
    std::cout << std::endl;
}

void AVL::inorder(AVLNode *treePtr) const
{
    if (treePtr != nullptr)
    {
        inorder(treePtr->leftChild);
        std::cout << treePtr->item << " ";
        inorder(treePtr->rightChild);
    }
}