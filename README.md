# How to Compile and Run the Text Analysis Tool

Requirements:
- C++ compiler (like g++)
- Source files (main.cpp, StringUtil.cpp, SortUtil.cpp, HeapUtil.cpp, etc.)
- A text file to analyse (e.g. sample-long.txt)

Steps:

1. Open a terminal and navigate to the folder with your source files.

2. Compile the program:

   g++ -o text-analyzer main.cpp StringUtil.cpp SortUtil.cpp HeapUtil.cpp

3. Run the program:

   ./text-analyzer

4. When prompted, enter the name of a text file:

   Please enter the filename:
   sample-long.txt

The program will then display:
- Top 10 most common words
- Bottom 10 least common words
- List of all unique words


# Sample Output

Top 10 words:
1. the – 185
2. and – 99
3. to – 86
4. of – 83
5. he – 74
6. a – 71
7. his – 63
8. was – 59
9. in – 55
10. that – 52

Bottom 10 words:
1. anxiously – 1
2. acquaintance – 1
3. acquaintance's – 1
4. actual – 1
5. advantage – 1
6. affectionate – 1
7. agitation – 1
8. aloud – 1
9. amusement – 1
10. anticipated – 1

Unique Words (total: 364):
abandoned, ability, able, above, absolutely, ... (truncated)
