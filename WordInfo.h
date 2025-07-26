/*------------------------------------------------------
Name: Luke Moorhouse
Student number: 7603599
Email address: lm678@uowmail.edu.au
Subject Code: CSCI203 Data Structures and Algorithms
Campus: SWS
-------------------------------------------------------*/
// include guard
#pragma once

/* A Structure, designed to store the word and its count, it has been chosen over using classes as structs are
 * defaulted to public.  */
struct WordInfo {
    char *word;
    int count;
};

/* A class that contains functions to manipulate strings */
class StringUtil {
public:
    static int stringCompare(const char* str1, const char* str2);
    static void stringCopy(char* dest, const char* src);
    static int stringLen(const char* str);
};

/* A class that contains functions to sort the array of WordInfo structs */
class SortUtil {
public:
    static bool compare(const WordInfo& a, const WordInfo& b);
    static void swap(WordInfo& a, WordInfo& b);
    static void heapSort(WordInfo arr[], int size);
    static void alphabeticalSort(WordInfo arr[], int size);
};

/* A class that contains functions to manipulate the heap */
class HeapUtil {
public:
    static void siftDown(WordInfo arr[], int size, int idx);
    static void buildHeap(WordInfo arr[], int size);
};