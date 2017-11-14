#include <iostream>

#include "SupplyCommand.h"

using namespace std ;
using namespace engine ;

SupplyCommand::SupplyCommand (state::Unit& unit): unit(unit){

}
CommandTypeId SupplyCommand::getCommandTypeId() const{
    return COM_SUPPLY;
}
void SupplyCommand::execute (state::State& state){

}
// Setters and Getters
state::Unit& SupplyCommand::getUnit() const{
	return unit ;
}
void SupplyCommand::setUnit(const state::Unit&& unit){

}