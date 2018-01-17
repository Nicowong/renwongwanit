#include <iostream>

#include "json/json.h"
#include "json/json-forwards.h"

#include "DestroyCommand.h"

using namespace std ;
using namespace engine ;


DestroyCommand::DestroyCommand (state::Unit& unit): unitId(unit.getId()), unit(unit){
}

DestroyCommand::DestroyCommand(state::State& state, int unitId): unitId(unitId), unit(*(state.getUnitId(unitId))){
}

CommandTypeId DestroyCommand::getCommandTypeId() const{
    return COM_DESTROY ;
}
void DestroyCommand::execute (state::State& state){
    cout << "Command destroy : " << endl ;
    cout << "unit : " ;
    unit.debug(1);
    if(unit.getHealth()<=0){
        state.getUnitTab().eraseElem(unit.getX(), unit.getY()) ;
    }else{
        std::cout<<"In engine::DestroyCommand::execute() : error"<<std::endl;
    }
    
}
// Setters and Getters
state::Unit& DestroyCommand::getUnit() const{
    return unit ;
}
void DestroyCommand::setUnit(const state::Unit&& unit){
    this->unit = unit;
}

void DestroyCommand::debug()const{
    cout<< "Destroy Command" << endl ;
}

Json::Value DestroyCommand::toJson () const{
    Json::Value data ;
    data["CommandTypeId"] = COM_DESTROY ;
    return data ;
}
