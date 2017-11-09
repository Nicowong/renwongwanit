#include <iostream>

#include "../shared/render/Layer.h"

using namespace std ;
using namespace render ;

void Layer::print (int x, int y, std::string text){
    
}
void Layer::draw (sf::RenderWindow& window){
    window.draw(*surface);
}
// Setters and Getters
Surface* Layer::getSurface () const{
    return surface ;
}
void Layer::setSurface(Surface* surface){
    this->surface = surface ;
}
TileSet* Layer::getTileSet() const{
    return tileSet ;
}
void Layer::setTileSet(TileSet* tileSet){
    this->tileSet = tileSet ;
}
