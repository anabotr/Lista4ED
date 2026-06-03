#include "Trie.hpp" 
#include <iostream> 
#include <vector> 
using namespace std; 

TrieNode::TrieNode(){}
TrieNode::~TrieNode(){}

Trie::Trie(){
    this-> root = new TrieNode(); 
}

Trie::~Trie(){
    delete [] this-> root;
}

