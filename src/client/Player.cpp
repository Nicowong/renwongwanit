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

#include "../shared/state/Player.h"
using namespace state;
Building* Player::getBuilding(int i){
    return BuildingList[i];
}
Unit* Player::getUnit(int i){
    return UnitList[i];
}
int Player::getPlayerID() const{
    return PlayerID;
}
void Player::setPlayerID(int playerID){
    PlayerID = playerID;
}
void Player::setUnitList(const std::vector<Unit*>& unitList){
    unitList=UnitList;
}
void Player::setBuildingList(const std::vector<Building*>& buildingList){
    buildingList=BuildingList;
}