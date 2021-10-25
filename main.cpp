#include <iostream>
#include <list>
#include <string>
#include "read.h"
#include <fstream>

using namespace std;
/* 
I declare that all material in this assessment task is my work except where there is
clear acknowledge- mentor reference to the work of others. I further declare that I have
complied and agreed to the CMU Academic Integrity Policy at the University website.
http://www.coloradomesa.edu/student-services/document
Author’s Name: Dylan Taylor UID(700#): 700373571 Date: 10/24/21
*/


int main(int argc, char** argv){
    
    Hash hashTable(100000);

    int input, sentenceCount;
    ifstream in;
    in.open(argv[1]);
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