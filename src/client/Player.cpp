/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: ren
 * 
 * Created on October 4, 2017, 11:45 AM
 */

#include "Player.h"
using namespace state;
Building* Player::getBuilding(int i){
    return buildingList[i];
}
Unit* Player::getUnit(int i){
    return unitList[i];
}
int Player::getPlayerID() const{
    return PlayerID;
}

