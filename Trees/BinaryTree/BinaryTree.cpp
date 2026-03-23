#include "BinaryTree.h"
#include <algorithm> // max fonksiyonu için

// ------------------- CONSTRUCTORS & DESTRUCTOR -------------------

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::BinaryTree(const TreeItemType &rootItem)
{
    root = new TreeNode(rootItem, nullptr, nullptr);
}

BinaryTree::BinaryTree(const TreeItemType &rootItem, const BinaryTree &leftTree, const BinaryTree &rightTree)
{
    root = new TreeNode(rootItem, nullptr, nullptr);
    copyTree(leftTree.root, root->leftChild);
    copyTree(rightTree.root, root->rightChild);
}

BinaryTree::BinaryTree(const BinaryTree &tree)
{
    copyTree(tree.root, root);
}

BinaryTree::~BinaryTree()
{
    destroyTree(root);
}

// ------------------- PUBLIC FUNCTIONS -------------------

bool BinaryTree::isEmpty() const
{
    return root == nullptr;
}

int BinaryTree::getHeight() const
{
    return getHeightHelper(root);
}

int BinaryTree::getNumberOfNodes() const
{
    return getNumberOfNodesHelper(root);
}

TreeItemType BinaryTree::getRootData() const
{
    if (isEmpty())
        return "";
    return root->item;
}

void BinaryTree::setRootData(const TreeItemType &newItem)
{
    if (!isEmpty())
        root->item = newItem;
}

void BinaryTree::attachLeft(const TreeItemType &newItem)
{
    if (!isEmpty() && root->leftChild == nullptr)
    {
        root->leftChild = new TreeNode(newItem, nullptr, nullptr);
    }
}

void BinaryTree::attachRight(const TreeItemType &newItem)
{
    if (!isEmpty() && root->rightChild == nullptr)
    {
        root->rightChild = new TreeNode(newItem, nullptr, nullptr);
    }
}

void BinaryTree::attachLeftSubtree(const BinaryTree &leftTree)
{
    if (!isEmpty() && root->leftChild == nullptr)
    {
        copyTree(leftTree.root, root->leftChild);
    }
}

void BinaryTree::attachRightSubtree(const BinaryTree &rightTree)
{
    if (!isEmpty() && root->rightChild == nullptr)
    {
        copyTree(rightTree.root, root->rightChild);
    }
}

void BinaryTree::detachLeftSubtree()
{
    if (!isEmpty())
    {
        destroyTree(root->leftChild);
        root->leftChild = nullptr;
    }
}

void BinaryTree::detachRightSubtree()
{
    if (!isEmpty())
    {
        destroyTree(root->rightChild);
        root->rightChild = nullptr;
    }
}

// ------------------- TRAVERSALS -------------------

void BinaryTree::inorderTraversal(void visit(TreeItemType &)) const
{
    inorderHelper(root, visit);
}

void BinaryTree::preorderTraversal(void visit(TreeItemType &)) const
{
    preorderHelper(root, visit);
}

void BinaryTree::postorderTraversal(void visit(TreeItemType &)) const
{
    postorderHelper(root, visit);
}

// ------------------- PRIVATE HELPERS -------------------

void BinaryTree::copyTree(TreeNode *treeptr, TreeNode *&newTreeptr) const
{
    if (treeptr == nullptr)
        newTreeptr = nullptr;
    else
    {
        newTreeptr = new TreeNode(treeptr->item, nullptr, nullptr);
        copyTree(treeptr->leftChild, newTreeptr->leftChild);
        copyTree(treeptr->rightChild, newTreeptr->rightChild);
    }
}

void BinaryTree::destroyTree(TreeNode *node)
{
    if (node != nullptr)
    {
        destroyTree(node->leftChild);
        destroyTree(node->rightChild);
        delete node;
    }
}

int BinaryTree::getHeightHelper(TreeNode *node) const
{
    if (node == nullptr)
        return 0;
    return 1 + max(getHeightHelper(node->leftChild), getHeightHelper(node->rightChild));
}

int BinaryTree::getNumberOfNodesHelper(TreeNode *node) const
{
    if (node == nullptr)
        return 0;
    return 1 + getNumberOfNodesHelper(node->leftChild) + getNumberOfNodesHelper(node->rightChild);
}

void BinaryTree::inorderHelper(TreeNode *node, void visit(TreeItemType &)) const
{
    if (node != nullptr)
    {
        inorderHelper(node->leftChild, visit);
        visit(node->item);
        inorderHelper(node->rightChild, visit);
    }
}

void BinaryTree::preorderHelper(TreeNode *node, void visit(TreeItemType &)) const
{
    if (node != nullptr)
    {
        visit(node->item);
        preorderHelper(node->leftChild, visit);
        preorderHelper(node->rightChild, visit);
    }
}

void BinaryTree::postorderHelper(TreeNode *node, void visit(TreeItemType &)) const
{
    if (node != nullptr)
    {
        postorderHelper(node->leftChild, visit);
        postorderHelper(node->rightChild, visit);
        visit(node->item);
    }
}