#include "Game.hpp"
#include <string>
#include <mutex>

using namespace server;
using namespace std;


Game::Game(): maxP(2){

}
Game::Game(int n, bool fill): maxP(n){
    if(fill)
        for(int i=0 ; i<n ; i++){
            string name = "player" ;
            name += std::to_string(i) ;
            players[i] = make_unique<Player>(name);
        }
}

Player& Game::player(int id){
    auto ite = players.find(id);
    if (ite == players.end())
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
    return *(ite->second.get());
}


const std::map<int, std::unique_ptr<Player>>& Game::getPlayers() const{
    return players;
}

int Game::addPlayer(std::unique_ptr<Player> player){
    if(players.size()>=maxP)
        throw ServiceException(HttpStatus::OUT_OF_RESSOURCES, "Game is full");
    for(int id = 0 ; id<(int)maxP ; id++){
        auto ite = players.find(id);
        if(ite == players.end()){
            players.insert(std::make_pair(id, std::move(player)));
            return id ;
        }
    }
    throw ServiceException(HttpStatus::OUT_OF_RESSOURCES, "Game is full(2)");
}

void Game::removePlayer(int id){
    if(id<0 || id>=(int)maxP)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
    players.erase(id);
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

