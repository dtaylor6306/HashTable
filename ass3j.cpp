#include <iostream>
#include "hashClass.h"
#include <list>
#include <string>

using namespace std;

/* TODO 
[x] Setup hash table
    Input:
[] Read input
[] Remove punct
[] change to lower
[] add to hash
    Sort:
[] quicksort
[] heapsort of top 150
[] heapsort lower 150
[] count sentences

*/

struct data{
    string word;
    int count = 1;
};

int main(){


    Hash hashTable(1000);
    //tolower()
    hashTable.insert("abc");
    hashTable.insert("abc");
    hashTable.insert("abc");
    hashTable.insert("bcd");
    hashTable.insert("bcd");
    hashTable.insert("cde");
    hashTable.insert("def");
    hashTable.insert("efg");
    hashTable.insert("abbe");
    hashTable.insert("zop");
    hashTable.insert("this");
    hashTable.insert("cat");
    hashTable.insert("Cat");
    bool istrue = hashTable.findValue("Cat");

    hashTable.printHash();
    cout << istrue << endl;

    istrue = hashTable.findValue("bbuubaiib");

    cout << istrue << endl;

    cout << hashTable.getWordCount() << endl;

    return 0;
}