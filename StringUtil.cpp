/*------------------------------------------------------
Name: Luke Moorhouse
Student number: 7603599
Email address: lm678@uowmail.edu.au
Subject Code: CSCI203 Data Structures and Algorithms
Campus: SWS
-------------------------------------------------------*/

#include "WordInfo.h"

/* Compares two strings. Returns 0 if they are equal, a positive number if str1 is greater than str2, and a negative
   number if str2 is greater than str1.*/
int StringUtil::stringCompare(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }
    return static_cast<int>(*str1) - static_cast<int>(*str2);
}

// Copies the contents of src into dest (including the null character) and returns destination string
void StringUtil::stringCopy(char* dest, const char* src) {
    while (*src) {
        *dest = *src;
        ++src;
        ++dest;
    }
    // this is to add the null character at the end of the string to make it a valid string
    *dest = '\0';
}

// Returns the length of the string (excluding the null character)
int StringUtil::stringLen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}
