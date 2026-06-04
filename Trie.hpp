#ifndef TRIE_HPP
#define TRIE_HPP

#include "Game.hpp"
#include "GamesDatabase.hpp"

#include <string>
// Permitido para armazenar e retornar os resultados
#include <vector> 
using namespace std; 

int const ALPHABET_SIZE = 36;

class TrieNode {

public:

    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfTitle;
    Game* game;

    TrieNode();
    ~TrieNode();
};


class Trie {

private:
    TrieNode* root;

public:

    Trie();
    ~Trie();

    bool insert(Game* game);
    bool contains(string title);
    bool isGreater(Game* game1, Game* game2); 
    int partition(vector<Game*>& arr, int low, int high);
    void quickSort(vector<Game*>& arr, int low, int high); 

    vector<Game*> autocomplete(std::string prefix, int k);

    string toSearchKey(string text);
    void sortResults(vector<Game*>& games);
    
    // Outros métodos auxiliares, se necessário
};

#endif