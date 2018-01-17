#include <iostream>

#include "json/json.h"
#include "json/json-forwards.h"

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
    attId(attacker.getId()), defId(defender.getId()),
    attacker(attacker), defender(defender){
}

AttackCommand::AttackCommand(state::State& state, int attId, int defId):
    attId(attId), defId(defId),
    attacker(*(state.getUnitId(attId))), defender(*(state.getUnitId(defId))){
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
    cout << "attack execute " << endl ;
    int ax = attacker.getX();
    cout << "ax:"<<ax ;
    int ay = attacker.getY();
    cout << "ay:"<<ay ;
    int dx = defender.getX();
    int dy = defender.getY();

    int dist = abs(dx-ax)+abs(dy-ay);

    UnitType aT = attacker.getUnitType() ;
    UnitType dT = defender.getUnitType() ;

    cout << "Command attack : " << endl ;
    cout << "attacker : " ;
    attacker.debug(1);
    cout << "defender : " ;
    defender.debug(1);

    if( attacker.getTeam()!=defender.getTeam() && dmgRule[aT*22+dT]!=0 && attacker.getAmmo()>0 &&
        minRangeRule[aT]<=dist && dist<=maxRangeRule[aT] ){

        cout << "attack phase ; "  ;
        defender.setHealth(defender.getHealth()- dmgRule[aT*22+dT]*attacker.getHealth()/100);
        if(defender.getHealth()>0 && defender.getAmmo()>0 && dist==1 && minRangeRule[dT]<=1){
            attacker.setHealth(attacker.getHealth()- dmgRule[dT*22+aT]*defender.getHealth()/100);
            cout << "defend phase"<<endl ;
        }
        attacker.setAmmo(attacker.getAmmo()-1);
    }else {
        std::cout<<"In engine::AttackCommand::execute() : error ";
        if(attacker.getTeam()==defender.getTeam())
            cout << "same team" <<endl ;
        if(dmgRule[aT*22+dT]==0)
            cout << "attacker has no attack" << endl ;
        if(attacker.getAmmo()<=0)
            cout << "attacker has no ammo"<< endl ;
        if(minRangeRule[aT]>dist)
            cout << "range is too close" << endl ;
        if(maxRangeRule[aT]<dist)
            cout << "range is too far" << endl ;
    }
    attacker.setMoved(true);
    attacker.setAvailable(false);
}

void AttackCommand::debug()const{
    cout << "Attack Command" << endl ;
    cout << "  attacker    x:" << attacker.getX() << "    y:"<< attacker.getY() << endl ;
    cout << "  defender    x:" << defender.getX() << "    y:"<< defender.getY() << endl ;
}

Json::Value AttackCommand::toJson () const{
    Json::Value data ;
    data["CommandTypeId"] = COM_ATTACK;
    data["attId"] = attId ;
    data["defId"] = defId ;
    /*
    data["Attacker"]["x"] = getAttacker().getX();
    data["Attacker"]["y"] = getAttacker().getY();
    data["Defender"]["x"] = getDefender().getX();
    data["Defender"]["y"] = getDefender().getY();
    */
    return data ;
}
