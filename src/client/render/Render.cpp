#include <iostream>

#include "Render.h"

using namespace std ;
using namespace render ;

Render::Render (state::State& state):
state(state), statusLayer(nullptr,nullptr), cellLayer(nullptr,nullptr), buildingLayer(nullptr,nullptr), unitLayer(nullptr,nullptr){
    statusLayer.setSurface(new Surface());
    cellLayer.setSurface(new Surface());
    buildingLayer.setSurface(new Surface());
    unitLayer.setSurface(new Surface());

    //StateTileSet* sts = new StateTileSet ;
    statusLayer.setTileSet(new StateTileSet());
    cellLayer.setTileSet(new CellTileSet());
    buildingLayer.setTileSet(new BuildingTileSet());
    unitLayer.setTileSet(new UnitTileSet());
}
    
void Render::draw (sf::RenderWindow& window){
    cellLayer.draw(window);
    buildingLayer.draw(window);
    unitLayer.draw(window);
    statusLayer.draw(window);
}
void Render::update(){
    cout << "Render::update()::cellLayer.update(state.getCellTab());" << endl ;
    cellLayer.update(state.getCellTab());
    //buildingLayer.update(state.getCellTab());
    cout << "Render::update()::unitLayer.update(state.getUnitTab());" << endl ;
    unitLayer.update(state.getUnitTab());
}

// Setters and Getters
void Render::setState(const state::State&& state){
    state.~State();
    this->state = state ;
}
const StatusLayer& Render::getStatusLayer() const{
    return statusLayer ;
}
void Render::setStatusLayer(const StatusLayer& statusLayer){
    this->statusLayer = statusLayer ;
}
const BoardLayer& Render::getCellLayer() const{
    return cellLayer ;
}
void Render::setCellLayer(const BoardLayer& cellLayer){
    this->cellLayer = cellLayer ;
}
const BoardLayer& Render::getBuildingLayer() const{
    return buildingLayer ;
}
void Render::setBuildingLayer(const BoardLayer& buildingLayer){
    this->buildingLayer = buildingLayer ;
}
const BoardLayer& Render::getUnitLayer() const{
    return unitLayer ;
}
void Render::setUnitLayer(const BoardLayer& unitLayer){
    this->unitLayer = unitLayer ;
}