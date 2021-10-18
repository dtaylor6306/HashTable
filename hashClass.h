#include <string>
#include <list>
#include <iostream>
using namespace std;

struct data{
        int counter = 1;
        string word;
};

class Hash{

private:
    int uniqueWordCount = 0;
    int SIZE;


    list <data> *table;
    int hash(string word){
        int hashed = (int)word[0] % SIZE;

        //cout << hashed << endl;

        return hashed;
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
        
        if(table[pos].empty()){
            data d;
            d.word = newWord;
            table[pos].push_back(d);
            uniqueWordCount++;
           // cout << "added " << newWord << endl;
        }
        else{
            list<data>::iterator it;
            for(it = table[pos].begin(); it != table[pos].end(); ++it){

                if(it->word == newWord){
                    it->counter++;
                   // cout << "increased counter" << endl;
                    break;
                }
            }
            if(it == table[pos].end()){
                data d;
                d.word = newWord;
                table[pos].push_back(d);
                uniqueWordCount++;

                //cout << "added new word" << endl;
            }
        }
    }

    void printHash(){
        for(int i = 0; i < SIZE; i++){
            list<data>::iterator it;
            for (it = table[i].begin(); it != table[i].end(); ++it){
                cout << i << " " << it->word << " " << it->counter << endl;
            }
        }
    }

    bool findValue(string searchedWord){
        int key = hash(searchedWord);
        list<data>::iterator it;
        for (it = table[key].begin(); it != table[key].end(); ++it){
            if(it->word == searchedWord) return true;
        }
        return false;
    }

    int getWordCount(){
        return uniqueWordCount;
    }

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
};
