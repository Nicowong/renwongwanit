#include "Game.hpp"
#include <string>

using namespace server;
using namespace std;

Game::Game(): maxP(2) {

}
Game::Game(int n, bool fill): maxP(n) {
    if(fill)
        for(int i=0 ; i<n ; i++){
            string name = "player" ;
            name += std::to_string(i) ;
            players.push_back(make_unique<Player>(name));
        }
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
    if(players.size()>=maxP)
        throw ServiceException(HttpStatus::OUT_OF_RESSOURCES, "Game is full");
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

const size_t& Game::getMaxP() const{
    return maxP ;
}
void Game::setMaxP(const size_t& maxP){
    this->maxP = maxP ;
}
