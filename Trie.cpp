//
// Created by Akshun Gupta on 4/9/16.
//

#include "Trie.h"
#include <iostream>
using namespace std;

Trie::Trie(){
    root = new Node('#', false);
    numNodes = 0;
    numWords = 0;
}

Trie::~Trie() {
    clear(root);
}

void Trie::clear(Node* root) {
    for (auto it = root->children.begin(); it != root->children.end(); it++) {
        clear(it->second);
        delete it->second;
    }
}

void Trie::insertWord(string word) {
    insertWord(root, word, 0);
}

void Trie::insertWord(Node *root, string word, int wordIndex) {
    Node* currNode = root;
    while(wordIndex < word.length()) {
        char currChar = word[wordIndex];
        if (currNode->children.find(currChar) == currNode->children.end()) { // could not find key. need to insert new node
            bool isWord = wordIndex == (word.length() -1);
            Node* newNode = new Node(currChar, isWord);
            currNode->children[currChar] = newNode;
            currNode = newNode;
            if (isWord) {
                numWords ++;
            }
            numNodes ++;
        } else { // node has child with currChar key
            currNode = currNode->children[currChar];
        }
        wordIndex ++;
    }
}

void Trie::printVector(vector<char> vector_word) {
    string word (vector_word.begin(), vector_word.end());
    cout << word << endl;
}

void Trie::printTrie() {
    vector<char> prefix;
    printTrie(root, prefix);
}

void Trie::printTrie(Node *root, vector<char> & prefix) {
    if (root->isWord) {
        printVector(prefix);
    } else {
        for (auto it = root->children.begin(); it != root->children.end(); it++) {
            prefix.push_back(it->first);
            printTrie(it->second, prefix);
            prefix.pop_back();
        }
    }
}

bool Trie::wordExists(string word) {
    return wordExists(root, word, 0);
}

bool Trie::wordExists(Node *root, string word, int wordIndex) {
    if (wordIndex >= word.length() && root->isWord) {
        return true;
    }
    auto it = root->children.find(word[wordIndex]);
    if (it == root->children.end()){
        return false;
    } else {
        return wordExists(it->second, word, wordIndex + 1);
    }
}