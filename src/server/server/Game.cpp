#include "Game.hpp"

using namespace server;
using namespace std;

Game::Game() {
}
Game::Game(int n) {
    players.push_back(make_unique<Player>("player1name"));
    players.push_back(make_unique<Player>("player2name"));
}

Player& Game::player(int id){
    if(id<0 || id>=(int)players.size())
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
    return *(players[id].get());
}

const std::vector<std::unique_ptr<Player>>& Game::getPlayers() const{
    return players;
}

int Game::addPlayer(std::unique_ptr<Player> player){
    players.push_back(std::move(player));
    return (int)players.size()-1 ;
}
/*
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
*/
