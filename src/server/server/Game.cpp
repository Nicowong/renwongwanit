#include "Game.h"

using namespace server;
using namespace std;

Game::Game() :places(1) {
    
}

Player& Game::player(int id){
    return players[id];
}

int Game::addPlayer(unique_ptr<Player> player){
    int id =  places++;
    players.insert(std::make_pair(id,std::move(player)));
    return id;
}

void Game::removePlayer(int id){
    auto ite = players.find(id);
    if(ite == players.end())
        return;
    players.erase(ite);
}

const std::vector<Player> Game::getPlayers() const{
    return players;
}

void Game::setPlayers(const std::vector<Player>& players){
    this->players=players;
}

int Game::getPlaces() const{
    return places;
}

void Game::setPlaces(int places){
    this->places = places;
}