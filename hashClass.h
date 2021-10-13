#include <string>
#include <list>
#include <iostream>
using namespace std;
class Hash{

private:

    int SIZE;

    struct data{
        int counter = 1;
        string word;
    };

    list <data> *table;
    int hash(string word){
        int hashed = (int)word[0] + (int)word[1] % SIZE;

        //cout << hashed << endl;

        return hashed;
    }

public:
    Hash(int newSIZE){
        SIZE = newSIZE;
        table = new list<data>[SIZE];
    }

    void insert(string newWord){
        //[] hash to find pos
        //[] if data in pos then counter ++
        //[] else create new data and push back
        int pos = hash(newWord);
        
        if(table[pos].empty()){
            data d;
            d.word = newWord;
            table[pos].push_back(d);
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

                //cout << "added new word" << endl;
            }
        }
    }
    void findValue(string word){
        //word = word.to_lower();
        int pos = hash(word);
        list<data>::iterator it;
        for (it = table[pos].begin(); it != table[pos].end(); ++it){
              
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
};

