#include <iostream>
#include <fstream>
using namespace std;

#include "Trie.h"

void createDictionary(Trie & trie) {
    string line;
    ifstream myfile ("/Users/akshungupta/ClionProjects/Trie/words.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            trie.insertWord(line);
        }
        myfile.close();
    }

    else cout << "Unable to open file";
}

int main() {
    Trie trie;
    createDictionary(trie);
 }