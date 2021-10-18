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
        
        while(ss >> word){
           hashTable.insert(word);
        }
    }
    return sentenceCount;
}