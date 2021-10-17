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
    Sort:
[] quicksort
[] heapsort of top 150
[] heapsort lower 150
[x] count sentences

*/


int main(){


    Hash hashTable(1000);


    ifstream in;
    in.open("A Scandal In Bohemia.txt");
    //in.open("test.txt");
    
    int sentenceCount;

    sentenceCount = readInput(in, hashTable);
    cout << sentenceCount << endl;

    hashTable.printHash();

   int wCount = hashTable.getWordCount();

   cout << wCount << endl;



    

    return 0;
}
