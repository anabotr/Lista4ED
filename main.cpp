#include "Game.hpp"
#include "Trie.hpp"

#include <iostream>
using namespace std; 

int main(int argc, char* argv[]){ 
    if (argc != 2) {
        std::cout << "Usage: ./app k prefix" << std::endl;
        return 1;
    }

    int k = std::atoi(argv[1]);

    // cout << "Titulo" << " | " << "Descricao" << " | " << "Populariedade" << cout; 



    return 0; 
} 