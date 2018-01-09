#include <iostream>

#include "Render.h"

using namespace std ;
using namespace render ;

Render::Render (state::State& state):
state(state), statusLayer(nullptr,nullptr), cellLayer(nullptr,nullptr), buildingLayer(nullptr,nullptr), unitLayer(nullptr,nullptr){
    Surface* statusSurface = new Surface();
    Surface* cellSurface = new Surface();
    Surface* buildingSurface = new Surface();
    Surface* unitSurface = new Surface();

    statusSurface->loadTexture("res/status.png");
    cellSurface->loadTexture("res/cells.png");
    buildingSurface->loadTexture("res/buildings.png");
    unitSurface->loadTexture("res/units.png");

    statusLayer.setSurface(statusSurface);
    cellLayer.setSurface(cellSurface);
    buildingLayer.setSurface(buildingSurface);
    unitLayer.setSurface(unitSurface);

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
    //cout << "-renderUpd-" ;
    cellLayer.update(state.getCellTab());
    buildingLayer.update(state.getCellTab());
    unitLayer.update(state.getUnitTab());
    statusLayer.update(state);
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