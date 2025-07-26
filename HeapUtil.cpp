/*------------------------------------------------------
Name: Luke Moorhouse
Student number: 7603599
Email address: lm678@uowmail.edu.au
Subject Code: CSCI203 Data Structures and Algorithms
Campus: SWS
-------------------------------------------------------*/

#include "WordInfo.h"

/*provides the logic to maintain the heap property. This function is used to build a heap and
  also to maintain the heap property when the heap is being sorted*/
void HeapUtil::siftDown(WordInfo arr[], int size, int idx) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    // If left child is larger than root set largest to left child
    if (left < size && SortUtil::compare(arr[left], arr[largest])) {
        largest = left;
    }
    // If right child is larger than largest so far set largest to right child
    if (right < size && SortUtil::compare(arr[right], arr[largest])) {
        largest = right;
    }
    // If largest is not root swap the root with the largest element and siftDown the affected sub-tree
    if (largest != idx) {
        SortUtil::swap(arr[idx], arr[largest]);
        siftDown(arr, size, largest);
    }
}

// Builds a heap from the bottom up this is a max heap so the largest element is at the root.
// I chose to use a max heap because it is easier to sort in descending order.
void HeapUtil::buildHeap(WordInfo arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        siftDown(arr, size, i);
    }
}
