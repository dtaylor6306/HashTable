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
[]  Menu for printing whatever
    Sort:
[] quicksort
[x] heapsort of top 150
[x] heapsort lower 150
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

    //hashTable.printHash();

   int wCount = hashTable.getWordCount();

   cout << wCount << endl;

   data arr[wCount];
 

   hashTable.getTable(arr);
   
   /*for(int i = 0; i < wCount; i++){
       cout << arr[i].word << endl;

   } */

   heapSort(arr,wCount);

   //printSmallest(arr,150);
    printLargest(arr,wCount);

    return 0;
}
