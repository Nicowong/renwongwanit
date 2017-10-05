/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Unit.cpp
 * Author: ren
 * 
 * Created on October 3, 2017, 5:13 PM
 */

#include <iostream>

#include "../shared/state/Unit.h"
using namespace state ;

Unit::Unit():
    Unit(0,0,UT_INFANTRY, UT_PLAYER1){
    
    std::cout<< "Unit::Unit()" << std::endl ;
}

Unit::Unit (int x, int y, UnitType uType, UnitTeam team):
    x(x), y(y), health(100), ammo(0), fuel(1), vision(1), unitTeam(team), unitType(uType){
    
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
        default:
            std::cout << "In Unit::Unit(int,int,UnitType,UnitTeam), error : unitType not found." << std::endl;
            break;
    }
}

UnitType Unit::getUnitType(){
    return unitType ;
}
UnitTeam Unit::getTeam(){
    return unitTeam ;
}
int Unit::getX() const{
    return x ;
}
void Unit::setX(int X){
    x = X ;
}
int Unit::getY() const{
    return y ;
}
void Unit::setY(int Y){
    y = Y ;
}
int Unit::getHealth() const{
    return health ;
}
void Unit::setHealth(int Health){
    health = Health ;
}
int Unit::getAmmo() const{
    return ammo ;
}
void Unit::setAmmo(int Ammo){
    ammo = Ammo ;
}
int Unit::getFuel() const{
    return fuel ;
}
void Unit::setFuel(int Fuel){
    fuel = Fuel ;
}
int Unit::getVision() const{
    return vision ;
}
void Unit::setVision(int Vision){
    vision = Vision ;
}
bool Unit::isInfantry(){
    if(unitType==0 || unitType==1)
        return true;
    else
        return false;
}
/*
bool Unit::isCapturing(){
    
}*/
bool Unit::isRanged(){
    if(unitType==7 || unitType==8 || unitType==9 || unitType==14)
        return true;
    else
        return false;
}
bool Unit::isTransporter(){
    if(unitType==5 || unitType==13 || unitType==16)
        return true;
    else
        return false;
}