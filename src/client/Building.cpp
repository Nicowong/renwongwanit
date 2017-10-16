/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Building.cpp
 * Author: ren
 * 
 * Created on October 3, 2017, 4:32 PM
 */

#include "../shared/state/Building.h"

using namespace state ;


Building::Building():Building(0,0, BT_CITY, BT_NEUTRAL){}

Building::Building(int x, int y, BuildingType bType, BuildingTeam team):
    x(x), y(y), buildingTeam(team), buildingType(bType), capturePoints(20){}

bool Building::isInCapture()const{
    if (capturePoints < 20)
        return true;
    else
        return false;
}

//Setters and Getters
int Building::getX() const{
    return x ;
}
void Building::setX(int X){
    x = X;
}
int Building::getY() const{
    return y ;
}
void Building::setY(int Y){
    y = Y ;
}
BuildingTeam Building::getBuildingTeam() const{
    return buildingTeam ;
}
void Building::setBuildingTeam(BuildingTeam buildingTeam){
    buildingTeam = buildingTeam ;
}
BuildingType Building::getBuildingType() const{
    return buildingType ;
}
void Building::setBuildingType(BuildingType buildingType){
    buildingType = buildingType ;
}
int Building::getCapturePoints() const{
    return capturePoints ;
}
void Building::setCapturePoints(int CapturePoints){
    capturePoints = CapturePoints ;
}