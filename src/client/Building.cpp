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


BuildingType Building::getBuildingType(){
    return buildingType ;
}
BuildingTeam Building::getTeam(){
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
bool Building::isInCapture(){
    if (capturePoints < 20)
        return true;
    else
        return false;
}