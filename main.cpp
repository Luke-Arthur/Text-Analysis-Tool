/*------------------------------------------------------
Name: Luke Moorhouse
Student number: 7603599
Email address: lm678@uowmail.edu.au
Subject Code: CSCI203 Data Structures and Algorithms
Campus: SWS
-------------------------------------------------------*/

//============================ Includes ===============================================================================
#include <iostream>
#include <fstream>
#include "WordInfo.h"
//============================Driver function=========================================================================

/* This function is used to print the top 10 words in descending order by count
 * and the bottom 10 words in alphabetical order by word it then prints all the
 * words that have a value of 1 as they are all the "unique words" in the file. */
int main() {
    char filename[200];
    std::cout << "Enter the name of the text file: ";
    std::cin >> filename;
    std::cout << std::endl;
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    /* Creates an array of WordInfo structs to store the words and their counts in the file and a counter to keep track
    of how many words are in the array and the size of the array */
    const int maxWords = 50000;
    WordInfo wordInfoList[maxWords];
    int wordCount = 0;

    char word[50];

    // Reads the file in and stores the words and their counts in the array of WordInfo structs
    while (inputFile >> word) {
        char cleanedWord[50] = "";
        int cleanedWordIdx = 0;
        // Removes all non-alphabetic characters from the word
        for (char *p = word; *p; ++p) {
            if (std::isalpha(*p)) {
                cleanedWord[cleanedWordIdx++] = std::tolower(*p);
            }
        }

        /* If the word is not empty, add it to the wordInfoList, if it is already in the list increment its count.
         * otherwise add it to the list */
        if (cleanedWordIdx > 0) {
            // Add null terminator to the end of the word
            cleanedWord[cleanedWordIdx] = '\0';
            bool found = false;
            // Loop through the wordInfoList
            for (int i = 0; i < wordCount; ++i) {
                // If the word is already in the wordInfoList, increment its count
                if (StringUtil::stringCompare(cleanedWord, wordInfoList[i].word) == 0) {
                    wordInfoList[i].count++;
                    found = true;
                    break;
                }
            }// If the word is not already in the wordInfoList, add it to the wordInfoList
            if (!found) {
                // Add the word to the wordInfoList
                wordInfoList[wordCount].word = new char[StringUtil::stringLen(cleanedWord) + 1];
                // Copy the word into the wordInfoList and set its count to 1 and increment the wordCount
                StringUtil::stringCopy(wordInfoList[wordCount].word, cleanedWord);
                wordInfoList[wordCount].count = 1;// Increment the wordCount
                wordCount++;
            }
        }
    }
    // Sort the wordInfoList in descending order by count
    SortUtil::heapSort(wordInfoList, wordCount);
    // Close the file
    inputFile.close();
    // Display the top 10 words
    std::cout << "Top 10 words:" << std::endl;
    for (int i = wordCount - 1; i >= std::max(0, wordCount - 10); --i) {
        std::cout << wordInfoList[i].word << ": " << wordInfoList[i].count << std::endl;
    }

    // Display the bottom 10 words
    std::cout << "\nBottom 10 words:" << std::endl;
    //initialise an array of WordInfo structs to store the bottom 10 words
    WordInfo bottomWords[10];
    int currentCount = wordInfoList[0].count;
    int index = 0;
    // Loop through the wordInfoList and add the words with the lowest count to the bottomWords array
    for (int i = 0; i < wordCount && index < 10; ++i) {
        // If the current word has the same count as the previous word, add it to the bottomWords array
        if (wordInfoList[i].count == currentCount) {
            bottomWords[index++] = wordInfoList[i];
        } else {
            break;  // Since we only want the words with the lowest count.
        }
    }

// Sort bottomWords alphabetically
    SortUtil::alphabeticalSort(bottomWords, index);

// Display the sorted bottom words
    for (int i = 0; i < index; ++i) {
        std::cout << bottomWords[i].word << ": " << bottomWords[i].count << std::endl;
    }


// Find the unique words in the file and store them in an array of WordInfo structs called uniqueWords
    WordInfo uniqueWords[maxWords];
    int uniqueWordCount = 0;
    // Loop through the wordInfoList and add the words with a count of 1 to the uniqueWords array
    for (int i = 0; i < wordCount; ++i) {
        if (wordInfoList[i].count == 1) {
            uniqueWords[uniqueWordCount++] = wordInfoList[i];
        }
    }

// Sort the unique words array alphabetically
    SortUtil::alphabeticalSort(uniqueWords, uniqueWordCount);

    // Display the unique words
    std::cout << "\nUnique words:" << std::endl;
    for (int i = 0; i < uniqueWordCount; ++i) {
        std::cout << uniqueWords[i].word << std::endl;
        delete[] uniqueWords[i].word;
    }
    // Display the number of unique words
    std::cout << "\nThere are " << uniqueWordCount << " unique words in your file." << std::endl;


    return 0;
}

//=========================== End of program =========================================================================


