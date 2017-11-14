#include <iostream>

#include "DestroyCommand.h"

using namespace std ;
using namespace engine ;


DestroyCommand::DestroyCommand (state::Unit& unit): unit(unit){

}
CommandTypeId DestroyCommand::getCommandTypeId() const{
    return COM_DESTROY ;
}
void DestroyCommand::execute (state::State& state){

}
// Setters and Getters
state::Unit& DestroyCommand::getUnit() const{
	return unit ;
}
void DestroyCommand::setUnit(const state::Unit&& unit){

}