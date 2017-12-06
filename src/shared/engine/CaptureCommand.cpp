#include <iostream>

#include "CaptureCommand.h"

using namespace std ;
using namespace state ;
using namespace engine ;

CaptureCommand::CaptureCommand(state::Building& building, state::Unit& unit):
building(building), unit(unit){

}

CommandTypeId CaptureCommand::getCommandTypeId() const{
    return COM_CAPTURE;
}

// EXECUTE COMMAND
void CaptureCommand::execute (state::State& state){
	cout << "Command capture : "<<endl ;
	// seulement si l'unite est une INFANTRY, que les positions sont correctes 
	//et que le building appartient a l'autre joueur
	if(unit.getX()==building.getX() && unit.getY()==building.getY() &&
	   unit.isInfantry() && unit.getTeam()!=building.getTeam()){

	   	//calcul de la valeur de capture
		int cp = unit.getHealth()/10 +1 ;
		if(cp > 10)
			cp = 10 ;
		if(cp < 0){
			cp = 0 ;
			cout << "error in CaptureCommand::execute : cp<0" << endl ;
		}

		// capture complete du building
		if(cp >= building.getCapturePoints()){
			building.setCapturePoints(20);
			building.setTeam(unit.getTeam());
			if(building.getCellType()== state::CT_BASE)
				state.setVictory(unit.getTeam());
		// capture partielle
		}else{
			int bcp = building.getCapturePoints() - cp ;
			building.setCapturePoints(bcp);
		}
	}
	else
		cout << "In engine::CaptureCommand::execute() : error"<<endl ;
}

//GETTER SETTER
state::Building& CaptureCommand::getBuilding() const{
	return building ;
}
void CaptureCommand::setBuilding(const state::Building&& building){
	this->building = building ;
}

state::Unit& CaptureCommand::getUnit() const{
	return unit ;
}
void CaptureCommand::setUnit(const state::Unit&& unit){
	this->unit = unit ;
}