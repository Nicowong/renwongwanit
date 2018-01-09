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

void Game::removePlayer(int id){
    if(id<0 || id>=(int)players.size())
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
    players.erase(players.begin()+id);
}

void Game::setPlayer(std::unique_ptr<Player> player, int id){
    if(id<0 || id>=(int)players.size())
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
    players[id] = std::move(player);
}