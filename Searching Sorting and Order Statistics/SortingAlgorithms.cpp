/**

Class functions:    Insertion sort, selection sort, bubble sort,
                    Merge sort, Randomized quick sort, Heapsort,
                    Kth Order statistic, Binary search

*/

#include<iostream>
#include<cstdlib>
#include<limits.h>
#include "SortingAlgorithms.h"
using namespace std;



    SortingAlgorithms::SortingAlgorithms()
    {
        //
    }

    void SortingAlgorithms::InsertionSort(int*& InputArray, int ArraySize)
    {
        for(int iter = 1 ; iter < ArraySize ; iter++)
        {
            int key = InputArray[iter];
            int j = iter - 1;
            while(j >= 0 && InputArray[j] > key)
            {
                InputArray[j+1] = InputArray[j];
                j--;
            }
            InputArray[j+1] = key;
        }
        PrintArray(InputArray,ArraySize);
    }

    void SortingAlgorithms::SelectionSort(int* InputArray, int ArraySize)
    {
        for(int i = 0 ; i < ArraySize - 1; i++)
        {
            int SelectMin = i;
            for(int j = i+1 ; j < ArraySize ; j++)
            {
                if(InputArray[j] < InputArray[SelectMin])
                    SelectMin = j;
            }
            int temp = InputArray[SelectMin];
            InputArray[SelectMin] = InputArray[i];
            InputArray[i] = temp;
        }
        PrintArray(InputArray,ArraySize);
    }

    void SortingAlgorithms::BubbleSort(int* InputArray, int ArraySize)
    {
        for(int i = 0 ; i < ArraySize - 1; i++)
        {
            for(int j = 1 ; j < ArraySize - i ; j++)
            {
                if(InputArray[j] < InputArray[j-1])
                {
                    int temp = InputArray[j];
                    InputArray[j] = InputArray[j-1];
                    InputArray[j-1] = temp;
                }
            }

        }
        PrintArray(InputArray,ArraySize);
    }

    void SortingAlgorithms::MergeSort(int* InputArray, int ArraySize)
    {
        MergeSortArray(InputArray, 0 , ArraySize - 1);
        PrintArray(InputArray, ArraySize);
    }

    void SortingAlgorithms::MergeSortArray(int* InputArray, int low, int high)
    {
        if(low < high)
        {
            int mid = (low + high)/2;
            MergeSortArray(InputArray, low, mid);
            MergeSortArray(InputArray, mid+1, high);
            Merge(InputArray, low, mid, high);
        }
    }

    void SortingAlgorithms::Merge(int* InputArray, int low, int mid, int high)
    {
        int length1 = mid - low + 2;
        int length2 = high - mid + 1;
     //   cout<<low<<" "<<mid<<" "<<high<<" ";
        int* TempLowerArray = new int[length1];
        int* TempUpperArray = new int[length2];
        for(int it = 0; it < length1 - 1; it++)
        {
            TempLowerArray[it] = InputArray[low + it];
        }
        TempLowerArray[length1 - 1] = INT_MAX;
        for(int it = 0 ; it < length2 - 1 ; it++)
        {
            TempUpperArray[it] = InputArray[mid + 1 + it];
        }
        TempUpperArray[length2 - 1] = INT_MAX;
        int pointer1 = 0;
        int pointer2 = 0;
        for(int it = 0; it < length1 + length2 - 2 ; it++)
        {
            //cout<<TempLowerArray[pointer1]<<" "<<TempUpperArray[pointer2]<<" ";
            if(TempLowerArray[pointer1] <= TempUpperArray[pointer2])
            {
                InputArray[low + it] = TempLowerArray[pointer1];
                pointer1++;
            }
            else
            {
                InputArray[low + it] = TempUpperArray[pointer2];
                pointer2++;
            }
        }
    }

    void SortingAlgorithms::HeapSort(int* InputArray, int ArraySize)
    {
        int HeapSize = ArraySize;
        BuildMaxHeap(InputArray, HeapSize);
        for(int i = HeapSize - 1 ; i >= 1 ; i--)
        {
            int temp = InputArray[0];
            InputArray[0] = InputArray[i];
            InputArray[i] = temp;
            HeapSize--;
            MaxHeapify(InputArray, 0, HeapSize);
        }
        PrintArray(InputArray, ArraySize);
    }

    void SortingAlgorithms::MaxHeapify(int* InputArray, int index, int HeapSize)
    {
        int largest = index;
        int l = (index* 2) + 1;
        int r = (index * 2) + 2;
        if(l < HeapSize && InputArray[l] > InputArray[largest])
            largest = l;
        if(r < HeapSize && InputArray[r] > InputArray[largest])
            largest = r;
        if(largest != index)
        {
            int temp = InputArray[index];
            InputArray[index] = InputArray[largest];
            InputArray[largest] = temp;
            MaxHeapify(InputArray, largest, HeapSize);
        }
    }

    void SortingAlgorithms::BuildMaxHeap(int* InputArray, int ArraySize)
    {
        for(int i = ArraySize/2 - 1; i > -1 ; i--)
            MaxHeapify(InputArray,i,ArraySize);
    }

    void SortingAlgorithms::QuickSort(int* InputArray, int ArraySize)
    {
        QuickSortArray(InputArray, 0 , ArraySize - 1);
        PrintArray(InputArray, ArraySize);
    }

    void SortingAlgorithms::QuickSortArray(int* InputArray, int low, int high)
    {
        if(low < high)
        {
            int mid = RandomizedPartition(InputArray, low, high);
            QuickSortArray(InputArray, low, mid - 1);
            QuickSortArray(InputArray, mid + 1, high);
        }
    }

    int SortingAlgorithms::RandomizedPartition(int* InputArray, int low, int high)
    {
        int random = rand();
        //cout<<random<<" ";
        random = random % (high - low + 1);
        int temp = InputArray[high];
        InputArray[high] = InputArray[low + random];
        InputArray[low + random] = temp;
        int pivot = InputArray[high];
        int i,k;
        for(i = -1 , k = 0; k < high ; k++)
        {
            if(InputArray[k] <= pivot)
            {
                int temp = InputArray[i+1];
                InputArray[i+1] = InputArray[k];
                InputArray[k] = temp;
                i++;
            }
        }
        temp = InputArray[i+1];
        InputArray[i+1] = pivot;
        InputArray[high] = temp;
        return(i+1);
    }

    int SortingAlgorithms::KthOrderStatistic(int* InputArray, int ArraySize, int k)
    {
        if(k < 1)
            return(INT_MAX);
        if(k > ArraySize)
            return(INT_MAX);
        return(KthOrder(InputArray,0,ArraySize - 1,k));
    }

    int SortingAlgorithms::KthOrder(int* InputArray, int low, int high, int k)
    {
        int mid = RandomizedPartition(InputArray, low, high);
        if(mid == k-1)
            return(InputArray[mid]);
        if(mid > k-1)
            return(KthOrder(InputArray, low, mid-1,k));
        else
            return(KthOrder(InputArray,mid+1,high,k));
    }


/**
Binary search: only valid when input array is sorted;
*/
    bool SortingAlgorithms::BinarySearch(const int* InputArray, int ElementToSearch, int ArraySize)
    {
        return(BinarySearchArray(InputArray, ElementToSearch, 0 , ArraySize - 1));
    }

    bool SortingAlgorithms::BinarySearchArray(const int* InputArray, int ElementToSearch, int low, int high)
    {
  //      cout<<low<<" "<<high<<" "<<endl;
        if(low > high)
            return(false);
        int mid = (low + high)/2;
        if(InputArray[mid] == ElementToSearch)
            return(true);
        if(InputArray[mid] > ElementToSearch)
            return(BinarySearchArray(InputArray, ElementToSearch, low, mid - 1));
        else
            return(BinarySearchArray(InputArray, ElementToSearch, mid + 1, high));
    }

    void SortingAlgorithms::PrintArray(int* OutputArray, int ArraySize)
    {
        cout<<"\nSorted Array: ";
        for(int iter = 0 ; iter < ArraySize ; iter++)
        {
            cout<<OutputArray[iter]<<" ";
        }
        cout<<endl;
    }
