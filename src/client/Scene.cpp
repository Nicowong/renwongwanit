/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../shared/render/Scene.h"
using namespace std;
using namespace render;
using namespace Scene;

Scene::getWidth(){
    return width;
}

Scene::setWidth(size_t width){
    this->width=width;
}

Scene::getHeight(){
    return height;
}


Scene::setHeight(size_t height){
    this->height=height;
}


