//Header file of a pointer based implementation of a binary tree.
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>

using namespace std;

typedef string TreeItemType;

class TreeNode{
    private:
        TreeNode(){};
        TreeNode(const TreeItemType &item, TreeNode *left, TreeNode *right){
            this->item = item;
            this->leftChild = left;
            this->rightChild = right;
        }
        TreeItemType item;
        TreeNode *leftChild;
        TreeNode *rightChild;
        //Friend class
        friend class BinaryTree;
};

class BinaryTree{
    public:
        BinaryTree();
        BinaryTree(const TreeItemType &rootItem);
        BinaryTree(const TreeItemType &rootItem, const BinaryTree &leftTree, const BinaryTree &rightTree);
        BinaryTree(const BinaryTree &tree);
        ~BinaryTree();
        bool isEmpty() const;
        int getHeight() const;
        int getNumberOfNodes() const;
        TreeItemType getRootData() const;
        void setRootData(const TreeItemType &newItem);
        void attachLeft(const TreeItemType &newItem);
        void attachRight(const TreeItemType &newItem);
        void attachLeftSubtree(const BinaryTree &leftTree);
        void attachRightSubtree(const BinaryTree &rightTree);
        void detachLeftSubtree();
        void detachRightSubtree();
        void inorderTraversal(void visit(TreeItemType &)) const;
        void preorderTraversal(void visit(TreeItemType &)) const;
        void postorderTraversal(void visit(TreeItemType &)) const;
    private:
        TreeNode *root;
        void copyTree(TreeNode *treeptr, TreeNode *&newTreeptr) const;
        void destroyTree(TreeNode *node);
        int getHeightHelper(TreeNode *node) const;
        int getNumberOfNodesHelper(TreeNode *node) const;
        void inorderHelper(TreeNode *node, void visit(TreeItemType &)) const;
        void preorderHelper(TreeNode *node, void visit(TreeItemType &)) const;
        void postorderHelper(TreeNode *node, void visit(TreeItemType &)) const;
};

#endif
