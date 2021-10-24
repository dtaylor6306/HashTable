#include <iostream>
#include <string>
#include "hashClass.h"
#include <fstream>
#include <sstream>

using namespace std;


int readInput(ifstream &in,Hash &hashTable){
    string line;
    string word;
    int sentenceCount = 0;
    while(!in.eof()){
        
        getline(in, line);
        //Takes input and takes out punct, makes lower case, and counts sentences.
        
        // This method of sentence counting will not work as well as it should as 
        // the word Mr. , Dr. and such will register as a sentence end.
        // Also accents do not work well with tolower() or rather basic strings.
        // This can be fixed with wstring as it is for the most part unicode.
        for (int i = 0, len = line.size(); i < len; i++)
        {   
            if(line[i] == '.' || line[i] == '!' || line[i] == '?'){
                sentenceCount++;
            }

            if (ispunct(line[i]))
            {
                line.erase(i--, 1);
                len = line.size();
            }
           line[i] = tolower(line[i]);
        }
        stringstream ss(line);
        //inserts every word in this newly changed line into the hash table.
        while(ss >> word){
           hashTable.insert(word);
        }
    }
    return sentenceCount;
}