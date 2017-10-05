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

Building* Player::getBuilding (int i){
    return buildingList[i];
}

Unit* Player::getUnit (int i){
    return unitList[i];
}
    // Setters and Getters
int Player::getPlayerID() const{
    return playerID ;
}

void Player::setPlayerID(int PlayerID){
    this->playerID = playerID ;
}

const std::vector<Unit*>& Player::getUnitList()const{
    return unitList ;
}
void Player::setUnitList(const std::vector<Unit*>& unitList){
    this->unitList = unitList ;
}
const std::vector<Building*>& Player::getBuildingList()const{
    return buildingList ;
}
void Player::setBuildingList(const std::vector<Building*>& buildingList){
    this->buildingList = buildingList ;
}