/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cell.cpp
 * Author: ren
 * 
 * Created on October 4, 2017, 11:23 AM
 */

#include "../shared/state/Cell.h"
using namespace state;

Building* Cell::getBuilding(){
    return nullptr ;//building;
}
Unit* Cell::getUnit(){
    return nullptr ;//unit;
}
CellType Cell::getCellType(){
    return cellType;
}
int Cell::getX() const{
    return x;
}
void Cell::setX(int X){
    x=X;
}
int Cell::getY() const{
    return y;
}
void Cell::setY(int Y){
    y=Y;
}
