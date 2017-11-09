#include <iostream>

#include "../shared/render/Render.h"

using namespace std ;
using namespace render ;

/*Render::Render(){
    
}*/
    
void Render::draw (sf::RenderWindow& window){
    cellLayer.draw(window);
    buildingLayer.draw(window);
    unitLayer.draw(window);
    statusLayer.draw(window);
}
// Setters and Getters
void Render::setState(const state::State& state){
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