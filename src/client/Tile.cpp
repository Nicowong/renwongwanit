/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../shared/render/Tile.h"
using namespace std;
using namespace render;

Tile::getX() const{
    return x;
}

Tile::setX(const int x){
    this->x=x;
}

Tile::getY() const{
    return y;
}

Tile::setY(const int y){
    this->y=y;
}

Tile::getWidth(){
    return width;
}

Tile::setWidth(const int width){
    this->width=width;
}

Tile::getHeight() const{
    return height;
}

Tile::setHeight(const int height){
    this->height=height;
}