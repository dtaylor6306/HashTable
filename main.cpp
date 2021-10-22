#include <iostream>
#include <list>
#include <string>
#include "read.h"
#include <fstream>

using namespace std;


int main(){
    
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

    hashTable.printHash();
}