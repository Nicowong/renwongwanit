#include <iostream>

#include "Layer.h"

using namespace std ;
using namespace render ;

Layer::Layer(Surface* surface, TileSet* tileset): surface(surface), tileSet(tileset){
	/*if(surface==nullptr){
		surface = new Surface ;
	}*/
	//cout << "Layer::Layer(TileSet* tileset): tileSet(tileset) ; surface="<< surface << endl ;
}

Layer::Layer(): surface(nullptr), tileSet(nullptr){
	surface = new Surface ;
	//cout << "Layer::Layer(): surface(nullptr), tileSet(nullptr) ; surface="<< surface << endl ;
}

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
