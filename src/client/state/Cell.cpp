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

Cell::Cell():
    Cell(CT_GROUND, 0, 0)
{
    
}
Cell::Cell (CellType cType, int x, int y ): 
    x(x), y(y), building(nullptr), unit(nullptr), cellType(cType)
{
    
}

//Getters and Setters
int Cell::getX() const{
    return x ;
}
void Cell::setX(int X){
    x = X;
}
int Cell::getY() const{
    return y ;
}
void Cell::setY(int Y){
    y = Y ;
}

Building* Cell::getBuilding () const{
    return building ;
}
void Cell::setBuilding (Building* building){
    this->building = building ;
}
Unit* Cell::getUnit () const{
    return unit ;
}
void Cell::setUnit (Unit* unit){
    this->unit = unit ;
}
    
CellType Cell::getCellType() const{
    return cellType ;
}
void Cell::setCellType(CellType cellType){
    this->cellType = cellType ;
}