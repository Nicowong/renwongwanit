#include <iostream>

#include "AttackCommand.h"

#include "rules.h"

using namespace std;
using namespace state;
using namespace engine;

extern const int dmgRule[22*22];
extern const int maxRangeRule[22];
extern const int minRangeRule[22];
extern const int moveRangeRule[22];

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
    int ax = attacker.getX();
    int ay = attacker.getY();
    int dx = defender.getX();
    int dy = defender.getY();

    int dist = abs(dx-ax)+abs(dy-ay);

    UnitType aT = attacker.getUnitType() ;
    UnitType dT = defender.getUnitType() ;

    if( attacker.getTeam()!=defender.getTeam() && dmgRule[aT*22+dT]!=0 && attacker.getAmmo()>0 &&
        minRangeRule[aT]<=dist && dist<=maxRangeRule[aT] ){

        defender.setHealth(defender.getHealth()- dmgRule[aT*22+dT]*attacker.getHealth()/100);
        if(defender.getHealth()>0 && defender.getAmmo()>0 && dist==1)
            attacker.setHealth(attacker.getHealth()- dmgRule[dT*22+aT]*defender.getHealth()/100);    
        attacker.setAmmo(attacker.getAmmo()-1);
    }else {
        std::cout<<"In engine::AttackCommand::execute() : error"<<std::endl;
    }
    attacker.setMoved(true);
    attacker.setAvailable(false);
}