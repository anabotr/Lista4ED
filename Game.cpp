#include "Game.hpp" 
#include <iostream> 
using namespace std; 

Game::~Game(){}

Game::Game(){}

Game::Game(std::string title, std::string shortDescription, int popularity){
    this->title = title;
    this->shortdescription = shortDescription;
    this->popularity = popularity;
}

string Game::getTitle(){
    return this->title; 
}

string Game::getShortDescription(){
    return this->shortdescription; 
}

int Game::getPopularity(){
    return this->popularity; 
}
