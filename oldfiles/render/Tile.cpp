/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../shared/render/Tile.h"
using namespace std;
using namespace render;

int Tile::getX() const{
    return x;
}

void Tile::setX(const int x){
    this->x=x;
}

int Tile::getY() const{
    return y;
}

void Tile::setY(const int y){
    this->y=y;
}

int Tile::getW()const{
    return w;
}

void Tile::setW(const int width){
    this->w=width;
}

int Tile::getH() const{
    return h;
}

void Tile::setH(const int height){
    this->h=height;
}