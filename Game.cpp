#include "Game.h"

using namespace std;
using namespace server;

const std::vector<Player>& Game::getPlayers() const{
    return players;
}

void Game::setPlayers(const std::vector<Player>& players){
    this->players = Players;
}