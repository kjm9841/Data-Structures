#ifndef SortingAlgorithms_h
#define SortingAlgorithms_h

/**

Class functions:    Insertion sort, selection sort, bubble sort,
                    Merge sort, Randomized quick sort, Heapsort,
                    Kth Order statistic, Binary search

*/
class SortingAlgorithms
{
public:

    SortingAlgorithms();
    void InsertionSort(int*&,int);          /**O(n^2) */
    void SelectionSort(int*,int);           /**O(n^2) */
    void BubbleSort(int*,int);              /**O(n^2) */

    void MergeSort(int*,int);              /**O(n.logn) */
    void MergeSortArray(int*, int, int);
    void Merge(int*,int,int,int);

    void HeapSort(int*, int);              /**O(n.logn) */
    void BuildMaxHeap(int*, int);
    void MaxHeapify(int*,int,int);

    void QuickSort(int*,int);              /**O(n.logn) Expected n.logn time complexity because of randomized partition*/
    int RandomizedPartition(int*, int, int);
    void QuickSortArray(int*, int, int);
    void CouuntingSort(int*,int);

    int KthOrderStatistic(int*,int,int);              /**O(n) Expected time complexity because of randomized partition*/
    int KthOrder(int*,int,int,int);

    bool BinarySearch(const int*,int, int);              /**O(logn)    Valid only when array is sorted*/
    bool BinarySearchArray(const int*, int, int, int);

    void PrintArray(int*,int);

};

#endif // SortingAlgorithms_h
