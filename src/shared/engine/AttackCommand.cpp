#include "AttackCommand.h"
#include <iostream>
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
    //determining the distance between 2 elements is available for attacking
    //and determining that  they are in 2 team
    if((attacker.getX()-defender.getX())<2 &&
       (attacker.getY()-defender.getY())<2 && attacker.getTeam()!=defender.getTeam()){
        
        defender.setHealth(defender.getHealth()-10);
        
        
    }else {
        std::cout<<"In engine::AttackCommand::execute() : error"<<std::endl;
    }
    
}