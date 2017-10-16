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


Building::Building(int x, int y, BuildingType bType, BuildingTeam team):
    x(x), y(y), capturePoints(20), buildingTeam(team), buildingType(bType){}

Building::Building():Building(0,0, BT_CITY, BT_NEUTRAL){}

BuildingType Building::getBuildingType() const{
    return buildingType ;
}
BuildingTeam Building::getBuildingTeam() const{
    return buildingTeam ;
}
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
int Building::getCapturePoints() const{
    return capturePoints ;
}
void Building::setCapturePoints(int CapturePoints){
    capturePoints = CapturePoints ;
}
bool Building::isInCapture()const{
    if (capturePoints < 20)
        return true;
    else
        return false;
}