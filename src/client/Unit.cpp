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

#include "Unit.h"
using namespace state ;

UnitType Unit::getUnitType(){
    return unittype;
}
UnitTeam Unit::getTeam(){
    return unitteam;
}
int Unit::getX() const{
    return x;
}
void Unit::setX(int X){
    x=X;
}
int Unit::getY() const{
    return y;
}
void Unit::setY(int Y){
    y=Y;
}
int Unit::getHealth() const{
    return health;
}
void Unit::setHealth(int Health){
    health=Health;
}
int Unit::getAmmo() const{
    return ammo;
}
void Unit::setAmmo(int Ammo){
    ammo=Ammo;
}
int Unit::getFuel() const{
    return fuel;
}
void Unit::setFuel(int Fuel){
    fuel=Fuel;
}
int Unit::getVision() const{
    return vision;
}
void Unit::setVision(int Vision){
    vision=Vision;
}
bool Unit::isInfantry(){
    if(unittype=0 ||unittype =1 ) return true;
    else return false;
}
/*
bool Unit::isCapturing(){
    
}*/
bool Unit::isRanged(){
    if(unittype=7||unittype=8||unittype=9||unittype=14) return true;
    else return false;
}
bool Unit::isTransporter(){
    if(unittype=5||unittype=13||unittype=16) return true;
    else return false;
}