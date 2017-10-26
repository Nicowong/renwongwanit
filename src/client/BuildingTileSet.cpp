/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../shared/render/BuildingTileSet.h"
using namespace std;
using namespace state;
using namespace render;

BuildingTileSet::BuildingTIleSet(){}
int const BuildingTileSet::getBuildingWidth(){
    return buildingWidth;
}

BuildingTileSet::setBuildingWidth(const int buildingWidth){
    this->buildingWidth=buildingWidth;
}

BuildingTileSet::getBuildingHeight(){
    return buildingHeight;
}

BuildingTileSet::setBuildingHeight(const int buildingHeight){
    this->buildingHeight=buildingHeight;
}

BuildingTileSet::getImageFile() const{
    return imageFile;
}

BuildingTileSet::setImageFile(std::string imageFile) const{
    this->imageFile = imageFile;
}