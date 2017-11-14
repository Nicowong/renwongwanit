#include <iostream>

#include "MoveCommand.h"

using namespace std ;
using namespace engine ;

MoveCommand::MoveCommand (state::Unit& unit, size_t x, size_t y): unit(unit), x(x), y(y){

}
CommandTypeId MoveCommand::getCommandTypeId() const{
    return COM_MOVE ;
}
void MoveCommand::execute (state::State& state){

}
// Setters and Getters
state::Unit& MoveCommand::getUnit() const{
	return unit ;
}
void MoveCommand::setUnit(const state::Unit&& unit){

}
const size_t& MoveCommand::getX() const{
	return x ;
}
void MoveCommand::setX(const size_t& x){

}
const size_t& MoveCommand::getY() const{
	return y ;
}
void MoveCommand::setY(const size_t& y){

}