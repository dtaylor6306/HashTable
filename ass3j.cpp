#include <iostream>
//#include "hashClass.h"
#include <list>
#include <string>
#include "read.h"
#include <fstream>

using namespace std;

/* TODO 
[x] Setup hash table
    Input:
[x] Read input
[x] Remove punct
[x] change to lower
[x] add to hash
[x]  Menu for printing whatever
    Sort:
[]  Size test w/ runtime
[x] heapsort of top 150
[x] heapsort lower 150
[x] count sentences

*/


int main(){

    //creates hashtable
    Hash hashTable(3000);

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
    heapSort(arr,wCount);
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
             << "6 to search for a word. \n";
        cin >> input;

        switch(input){
            case 0: system("CLS");
                exit(1);
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
        }
        cout << endl;
    }


    return 0;
}
