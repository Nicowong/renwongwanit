#include "../shared/state/Element.h"

using namespace std ;
using namespace state;

Element::Element (TypeId type, Team team, int x, int y):
    type(type), team(team), x(x), y(y){
    
}
bool const Element::isUnit (){
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
int Element::getX() const{
    return x ;
}
void Element::setX(int x){
    this->x = x ;
}
int Element::getY() const{
    return y ;
}
void Element::setY(int y){
    this->y = y ;
}
