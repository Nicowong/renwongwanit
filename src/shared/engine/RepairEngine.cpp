#include <iostream>

#include "RepairCommand.h"

using namespace std ;
using namespace engine ;

RepairCommand::RepairCommand (state::Unit& unit): unit(unit){

}
CommandTypeId RepairCommand::getCommandTypeId() const{
    return COM_REPAIR ;
}
void RepairCommand::execute (state::State& state){
	if(unit.getHealth() != 100 ){
        this->unit.setHealth(unit.getHealth()+2);
    }else{
        std::cout<<"In engine::MoveCommand::execute() : error"<<std::endl;

        }

    
}
// Setters and Getters
state::Unit& RepairCommand::getUnit() const{
    return unit ;
}
void RepairCommand::setUnit(const state::Unit&& unit){
	this->unit = unit ;
}