// CPP program to implement hashing with chaining
#include<bits/stdc++.h>
using namespace std;

class Hash
{
    struct item{
        int count = 0;
        string word;
    };

	int BUCKET; // No. of buckets

	// Pointer to an array containing buckets
	list<item> *table;
public:
	Hash(int V); // Constructor

	// inserts a key into hash table
	void insertItem(int x, string w);

	// deletes a key from hash table
	void deleteItem(int key);

	// hash function to map values to key
	int hashFunction(int x) {
		return (x % BUCKET);
	}

	void displayHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<item>[BUCKET];
}

void Hash::insertItem(int key, string word)
{
	int index = hashFunction(key);
    item i;
    i.word = word;
    i.count++;
	table[index].push_back(i);
}

void Hash::deleteItem(int key)
{
// get the hash index of key
int index = hashFunction(key);

// find the key in (index)th list
list <item> :: iterator i;
for (i = table[index].begin();
		i != table[index].end(); i++) {
	if (*i == )
	break;
}

// if key is found in hash table, remove it
if (i != table[index].end())
	table[index].erase(i);
}

// function to display hash table
void Hash::displayHash() {
for (int i = 0; i < BUCKET; i++) {
	cout << i;
	for (auto x : table[i])
	cout << " --> " << x;
	cout << endl;
}
}



std::string RemoveWords(const std::string& source, const std::string& chars) {
    std::string result="";
    for (unsigned int i=0; i<source.length(); i++) {
      bool foundany=false;
      for (unsigned int j=0; j<chars.length() && !foundany; j++) {
        foundany=(source[i]==chars[j]);
      }
      if (!foundany) {
        result+=source[i];
      }
    }
   return result;
}

int number_of_sentences = 0;
text = RemoveWords("Mrs. lady is a lady", "Mrs.");
for(unsigned int i=0; i <= text.length()-1; i++){
  if(text[i] == '.' || text[i] == '?' ||text[i] == '!'){
  ++number_of_sentences;
  }
}
return number_of_sentences;
