#include <iostream>
#include "hashClass.h"
#include <list>
#include <string>

using namespace std;

struct data{
    string word;
    int count = 1;
};

int main(){
/*
    list <data> items[10];

    for(int i = 0; i < 10; i++){
        data d;
        d.count = 4;
        d.word = "hello";
        items[i].push_back(d);
    }

    data k;
    k.count = 9;
    k.word = "another one";
    items[0].push_back(k);
    
for(int i = 0; i < 10; i++){
    std::list<data>::iterator it;
    for (it = items[i].begin(); it != items[i].end(); ++it){
        std::cout << it->word << " " << it->count << endl;
    }

}
 */

    Hash hashTable(10);

    hashTable.insert("abc");
    hashTable.insert("abc");
    hashTable.insert("abc");
    hashTable.insert("bcd");
    hashTable.insert("bcd");
    hashTable.insert("cde");
    hashTable.insert("def");
    hashTable.insert("efg");
    hashTable.insert("abbe");
    hashTable.printHash();

    return 0;
}