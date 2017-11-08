#include <iostream>

#include "../shared/state/Unit.h"

using namespace std ;
using namespace state ;

Unit::Unit(Team team, UnitType utype, size_t x, size_t y):
    Element(T_UNIT, team, x,y), unitType(utype), health(100), ammo(0), fuel(1), vision(1){
    switch(unitType){
        case UT_INFANTRY :
            ammo = 99 ;
            fuel = 99 ;
            vision = 2 ;
            break;
        case UT_MECH :
            ammo = 6 ;
            fuel = 70 ;
            vision = 2 ;
            break;
        case UT_RECON :
            ammo = 12 ;
            fuel = 99 ;
            vision = 5 ;
            break;
        case UT_TANK :
            break;
        default:
            std::cout << "In Unit::Unit(int,int,UnitType,UnitTeam), error : unitType not found." << std::endl;
            break;
    }
}
bool Unit::isInfantry () const{
    if(unitType==UT_INFANTRY || unitType==UT_MECH)
        return true;
    else
        return false;
}
bool Unit::isRanged () const{
    if(unitType==UT_AAMISSILELAUNCHER || unitType==UT_ARTILLERY || unitType==UT_MISSILELAUNCHER || unitType==UT_BATTLESHIP)
        return true;
    else
        return false;
}
bool Unit::isTransporter () const{
    if(unitType==UT_APC || unitType==UT_TRANSPORTHELI || unitType==UT_LANDER)
        return true ;
    else
        return false ;
}
/*
bool isCapturing () const{
    
}
*/
// Setters and Getters
UnitType Unit::getUnitType() const{
    return unitType;
}
void Unit::setUnitType(UnitType unitType){
    this->unitType = unitType ;
}
int Unit::getHealth() const{
    return health ;
}
void Unit::setHealth(int health){
    this->health = health ;
}
int Unit::getAmmo() const{
    return ammo ;
}
void Unit::setAmmo(int ammo){
    this->ammo = ammo ;
}
int Unit::getFuel() const{
    return fuel ;
}
void Unit::setFuel(int fuel){
    this->fuel = fuel ;
}
int Unit::getVision() const{
    return vision ;
}
void Unit::setVision(int vision){
    this->vision = vision ;
}

void Unit::debug()const{
    std::cout<< "Unit::";
    Element::debug();
    std::cout<< "unitType : "<<unitType <<std::endl ;
    std::cout<< "health : "<<health <<std::endl ;
    std::cout<< "ammo : "<<ammo <<std::endl ;
    std::cout<< "fuel : "<<fuel <<std::endl ;
    std::cout<< "vision : "<<vision <<std::endl ;
}
