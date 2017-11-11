#include<iostream>
#include<string>
#include<sstream>
#include "SortingAlgorithms.h"
#define NOT_INITIALIZED -1
using namespace std;

int main(int argc, char* argv)
{
    int ConvertStingToInteger(string);
    void PrintArray(int*,int);
    int* TestArray;
    int ArraySize = 8;
    for(int i = 8,j = 0; i > 0 ; i--,j++)
    {
        TestArray[j] = i;
    }
    cout<<"Input: ";
    for(int i = 0 ; i < 8 ; i++)
        cout<<TestArray[i]<<" ";
    SortingAlgorithms* Object = new SortingAlgorithms();
    int option =  NOT_INITIALIZED;
    string input;
    while(true)
    {
        cout<<"\n\nEnter option:"<<endl
            <<"1. Take Input"<<endl
            <<"2. Insertion Sort"<<endl
            <<"3. Selection Sort"<<endl
            <<"4. Bubble Sort"<<endl
            <<"5. Merge Sort"<<endl
            <<"6. Heap Sort"<<endl
            <<"7. Quick Sort"<<endl
            <<"8. Kth Order Statistic"<<endl
            <<"9. Binary Search"<<endl
            <<"10. Exit"<<endl;
        cin>>input;
        int option = ConvertStingToInteger(input);
        switch(option)
        {
        case 1:
            {
                delete(TestArray);
                cout<<"\nEnter n: ";
                cin>>input;
                ArraySize = ConvertStingToInteger(input);
                if(ArraySize > 0)
                {
                    cout<<"\nEnter elements: ";
                    TestArray = new int[ArraySize];
                    for(int i = 0 ; i < ArraySize ; i++)
                    {
                        cin>>input;
                        TestArray[i] = ConvertStingToInteger(input);
                    }
                }
                break;
            }
        case 2:
            {
                Object->InsertionSort(TestArray,ArraySize);
                PrintArray(TestArray,ArraySize);
                break;
            }
        case 3:
            {
                Object->SelectionSort(TestArray,ArraySize);
                PrintArray(TestArray,ArraySize);
                break;
            }
        case 4:
            {
                Object->BubbleSort(TestArray,ArraySize);
                PrintArray(TestArray,ArraySize);
                break;
            }
        case 5:
            {
                Object->MergeSort(TestArray,ArraySize);
                PrintArray(TestArray,ArraySize);
                break;
            }
        case 6:
            {
                Object->HeapSort(TestArray,ArraySize);
                PrintArray(TestArray,ArraySize);
                break;
            }
        case 7:
            {
                Object->QuickSort(TestArray,ArraySize);
                PrintArray(TestArray,ArraySize);
                break;
            }
        case 8:
            {
                cout<<"\nEnter k: ";
                cin>>input;
                int k;
                k = ConvertStingToInteger(input);
                int ans = Object->KthOrderStatistic(TestArray, ArraySize,k);
                if(ans == INT_MAX)
                    cout<<"Does NOT exist!";
                else
                    cout<<k <<"th Order statistic: "<<ans;
                break;
            }
        case 9:
            {
                cout<<"\nEnter element to search: ";
                int ElementToSearch;
                cin>>input;
                ElementToSearch = ConvertStingToInteger(input);
                bool present = Object->BinarySearch(TestArray, ElementToSearch, ArraySize);
                if(present)
                    cout<<"\nElement "<<ElementToSearch<<" is present";
                else
                    cout<<"\nElement "<<ElementToSearch<<" is NOT present";
                break;
            }
        default:
            {
                cout<<"\nWrong Input! :("<<endl;
            }
        }
    }
    return(0);
}

void PrintArray(int* OutputArray, int ArraySize)
{
    cout<<"\nSorted Array: ";
    for(int iter = 0 ; iter < ArraySize ; iter++)
    {
        cout<<OutputArray[iter]<<" ";
    }
    cout<<endl;
}

int ConvertStingToInteger(string s)
{
    stringstream convert(s);
    int ans;
    convert >> ans;
    return(ans);
}
