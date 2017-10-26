/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../shared/render/CellTileSet.h"
using namespace std;
using namespace state;
using namespace render;

CellTileSet::CellTileSet(){}

CellTileSet::getCellHeight(){
    return cellHeight;
}

CellTileSet::setCellHeight(int cellHeight){
    this->cellHeight=cellHeight;
}

CellTileSet::getCellWidth(){
    return cellWidth;
}

CellTileSet::setCellWidth(int cellWidth){
    this->cellWidth=cellWidth;
}

CellTileSet::getImageFile(){
    return imageFile;
}

CellTileSet::setImageFIle(std::string imageFile){
    this->imageFile=imageFile;
}

