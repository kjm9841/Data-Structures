/**

Author: Kumar Mehta
Custom Binary Search Tree functions to Add key, Search key, Delete key and various traversals

Search:     O(h)
Insert:     O(h)
Delete:     O(h)
Traversal:  O(n)

*/

#include<iostream>
#include<cstdlib>
#include "BST.h"
#include<queue>
#include<limits.h>
using namespace std;

/**
Constructor
*/
    BST::BST(void)
    {
        root = NULL;
        helper = NULL;
        BSTNodeCount = 0;
    }


/**
Functions to add new key to BST
*/
    bool BST::CallAddNode(int newKey)
    {
        if(root == NULL)
        {
            root = newNode(NULL,NULL,NULL,newKey);
            BSTNodeCount++;
            PrintAsBinaryTree();
            return(true);
        }
        struct BSTNode* check = SearchNode(newKey,root);
        if(check)
            return(false);
        else
        {
            AddNode(newKey);
            PrintAsBinaryTree();
            return(true);
        }
    }

    void BST::AddNode(int newKey)
    {
        if(newKey > helper->key)
        {
            helper->right = newNode(NULL,NULL,helper,newKey);
        }
        else
        {
            helper->left = newNode(NULL,NULL,helper,newKey);
        }
    }

    struct BSTNode* BST::newNode(struct BSTNode* left,struct BSTNode* right,struct BSTNode* parent,int newKey)
    {
        struct BSTNode* createNewNode = new(struct BSTNode);
        createNewNode->key = newKey;
        createNewNode->left = left;
        createNewNode->right = right;
        createNewNode->parent = parent;
        return(createNewNode);
    };


/**
Functions to search key in BST
*/
    bool BST::CallSearchNode(int searchKey)
    {
        helper = NULL;
        if(SearchNode(searchKey,root))
            return(true);
        else
            return(false);
    }

    struct BSTNode* BST::SearchNode(int searchKey, struct BSTNode* current)
    {
        if(current == NULL)
            return(current);
        if(current->key == searchKey)
            return(current);
        helper = current;
        if(current->key > searchKey)
            return(SearchNode(searchKey,current->left));
        else
            return(SearchNode(searchKey,current->right));
    }


/**
Functions to Delete key from a BST
*/
    bool BST::CallDeleteNode(int deleteKey)
    {
        struct BSTNode* NodeToDelete = SearchNode(deleteKey,root);
        if(!NodeToDelete)
        {
            return(false);
        }
        deleteNode(NodeToDelete);
        BSTNodeCount--;
        PrintAsBinaryTree();
        return(true);
    }

    void BST::deleteNode(struct BSTNode* NodeToDelete)
    {
        helper = NodeToDelete->parent;
        if(NodeToDelete->left == NULL && NodeToDelete->right == NULL)
        {
            if(helper)
            {
                if(helper->left == NodeToDelete)
                    helper->left = NULL;
                else
                    helper->right = NULL;
            }
            else
                root = NULL;
        }
        else if(NodeToDelete->left == NULL || NodeToDelete->right == NULL)
        {
            if(helper)
            {
                if(NodeToDelete->left == NULL)
                {
                    NodeToDelete->right->parent = helper;
                    if(helper->left == NodeToDelete)
                        helper->left = NodeToDelete->right;
                    else
                        helper->right = NodeToDelete->right;
                }
                else
                {
                    NodeToDelete->left->parent = helper;
                    if(helper->left == NodeToDelete)
                        helper->left = NodeToDelete->left;
                    else
                        helper->right = NodeToDelete->left;
                }
            }
            else
            {
                if(NodeToDelete->left == NULL)
                {
                    NodeToDelete->right->parent = helper;
                    root = NodeToDelete->right;
                }
                else
                {
                    NodeToDelete->left->parent = helper;
                    root = NodeToDelete->left;
                }
            }
        }
        else
        {
            struct BSTNode* succ = successor(NodeToDelete);
            cout<<succ->key;
            int temp = NodeToDelete->key;
            NodeToDelete->key = succ->key;
            succ->key = temp;
            NodeToDelete = succ;
            helper = succ->parent;
            if(succ->left == NULL && succ->right == NULL)
            {
                if(helper->left == NodeToDelete)
                    helper->left = NULL;
                else
                    helper->right = NULL;
            }
            else
            {
                if(NodeToDelete->left == NULL)
                {
                    NodeToDelete->right->parent = helper;
                    if(helper->left == NodeToDelete)
                        helper->left = NodeToDelete->right;
                    else
                        helper->right = NodeToDelete->right;
                }
                else
                {
                    NodeToDelete->left->parent = helper;
                    if(helper->left == NodeToDelete)
                        helper->left = NodeToDelete->left;
                    else
                        helper->right = NodeToDelete->left;
                }
            }
        }
        delete(NodeToDelete);
    }

    int BST::FindSuccessor(int key)
    {
        struct BSTNode* temp = SearchNode(key,root);
        if(!temp)
            return(INT_MIN);
        else
        {
            temp = successor(temp);
            if(temp)
                return(temp->key);
            else
                return(INT_MIN+1);
        }
    }

    struct BSTNode* BST::successor(struct BSTNode* input)
    {
        struct BSTNode* answer;
        if(input->right)
        {
            answer = input->right;
            while(answer->left)
                answer = answer->left;
        }
        else
        {
            struct BSTNode* temp = input;
            answer = input->parent;
            while(answer && answer->right == temp)
            {
                temp = answer;
                answer = answer->parent;
            }
        }
        return(answer);
    }


