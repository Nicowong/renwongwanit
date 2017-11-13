#include <iostream>

#include "../shared/state/Element.h"

using namespace std ;
using namespace state;

Element::Element (TypeId type, Team team, size_t x, size_t y):
    type(type), team(team), x(x), y(y){
    
}
bool Element::isUnit ()const{
    return type==T_UNIT ;
}
// Setters and Getters
TypeId Element::getType() const{
    return type ;
}
void Element::setType(TypeId Type){
    this->type = type ;
}
Team Element::getTeam() const{
    return team ;
}
void Element::setTeam(Team team){
    this->team = team ;
}
const size_t& Element::getX() const{
    return x ;
}
void Element::setX(const size_t& x){
    this->x = x ;
}
const size_t& Element::getY() const{
    return y ;
}
void Element::setY(const size_t& y){
    this->y = y ;
}

void Element::debug()const{
    std::cout << "Element::void debug()const" <<std::endl;
    std::cout << "typeId : "<<type <<std::endl;
    std::cout << "team : "<<team <<std::endl;
    std::cout << "pos(x,y) : "<<x<<","<<y <<std::endl;
}
