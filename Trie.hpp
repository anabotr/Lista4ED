#ifndef TRIE_HPP
#define TRIE_HPP

#include "Game.hpp"
#include "GamesDatabase.hpp"

#include <string>
// Permitido para armazenar e retornar os resultados
#include <vector> 

int const ALPHABET_SIZE = 26;

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
    bool contains(std::string title);

    std::vector<Game*> autocomplete(std::string prefix, int k);

    std::string toSearchKey(std::string text);
    void sortResults(std::vector<Game*>& games);

    // Outros métodos auxiliares, se necessário
};

#endif