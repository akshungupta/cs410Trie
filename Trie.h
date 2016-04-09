//
// Created by Akshun Gupta on 4/9/16.
//

#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Trie {
public:
    Trie();

    ~Trie();

    void insertWord(string word);

    bool wordExists(string word);

    void printTrie();

    int numNodes;
    int numWords;
private:
    class Node{

    public:
        unordered_map<char,Node*> children;
        char character;
        bool isWord;

        Node(char character, bool isWord) {
            this->character = character;
            this->isWord = isWord;
        }
    };

    void printTrie(Node* root, vector<char> & prefix);
    void insertWord(Node* root, string word, int wordIndex);
    void printVector(vector<char> word);
    bool wordExists(Node* root, string word, int wordIndex);
    void clear(Node* root);
    Node* root;
};


#endif //TRIE_TRIE_H
