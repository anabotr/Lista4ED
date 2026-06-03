#include "Trie.hpp" 
#include <iostream> 
#include <vector> 
using namespace std; 

TrieNode::TrieNode(){
    for(int i = 0; i<36; i++){
        this->children[i] = nullptr;
    }
    this -> isEndOfTitle = false;
    this -> game = nullptr;
}

TrieNode::~TrieNode(){
    // apagar? são só 36. 
    delete[] this -> children;
}

Trie::Trie(){
    this-> root = new TrieNode(); 
}

Trie::~Trie(){
    delete this-> root;
}
string Trie::toSearchKey(std::string text){
    string convertido; 
    char letra;
    int ascii_letra;
    
    for(int i = 0; i<text.size(); i++){
        letra = text[i];
        ascii_letra = letra;
        if(((ascii_letra >= 97) && (ascii_letra <= 122)) || ((ascii_letra >= 48) && (ascii_letra <= 57))){
            letra = char(ascii_letra);
            convertido += letra; 
        } else if((ascii_letra >= 65) && (ascii_letra <= 90)){
            ascii_letra += 32; 
            letra = char(ascii_letra);
            convertido += letra; 
        } 
    }
    return convertido;
}

bool Trie::insert(Game* game){
    string nome = game->getTitle();
    nome = this->toSearchKey(nome);
    TrieNode* atual = this->root;
    TrieNode* temp = nullptr; 
    int indice;

    for(int i=0; i<nome.size(); i++){
        indice = nome[i];
        if(atual->children[indice - 97] == nullptr){
            temp = new TrieNode();
            atual->children[indice-97] = temp;
        } else {
            temp = atual -> children[indice - 97];
        }     
        atual = temp;   
    }
    atual->isEndOfTitle = true;
    atual->game = game;
    return true;
}

bool Trie::contains(std::string title){
    TrieNode* atual = this->root;
    TrieNode* temp = nullptr; 
    int indice;
    
    for(int i=0; i<title.size(); i++){
        indice = title[i];
        if(atual->children[indice - 97] == nullptr){
            return false;
        } else {
            temp = atual -> children[indice - 97];
        }     
        atual = temp;   
    }
    if(atual->isEndOfTitle == false){
        return false;
    }
    return true;
}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k){

}

void Trie::sortResults(std::vector<Game*>& games){

}
