/*
Author  :   Kumar Mehta
Date    :   26/09/2017
Program to implement  Singly Linked Lists

Insertion   ->  O(1)
Search      ->  O(n)
Delete      ->  O(n)

*/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int key;
    struct node* next;
};

class SinglyLinkedList
{
    struct node* head;
    struct node* helper;        // node to aid deleteNode function as helper will point to previous node

public:

    SinglyLinkedList(void)
    {
        head = NULL;
        helper = NULL;
    }

    void addNode(int k)
    {
        struct node* temp = new struct node;
        temp->key = k;
        temp->next = head;
        head = temp;
        printList();
    }

/*Call function to call from outside of class*/
    int callSearch(int k)
    {
        struct node* temp = searchNode(k);
        if(temp)
            return(1);
        else
            return(0);
    }

    struct node* searchNode(int k)
    {
        struct node* temp = head;
        helper = NULL;
        while(temp)
        {
            if(temp->key == k)
                return(temp);
            helper = temp;
            temp = temp->next;
        }
        return(NULL);
    }

    void deleteNode(int k)
    {
        /*Only if node is successfully searched, delete it*/
        if(searchNode(k))
        {
            struct node* temp;
            if(helper == NULL)
            {
                temp = head;
                head = head->next;
            }
            else
            {
                temp = helper->next;
                helper->next = temp->next;
            }
            delete(temp);
            printList();
        }
        else
            cout<<"\nElement NOT PRESENT!\n";
    }

    void printList()
    {
        cout<<"\nHead -> ";
        struct node* temp = head;
        while(temp)
        {
            cout<<temp->key<<" -> ";
            temp = temp->next;
        }
        cout<<" NULL\n";
    }

};


int main()
{
    SinglyLinkedList TempList;
    int option = -1;
    while(1)
    {
        cout<<"\n\nEnter option: "<<endl
            <<"1. Add node"<<endl
            <<"2. Delete node"<<endl
            <<"3. Print List"<<endl
            <<"4. Search List"<<endl
            <<"9. Exit"<<endl;
        cin>>option;
        switch(option)
        {
        case 1:
            {
                cout<<"\nEnter new key: ";
                int n;
                cin>>n;
                TempList.addNode(n);
                break;
            }
        case 2:
            {
                cout<<"\nEnter key to delete: ";
                int n;
                cin>>n;
                TempList.deleteNode(n);
                break;
            }
        case 3:
            {
                TempList.printList();
                break;
            }
        case 4:
            {
                cout<<"\nEnter element to search: ";
                int n;
                cin>>n;
                int ans = TempList.callSearch(n);
                if(ans)
                    cout<<" Element PRESENT!\n";
                else
                    cout<<" Element NOT PRESENT\n";
                break;
            }
        case 9:
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
