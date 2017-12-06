#include <iostream>

#include "../shared/state/Unit.h"

using namespace std ;
using namespace state ;

Unit::Unit(Team team, UnitType utype, size_t x, size_t y):
    Element(T_UNIT, team, x,y), unitType(utype), health(100), ammo(0), fuel(1), vision(1){
    switch(unitType){
        case UT_INFANTRY          : ammo = 99 ; fuel = 99 ; vision = 2 ; break ;
        case UT_MECH              : ammo = 6  ; fuel = 70 ; vision = 2 ; break ;
        case UT_RECON             : ammo = 99 ; fuel = 99 ; vision = 5 ; break ;
        case UT_TANK              : ammo = 12 ; fuel = 99 ; vision = 2 ; break ;
        case UT_TANKM             : ammo = 9  ; fuel = 99 ; vision = 2 ; break ;
        case UT_NEOTANK           : ammo = 6  ; fuel = 99 ; vision = 2 ; break ;
        case UT_MEGATANK          : ammo = 6  ; fuel = 99 ; vision = 2 ; break ;
        case UT_APC               : ammo = 0  ; fuel = 99 ; vision = 1 ; break ;
        case UT_ARTILLERY         : ammo = 9  ; fuel = 99 ; vision = 3 ; break ;
        case UT_MISSILELAUNCHER   : ammo = 6  ; fuel = 99 ; vision = 3 ; break ;
        case UT_AAMISSILELAUNCHER : ammo = 6  ; fuel = 99 ; vision = 4 ; break ;
        case UT_AATANK            : ammo = 12 ; fuel = 99 ; vision = 3 ; break ;
        case UT_TRANSPORTHELI     : ammo = 0  ; fuel = 99 ; vision = 1 ; break ;
        case UT_BATTLEHELI        : ammo = 6  ; fuel = 99 ; vision = 3 ; break ;
        case UT_FIGHTER           : ammo = 6  ; fuel = 99 ; vision = 3 ; break ;
        case UT_BOMBER            : ammo = 6  ; fuel = 70 ; vision = 2 ; break ;
        case UT_ASA               : ammo = 6  ; fuel = 99 ; vision = 5 ; break ;
        case UT_LANDER            : ammo = 0  ; fuel = 99 ; vision = 1 ; break ;
        case UT_CRUISER           : ammo = 9  ; fuel = 99 ; vision = 4 ; break ;
        case UT_SUBMARINE         : ammo = 6  ; fuel = 50 ; vision = 5 ; break ;
        case UT_BATTLESHIP        : ammo = 6  ; fuel = 99 ; vision = 3 ; break ;
        case UT_CARRIER           : ammo = 99 ; fuel = 99 ; vision = 2 ; break ;

        default:
            std::cout << "In Unit::Unit(Team,UnitType,size_t,size_t), error : unitType not found." << std::endl;
            break;
    }
    available = true ;
    moved = false ;
}
Unit::Unit(int team, int utype, size_t x, size_t y):
    Element(T_UNIT, NONE, x,y), unitType(UT_NONE), health(100), ammo(0), fuel(1), vision(1){
    switch(team){
        case 1 :    this->team = PLAYER1 ;  break ;
        case 2 :    this->team = PLAYER2 ;  break ;
        default :   this->team = NONE    ;  break ;
    }
    switch(utype){
        case 0  : unitType = UT_INFANTRY          ; ammo = 99 ; fuel = 99 ; vision = 2 ; break ;
        case 1  : unitType = UT_MECH              ; ammo = 6  ; fuel = 70 ; vision = 2 ; break ;
        case 2  : unitType = UT_RECON             ; ammo = 99 ; fuel = 99 ; vision = 5 ; break ;
        case 3  : unitType = UT_TANK              ; ammo = 12 ; fuel = 99 ; vision = 2 ; break ;
        case 4  : unitType = UT_TANKM             ; ammo = 9  ; fuel = 99 ; vision = 2 ; break ;
        case 5  : unitType = UT_NEOTANK           ; ammo = 6  ; fuel = 99 ; vision = 2 ; break ;
        case 6  : unitType = UT_MEGATANK          ; ammo = 6  ; fuel = 99 ; vision = 2 ; break ;
        case 7  : unitType = UT_APC               ; ammo = 0  ; fuel = 99 ; vision = 1 ; break ;
        case 8  : unitType = UT_ARTILLERY         ; ammo = 9  ; fuel = 99 ; vision = 3 ; break ;
        case 9  : unitType = UT_MISSILELAUNCHER   ; ammo = 6  ; fuel = 99 ; vision = 3 ; break ;
        case 10 : unitType = UT_AAMISSILELAUNCHER ; ammo = 6  ; fuel = 99 ; vision = 4 ; break ;
        case 11 : unitType = UT_AATANK            ; ammo = 12 ; fuel = 99 ; vision = 3 ; break ;
        case 12 : unitType = UT_TRANSPORTHELI     ; ammo = 0  ; fuel = 99 ; vision = 1 ; break ;
        case 13 : unitType = UT_BATTLEHELI        ; ammo = 6  ; fuel = 99 ; vision = 3 ; break ;
        case 14 : unitType = UT_FIGHTER           ; ammo = 6  ; fuel = 99 ; vision = 3 ; break ;
        case 15 : unitType = UT_BOMBER            ; ammo = 6  ; fuel = 70 ; vision = 2 ; break ;
        case 16 : unitType = UT_ASA               ; ammo = 6  ; fuel = 99 ; vision = 5 ; break ;
        case 17 : unitType = UT_LANDER            ; ammo = 0  ; fuel = 99 ; vision = 1 ; break ;
        case 18 : unitType = UT_CRUISER           ; ammo = 9  ; fuel = 99 ; vision = 4 ; break ;
        case 19 : unitType = UT_SUBMARINE         ; ammo = 6  ; fuel = 50 ; vision = 5 ; break ;
        case 20 : unitType = UT_BATTLESHIP        ; ammo = 6  ; fuel = 99 ; vision = 3 ; break ;
        case 21 : unitType = UT_CARRIER           ; ammo = 99 ; fuel = 99 ; vision = 2 ; break ;

        default:
            std::cout << "In Unit::Unit(int,int,size_t,size_t), error : unitType "<< utype<<" not found." << std::endl;
            break;
    }
    available = false ;
    moved = true ;
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
    if(unitType==UT_APC || unitType==UT_TRANSPORTHELI || unitType==UT_LANDER || unitType==UT_CARRIER || unitType==UT_CRUISER)
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

bool Unit::getAvailable()const{
    return available ;
}
void Unit::setAvailable(bool av){
    available=av ;
}
bool Unit::getMoved()const{
    return moved ;
}
void Unit::setMoved(bool moved){
    this->moved = moved ;
}


void Unit::debug(int mode)const{
    if(mode == 0 ){
        std::cout<< "Unit::";
        Element::debug();
        std::cout<< "unitType : "<<unitType <<std::endl ;
        std::cout<< "health : "<<health <<std::endl ;
        std::cout<< "ammo : "<<ammo <<std::endl ;
        std::cout<< "fuel : "<<fuel <<std::endl ;
        std::cout<< "vision : "<<vision <<std::endl ;
    }else{
        switch(unitType){
            case UT_INFANTRY          : cout<<"Infantry"    ; break ;
            case UT_MECH              : cout<<"Mech"        ; break ;
            case UT_RECON             : cout<<"Recon"       ; break ;
            case UT_TANK              : cout<<"Tank"        ; break ;
            case UT_TANKM             : cout<<"TankM"       ; break ;
            case UT_NEOTANK           : cout<<"NeoTank"     ; break ;
            case UT_MEGATANK          : cout<<"MegaTank"    ; break ;
            case UT_APC               : cout<<"APC"         ; break ;
            case UT_ARTILLERY         : cout<<"Artillery"   ; break ;
            case UT_MISSILELAUNCHER   : cout<<"MissileL"    ; break ;
            case UT_AAMISSILELAUNCHER : cout<<"AAMissileL"  ; break ;
            case UT_AATANK            : cout<<"AATank"      ; break ;
            case UT_TRANSPORTHELI     : cout<<"TranspHeli"  ; break ;
            case UT_BATTLEHELI        : cout<<"BattleHeli"  ; break ;
            case UT_FIGHTER           : cout<<"Fighter"     ; break ;
            case UT_BOMBER            : cout<<"Bomber"      ; break ;
            case UT_ASA               : cout<<"ASA"         ; break ;
            case UT_LANDER            : cout<<"Lander"      ; break ;
            case UT_CRUISER           : cout<<"Cruiser"     ; break ;
            case UT_SUBMARINE         : cout<<"Submarine"   ; break ;
            case UT_BATTLESHIP        : cout<<"Battleship"  ; break ;
            case UT_CARRIER           : cout<<"Carrier"     ; break ;
            default                   : cout<<"default"     ; break ;
        }
        switch(team){
            case PLAYER1 : cout << "(P1)" ; break ;
            case PLAYER2 : cout << "(P2)" ; break ;
            default : break ;
        }
        cout << "x:"<<x <<" y:"<<y << " hp:"<<health <<endl ;
    }
}
