/**
Program to test BST class
*/

#include<iostream>
#include<sstream>
#include<limits.h>
#include<string>
#include "BST.h"
#define NOT_INITIALIZED -1
using namespace std;

int main(int argc, char* argv)
{
    int convertStringToInteger(string);
    BST* TreeObject = new BST();
    int option = NOT_INITIALIZED;
    string input;
    while(true)
    {
        cout<<"\n\nEnter option: "<<endl
            <<"1. Add key"<<endl
            <<"2. Search key"<<endl
            <<"3. Delete key"<<endl
            <<"4. Print Tree"<<endl
            <<"5. Print Inorder Traversal"<<endl
            <<"6. Print Preorder Traversal"<<endl
            <<"7. Print Postorder Traversal"<<endl
            <<"8. Print Levelorder Traversal"<<endl
            <<"9. Get successor"<<endl
            <<"10. Exit"<<endl;
        cin>>input;
        option = convertStringToInteger(input);
        switch(option)
        {
        case 1:
            {
                cout<<"\nEnter new key: ";
                int newKey;
                cin>>input;
                newKey = convertStringToInteger(input);
                bool success = TreeObject->CallAddNode(newKey);
                if(!success)
                    cout<<"\nERROR! Node already present!"<<endl;
                break;
            }
        case 2:
            {
                cout<<"\nEnter element to search: ";
                int keyToSearch;
                cin>>input;
                keyToSearch = convertStringToInteger(input);
                bool ans = TreeObject->CallSearchNode(keyToSearch);
                if(ans)
                    cout<<"Element PRESENT!\n";
                else
                    cout<<"Element NOT PRESENT\n";
                break;
            }
        case 3:
            {
                cout<<"\nEnter key to delete: ";
                int deleteNode;
                cin>>input;
                deleteNode = convertStringToInteger(input);
                bool success = TreeObject->CallDeleteNode(deleteNode);
                if(!success)
                    cout<<"\nERROR! Node not present!"<<endl;
                break;
            }
        case 4:
            {
                TreeObject->PrintAsBinaryTree();
                break;
            }
        case 5:
            {
                TreeObject->PrintInOrderTraversal();
                break;
            }
        case 6:
            {
                TreeObject->PrintPreOrderTraversal();
                break;
            }
        case 7:
            {
                TreeObject->PrintPostOrderTraversal();
                break;
            }
        case 8:
            {
                TreeObject->PrintLevelOrderTraversal();
                break;
            }
        case 9:
            {
                int key;
                cout<<"\nEnter key: ";
                cin>>input;
                key = convertStringToInteger(input);
                int successor = TreeObject->FindSuccessor(key);
                if(successor ==INT_MIN)
                    cout<<"Key NOT PRESENT!"<<endl;
                else if(successor == INT_MIN+1)
                    cout<<"Successor DOES NOT EXIST!"<<endl;
                else
                    cout<<"Successor: "<<successor<<endl;
                break;
            }
        case 10:
            {
                cout<<"\n\nBYE!"<<endl;
                return(0);
            }
        default:
            {
                cout<<"\nWrong input! :(";
            }
        }
    }
}

int convertStringToInteger(string s)
{
    stringstream convert(s);
    int ans;
    convert >> ans;
    return(ans);
}
