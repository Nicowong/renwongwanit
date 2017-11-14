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

}
// Setters and Getters
state::Unit& RepairCommand::getUnit() const{
	return unit ;
}
void RepairCommand::setUnit(const state::Unit&& unit){

}