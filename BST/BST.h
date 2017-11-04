/**

Author: Kumar Mehta
Custom Binary Search Tree class definition to Add key, Search key, Delete key and various traversals

Search:     O(h)
Insert:     O(h)
Delete:     O(h)
Traversal:  O(n)

*/
#ifndef BST_h
#define BST_h

#include<iostream>
using namespace std;

struct BSTNode
{
    int key;
    struct BSTNode* left;
    struct BSTNode* right;
    struct BSTNode* parent;
};

class BST
{
    BSTNode* root;
    BSTNode* helper;
    int BSTNodeCount;

public:

    BST(void);

/**Functions to add new key to BST*/
    bool CallAddNode(int);
    void AddNode(int);
    struct BSTNode* newNode(struct BSTNode*, struct BSTNode*, struct BSTNode*, int);

/**Functions to search key in BST*/
    bool CallSearchNode(int);
    struct BSTNode* SearchNode(int, struct BSTNode*);

/**Functions to delete key from BST*/
    void deleteNode(struct BSTNode*);
    int FindSuccessor(int);
    struct BSTNode* successor(struct BSTNode*);
    bool CallDeleteNode(int);

/** Traversal functions*/
    void InOrderTraversal(struct BSTNode*);
    void PostOrderTraversal(struct BSTNode*);
    void PreOrderTraversal(struct BSTNode*);
    void LevelOrderTraversal(struct BSTNode*);
    void PrintAsTree(struct BSTNode*);
    void PrintLevelOrderTraversal();
    void PrintAsBinaryTree();
    void PrintInOrderTraversal();
    void PrintPreOrderTraversal();
    void PrintPostOrderTraversal();

    int column(struct BSTNode*);
    void CustomInorderTraversal(struct BSTNode*, int, int&, int&);
};


#endif
