/*------------------------------------------------------
Name: Luke Moorhouse
Student number: 7603599
Email address: lm678@uowmail.edu.au
Subject Code: CSCI203 Data Structures and Algorithms
Campus: SWS
-------------------------------------------------------*/

#include "WordInfo.h"

/* Compares two WordInfo structs. Returns true if a is greater than b, false otherwise, if they are equal it compares
alphabetically */
bool SortUtil::compare(const WordInfo &a, const WordInfo &b) {
    if (a.count > b.count) {
        return true;
    } else if (a.count < b.count) {
        return false;
    } else {
        return StringUtil::stringCompare(a.word, b.word) < 0; // Compare alphabetically
    }
}

// Swaps two WordInfo structs in the array of WordInfo structs
void SortUtil::swap(WordInfo &a, WordInfo &b) {
    WordInfo temp = a;
    a = b;
    b = temp;
}


// Sorts the array of WordInfo structs in descending order by count
void SortUtil::heapSort(WordInfo arr[], int size) {
    HeapUtil::buildHeap(arr, size);
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        HeapUtil::siftDown(arr, i, 0);
    }
}


/* Sorts the array of WordInfo structs in alphabetical order by word
 * This function is only used to sort the bottom 10 words alphabetically
 * because the heap sort sorts the words in descending order by count */
void SortUtil::alphabeticalSort(WordInfo arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (StringUtil::stringCompare(arr[i].word, arr[j].word) > 0) {
                swap(arr[i], arr[j]);
            }
        }
    }
}