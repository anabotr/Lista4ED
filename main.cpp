#include "Game.hpp"
#include "Trie.hpp"
#include "GamesDatabase.hpp"
#include <vector> 
#include <iostream>
using namespace std; 

int main(int argc, char* argv[]){ 
    if (argc < 2) {
        std::cout << "Usage: ./app k prefix" << std::endl;
        return 1;
    }

    Trie* arvre = new Trie(); 
    Game* p = &games[0];
    cout << p->getTitle() << endl; 
    
    for(int i =0; i<numberOfGames; i++){
        arvre->insert(&games[i]);
    }

    int k = std::atoi(argv[1]);
    string prefix = argv[2]; 
    prefix = arvre->toSearchKey(prefix);

    bool a = arvre->contains(prefix); 
    cout << a << endl; 

    // cout << "Titulo" << " | " << "Descricao" << " | " << "Populariedade" << cout; 

    return 0; 
} 