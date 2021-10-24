#include <string>
#include <list>
#include <iostream>
#include "heap.h"
using namespace std;

class Hash{

private:
    //Used to count how many words, can be used to get an array size.
    int uniqueWordCount = 0;
    //Used to create the size of the hash table.
    int SIZE;
    //Used to calculate occupancy/collision rate or cr.
    int cr = 0;

    //The main data structure an array of lists.
    list <data> *table;
    //Basic hash function.
    int hash(string word){
        int hashed = 0;
        int multiplier = 1;
        for(int i = 0; i < word.length(); i++){
            hashed += (int)word[i] * multiplier;
            multiplier +=13;
        }
        hashed = abs(hashed);
        hashed = hashed % SIZE;
        return hashed;
    }
    //formats a string to lower case, will not remove punct however which might be an oversight.
    void formatString(string & word){
        for(int i = 0; i < word.length(); i++){
            word[i] = tolower(word[i]);
        }
    }

public:
    Hash(int newSIZE){
        SIZE = newSIZE;
        table = new list<data>[SIZE];
    }

    void insert(string newWord){
        //[x] hash to find pos
        //[x] if data in pos then counter ++
        //[x] else create new data and push back
        int pos = hash(newWord);
        
        //If empty create a new struct and make it the first element of the list
        if(table[pos].empty()){
            data d;
            d.word = newWord;
            table[pos].push_back(d);
            uniqueWordCount++;
        } //else there are elements in the list so we need to check for the word.
        else{
            list<data>::iterator it;
            for(it = table[pos].begin(); it != table[pos].end(); ++it){
                //if found in the list just increment the counter
                if(it->word == newWord){
                    it->counter++;
                    break;
                }
            } //if it has gone through the list w/o finding the element then create a new data struct
            if(it == table[pos].end()){
                data d;
                d.word = newWord;
                table[pos].push_back(d);
                uniqueWordCount++;
                cr++;
            }
        }
    }
    //Will print the whole hash
    void printHash(){
        for(int i = 0; i < SIZE; i++){
            list<data>::iterator it;
            for (it = table[i].begin(); it != table[i].end(); ++it){
                cout << i << " " << it->word << " " << it->counter << endl;
            }
        }
    }
    //Converts word to lower
    //then attempts to find the word
    void findWord(string searchedWord){
        formatString(searchedWord);
        int key = hash(searchedWord);
        list<data>::iterator it;
        bool isFound = false;
        for (it = table[key].begin(); it != table[key].end(); ++it){
            if(it->word == searchedWord){
                isFound = true;
                break;
            }
        }
        if(isFound){
            cout << it->word << " " << it->counter << endl;
        }
        else{
            cout << "The word:" << searchedWord << " was not found." << endl;
        }
        
    }
    //Every time a new word is created, uniqueWordCount is incremented.
    int getWordCount(){
        return uniqueWordCount;
    }
    //Outputs hash tabe to an array.
    void getTable(data (&arr)[]){
        
        list<data>::iterator it;
        int j = 0;
        for(int i = 0; i < SIZE; i++){
            if(!table[i].empty()){
                for(it = table[i].begin(); it != table[i].end(); it++){
                    arr[j].word = it->word;
                    arr[j].counter = it->counter;
                    j++;

                }
            }

        }
        
    }

   void printCR(){
       double rate = (double)cr/(double)uniqueWordCount;
       rate = rate * 100;
       cout << (int)rate << "%" << endl;
   }
};
