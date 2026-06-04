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
    //delete[] this -> children;
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

        if(((ascii_letra >= 97) && (ascii_letra <= 122)) 
            || 
            ((ascii_letra >= 48) && (ascii_letra <= 57))){
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
        if (indice - 97 >= 0){
            if(atual->children[indice - 97] == nullptr){ 
                temp = new TrieNode(); 
                atual->children[indice-97] = temp;
            } else {
                temp = atual -> children[indice - 97];
            }
        } else {
            if(atual->children[indice - 22] == nullptr){ 
                temp = new TrieNode(); 
                atual->children[indice-22] = temp;
            } else {
                temp = atual -> children[indice - 22];
            }     
        }
        atual = temp; 
    }

    atual->isEndOfTitle = true;
    atual->game = game;
    return true;
}

bool Trie::contains(std::string title){
    title = toSearchKey(title);

    TrieNode* atual = this->root;
    TrieNode* temp = nullptr; 
    int indice;
    
    for(int i=0; i<title.size(); i++){
        indice = title[i];
        if (indice - 97 >= 0){
            if(atual->children[indice - 97] == nullptr){ 
                return false; 
            } else {
                temp = atual -> children[indice - 97];
            }
        } else {
            if(atual->children[indice - 22] == nullptr){ 
                return false; 
            } else {
                temp = atual -> children[indice - 22];
            }
        }
        atual = temp;    
    }

    if((atual->isEndOfTitle) == false){
        return false;
    }

    return true;
}

bool Trie::isLower(Game* game1, Game* game2){
    if(game1->getPopularity() < game2->getPopularity()){
        return true;
    } else if(game1->getPopularity() > game2->getPopularity()){
        return false;
    }

    return game1->getTitle() < game2->getTitle();
}

int Trie::partition(vector<Game*>& arr, int low, int high) {
    Game* pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (true) {
        while ((left <= right) && (isLower(pivot, arr[left]))) {
            left++;
        }

        while ((left <= right) && (isLower(arr[right],pivot))){
            right--;
        }

        if (left > right) {
            break;
        }

        std::swap(arr[left], arr[right]);
    }

    std::swap(arr[low], arr[right]);

    return right;
}

void Trie::quickSort(vector<Game*>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void Trie::sortResults(std::vector<Game*>& games){
    quickSort(games, 0, games.size()-1);
}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k){
    vector<Game*> aux; 
    vector<TrieNode*> proxs;
    vector<TrieNode*> proxs_aux;
    TrieNode* atual = this->root; 
    int letra;
    bool add = false;
    bool flag = true;

    prefix = toSearchKey(prefix); 

    if(k<=0){
        return aux;
    }
    
    for(int i =0; i<prefix.size(); i++){
        letra = prefix[i];
        if(letra - 97 >= 0){ 
            if(atual->children[letra-97] != nullptr){  
                atual = atual->children[letra-97]; 
            } 
        } else if (letra - 97 < 0) {
            if(atual->children[letra-22] != nullptr){  
                atual = atual->children[letra-22]; 
            } 
        }
    }
    
    for(int j =0; j<36; j++){
        if(atual->children[j] != nullptr){
            proxs.push_back(atual->children[j]);
            add = true;
        }
    } 

    if(atual->isEndOfTitle == true){
        aux.push_back(atual->game);
    }

    while(flag){

        if(not add){
            flag = false;
        }

        add = false;
        
        for(int l = 0; l < proxs.size(); l++){
            if (proxs[l]->isEndOfTitle){
                aux.push_back(proxs[l]->game);
            }
            for(int j =0; j<36; j++){
                if(proxs[l]->children[j] != nullptr){
                    proxs_aux.push_back(proxs[l]->children[j]);
                    add = true;
                }
            } 
        }

        proxs.clear();
        proxs = proxs_aux;
        proxs_aux.clear(); 
    } 

    sortResults(aux);
    
    if (aux.size() <= k){
        return aux;
    }
    else{
        vector<Game*> copia(aux.begin(), aux.begin() + k);
        return copia;
    }
}