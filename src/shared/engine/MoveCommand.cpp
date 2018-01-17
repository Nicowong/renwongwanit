#include <iostream>

#include "json/json.h"
#include "json/json-forwards.h"

#include "MoveCommand.h"

#include "rules.h"

using namespace std ;
using namespace state ;
using namespace engine ;

MoveCommand::MoveCommand (state::Unit& unit, size_t x, size_t y): unitId(unit.getId()), unit(unit), x(x), y(y){

}

MoveCommand::MoveCommand (state::State& state, int unitId, size_t x, size_t y): 
    unitId(unitId), unit(*(state.getUnitId(unitId))),
     x(x), y(y){

}

CommandTypeId MoveCommand::getCommandTypeId() const{
    return COM_MOVE ;
}
void MoveCommand::execute (state::State& state){
    cout << "Command move : " << endl ;
    int ux = unit.getX();
    int uy = unit.getY();
    cout << "unit : ";
    unit.debug(1);
    cout << "to x:"<<x << " y:"<<y <<endl ;
    int dist = abs(ux-(int)x)+abs(uy-(int)y);

    if( dist<=moveRangeRule[unit.getUnitType()] && (unit.getX() != x || unit.getY() != y) ){
        state.getUnitTab().moveElem(unit.getX(), unit.getY(), x, y);
        unit.setX(x);
        unit.setY(y);
        unit.setFuel(unit.getFuel()-dist);
        unit.setMoved(true);
    }else{
        std::cout<<"In engine::MoveCommand::execute() : error"<<std::endl;
    }
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
    this->x=x;
}
const size_t& MoveCommand::getY() const{
    return y;
}
void MoveCommand::setY(const size_t& y){
    this->y=y;
}

void MoveCommand::debug()const{
    cout << "Move Command" << endl ;
    cout << "  unit    x:" << unit.getX() << "    y:"<< unit.getY() << endl ;
    cout << "  to        " << x << "      "<< y << endl ;
}

Json::Value MoveCommand::toJson () const{
    cout << "MoveCom::toJson "<< endl ;
    Json::Value data ;
    data["CommandTypeId"] = COM_MOVE ;
    //data["Unit"]["x"] = getUnit().getX();
    //data["Unit"]["y"] = getUnit().getY();
    data["unitId"] = unitId ;
    data["x"] = getX();
    data["y"] = getY();
    return data ;
}
