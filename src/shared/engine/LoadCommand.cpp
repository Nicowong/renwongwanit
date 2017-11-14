#include <iostream>

#include "LoadCommand.h"

using namespace std ;
using namespace engine ;


LoadCommand::LoadCommand (state::Unit& carrier, state::Unit& unit): carrier(carrier), unit(unit){

}
CommandTypeId LoadCommand::getCommandTypeId() const{
    return COM_LOAD ;
}
void LoadCommand::execute (state::State& state){

}
// Setters and Getters
state::Unit& LoadCommand::getCarrier() const{
	return carrier ;
}
void LoadCommand::setCarrier(const state::Unit&& carrier){

}
state::Unit& LoadCommand::getUnit() const{
	return unit ;
}
void LoadCommand::setUnit(const state::Unit&& unit){

}