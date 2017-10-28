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
    Unit(0,0,UT_INFANTRY, UT_PLAYER1)
{
    std::cout<< "Unit::Unit()" << std::endl ;
}

Unit::Unit (int x, int y, UnitType uType, UnitTeam team):
    x(x), y(y), unitTeam(team), unitType(uType), health(100), ammo(0), fuel(1), vision(1)
{
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

bool Unit::isInfantry()const{
    if(unitType==UT_INFANTRY || unitType==UT_MECH)
        return true;
    else
        return false;
}
bool Unit::isRanged()const{
    if(unitType==UT_AAMISSILELAUNCHER || unitType==UT_ARTILLERY || unitType==UT_MISSILELAUNCHER || unitType==UT_BATTLESHIP)
        return true;
    else
        return false;
}
bool Unit::isTransporter()const{
    if(unitType==UT_APC || unitType==UT_TRANSPORTHELI || unitType==UT_LANDER)
        return true;
    else
        return false;
}

//Setters and Getters
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
void Unit::setUnitTeam(UnitTeam unitTeam){
    this->unitTeam = unitTeam ;
}
UnitTeam Unit::getUnitTeam()const{
    return unitTeam ;
}
void Unit::setUnitType(UnitType unitType){
    this->unitType = unitType ;
}
UnitType Unit::getUnitType()const{
    return unitType ;
}
int Unit::getHealth() const{
    return health ;
}
void Unit::setHealth(int Health){
    this->health = Health ;
}
int Unit::getAmmo() const{
    return ammo ;
}
void Unit::setAmmo(int Ammo){
    this->ammo = Ammo ;
}
int Unit::getFuel() const{
    return fuel ;
}
void Unit::setFuel(int Fuel){
    this->fuel = Fuel ;
}
int Unit::getVision() const{
    return vision ;
}
void Unit::setVision(int Vision){
    this->vision = Vision ;
}
/*
bool Unit::isCapturing(){
    
}*/