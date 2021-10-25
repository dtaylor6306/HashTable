#include <iostream>
#include <list>
#include <string>
#include "read.h"
#include <fstream>
#include <chrono>
using namespace std::chrono;

using namespace std;

/* 
I declare that all material in this assessment task is my work except where there is
clear acknowledge- mentor reference to the work of others. I further declare that I have
complied and agreed to the CMU Academic Integrity Policy at the University website.
http://www.coloradomesa.edu/student-services/document
Author’s Name: Dylan Taylor UID(700#): 700373571 Date: 10/24/21
*/

/* TODO 
[x] Setup hash table
    Input:
[x] Read input
[x] Remove punct
[x] change to lower
[x] add to hash
[x]  Menu for printing whatever
    Sort:
[x]  Size test w/ runtime
[x] heapsort of top 150
[x] heapsort lower 150
[x] count sentences

*/


int main(){


    //creates hashtable
    Hash hashTable(100000);

    int input, sentenceCount;
    ifstream in;
    in.open("AScandalInBohemia.txt");
    //reading input and storing number of sentences
    sentenceCount = readInput(in, hashTable);
    //gets how many uniquewords are in the hash table
    int wCount = hashTable.getWordCount();
    //array to sort occurrences
    data arr[wCount];

    //sets up the array with hash data
    hashTable.getTable(arr);
    //Sorts array
    // auto start = high_resolution_clock::now();
    heapSort(arr,wCount);
   // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<milliseconds>(stop - start);
    // cout << "Time elapsed: " << duration.count() << " milliseconds." << endl;
    string searchWord;

    //Basic menu
    while (true)
    {   cout << "Please choose and option and enter an appropriate number." << endl;
        cout << "0 to exit.\n"
             << "1 to print hash table.\n"
             << "2 to print the smallest 150 elements.\n"
             << "3 to print the largest 150 elements.\n"
             << "4 to print the amount of sentences.\n"
             << "5 to print number of unique words.\n"
             << "6 to search for a word. \n"
             << "7 to see collision rate of this hash\n";
        cin >> input;

        switch(input){
            case 0: exit(1);
            case 1: hashTable.printHash();
                break;
            case 2: printSmallest(arr,150);
                break;
            case 3: printLargest(arr, wCount);
                break;
            case 4: cout << "There are " << sentenceCount << " sentences." << endl;
                break;
            case 5: cout << "There are " << wCount << " unique words." << endl;
                break;
            case 6: cout << "\nInput a word to search for." << endl;
                    cin >> searchWord;
                    hashTable.findWord(searchWord);
                break;
            case 7: hashTable.printCR();
                break;
        }
        cout << endl;
    }


    return 0;
}
