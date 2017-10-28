/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../shared/render/Layer.h"
using namespace std;
using namespace render;

Layer::getSurface() const{
    return surface;
}

Layer::setSurface(Surface* surface){
    this->surface=surface;
}

Layer::initSurface(){
    surface = 0;
}

Layer::printText(int x, int y, const std::string& msg){
    std::cout<<"position : "<<x<<","<<y<<"message :"<<msg<<std::endl;
}

Layer::getTileset() const{
    
}