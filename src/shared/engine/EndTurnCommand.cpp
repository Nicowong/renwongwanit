#include <iostream>
#include "EndTurnCommand.h"

using namespace std ;
using namespace state ;
using namespace engine ;

EndTurnCommand::EndTurnCommand(state::State& state): state(state){

}

CommandTypeId EndTurnCommand::getCommandTypeId () const{
	return COM_ENDTURN ;
}
void EndTurnCommand::execute (state::State& state){
    cout << "Command endTurn : " << endl ;
	ElementTab& utab = state.getUnitTab();
	Unit *u = nullptr ;
	for(size_t j=0 ; j<state.getH() ; j++)
		for(size_t i=0 ; i<state.getW() ; i++){
			u = (Unit*)utab.getElem(i,j);
			if(u != nullptr){
				u->setMoved(false);
				u->setAvailable(true);
			}
		}
	state.turnIncr();
}
// Setters and Getters
state::State& EndTurnCommand::getState() const{
	return state;
}
void EndTurnCommand::setState(const state::State&& state){
	this->state = state ;
}