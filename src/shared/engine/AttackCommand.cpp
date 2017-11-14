#include "AttackCommand.h"

using namespace std;
using namespace state;
using namespace engine;

AttackCommand::AttackCommand(state::Unit& attacker, state::Unit& defender):
    attacker(attacker), defender(defender){
    
    
}

state::Unit& AttackCommand::getAttacker() const{
    return attacker;
}

void AttackCommand::setAttacker(const state::Unit&& attacker){
    this->attacker=attacker;
}

state::Unit& AttackCommand::getDefender() const{
    return defender;
}

void AttackCommand::setDefender(const state::Unit&& defender){
    this->defender=defender;
}

CommandTypeId AttackCommand::getCommandTypeId() const{
    return COM_ATTACK;
}


void AttackCommand::execute(state::State& state){
    defender.setHealth(defender.getHealth()-10);
}