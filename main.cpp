#include "Game.hpp"
#include "Trie.hpp"
#include "GamesDatabase.hpp"
#include <vector> 
#include <iostream>
using namespace std; 

int main(int argc, char* argv[]){ 
    if (argc < 2) {
        cout << "Usage: ./app k prefix" << std::endl;
        return 1;
    }

    int k = atoi(argv[1]);
    k = max(k, 0);
    k = min(k, numberOfGames);

    Game* aux;
    Trie arvre; 

    for(int n = 0; n < numberOfGames; n++){
        arvre.insert(&games[n]); 
    }

    string prefix = argv[2]; 

    vector<Game*> gamesk = arvre.autocomplete(prefix, k); 

    int m = min(k, int(gamesk.size()));

    if(int(gamesk.size()) == 0){
        cout << "No results found" << endl;
        return 0; 
    } else {
        for(int j =0; j<m; j++){  
            cout << "[" << gamesk[j]->getTitle() << " | " << gamesk[j]->getShortDescription() << " | " << gamesk[j]->getPopularity() << endl;
        }
    }

    return 0; 
} 