/**
Functions to print various traversals
*/

    void BST::PrintInOrderTraversal()
    {
        cout<<"\nIn-Order Traversal: ";
        if(root)
            InOrderTraversal(root);
        cout<<endl;
    }

    void BST::InOrderTraversal(struct BSTNode* current)
    {
        if(current == NULL)
            return;
        InOrderTraversal(current->left);
        cout<<current->key<<" ";
        InOrderTraversal(current->right);
    }

    void BST::PrintPreOrderTraversal()
    {
        cout<<"\nPre-Order Traversal: ";
        if(root)
            PreOrderTraversal(root);
        cout<<endl;
    }

    void BST::PreOrderTraversal(struct BSTNode* current)
    {
        if(current == NULL)
            return;
        cout<<current->key<<" ";
        PreOrderTraversal(current->left);
        PreOrderTraversal(current->right);
    }

    void BST::PrintPostOrderTraversal()
    {
        cout<<"\nPost-Order Traversal: ";
        if(root)
            PostOrderTraversal(root);
        cout<<endl;
    }

    void BST::PostOrderTraversal(struct BSTNode* current)
    {
        if(current == NULL)
            return;
        PostOrderTraversal(current->left);
        PostOrderTraversal(current->right);
        cout<<current->key<<" ";
    }

    void BST::PrintLevelOrderTraversal()
    {
        cout<<"\nLevel-Order Traversal: ";
        if(root)
            LevelOrderTraversal(root);
        cout<<endl;
    }

    void BST::LevelOrderTraversal(struct BSTNode* start)
    {
        queue<struct BSTNode*> levelOrderQueue;
        levelOrderQueue.push(start);
        while(!levelOrderQueue.empty())
        {
            struct BSTNode* current = levelOrderQueue.front();
            if(current->left)
                levelOrderQueue.push(current->left);
            if(current->right)
                levelOrderQueue.push(current->right);
            cout<<current->key<<" ";
            levelOrderQueue.pop();
        }
    }

    void BST::PrintAsBinaryTree()
    {
        cout<<"\nBST: "<<endl;
        if(root)
            PrintAsTree(root);
        cout<<endl;
    }

    void BST::PrintAsTree(struct BSTNode* start)
    {
        queue<struct BSTNode*> levelOrderQueue;
        levelOrderQueue.push(start);
        int level = 0;
        int currentLevelLeft = 1;
        int nextLevel = 0;
        int rowsDone = 0;
        while(!levelOrderQueue.empty())
        {
            struct BSTNode* current = levelOrderQueue.front();
            if(current->left)
            {
                nextLevel++;
                levelOrderQueue.push(current->left);
            }
            if(current->right)
            {
                levelOrderQueue.push(current->right);
                nextLevel++;
            }
            int tabs = column(current);
            while(rowsDone < tabs)
            {
                cout<<"\t";
                rowsDone++;
            }
            cout<<current->key;
            levelOrderQueue.pop();
            currentLevelLeft--;
            if(currentLevelLeft == 0)
            {
                currentLevelLeft = nextLevel;
                nextLevel = 0;
                rowsDone = 0;
                cout<<endl<<endl;
            }
        }
    }


/**
Helper functions to print BST as a tree
*/
    int BST::column(struct BSTNode* current)
    {
        int col = 0;
        int colCount = -1;
        CustomInorderTraversal(root,current->key,colCount,col);
        return(colCount);
    }

    void BST::CustomInorderTraversal(struct BSTNode* current, int key, int& colCount, int& col)
    {
        if(current == NULL)
            return;
        CustomInorderTraversal(current->left,key,colCount,col);
        col++;
        if(current->key == key)
        {
            colCount = col;
        }
        CustomInorderTraversal(current->right,key,colCount,col);
    }


