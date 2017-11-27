#include "PathMap.h"

using namespace std;
using namespace ai;
using namespace state;

void PathMap::init(const state::Element& element){
    state::ElementTab elementtab;
    int distance=0;
    for(int x=0; x < 480;x+=16){
        for(int y=0; y < 240; y+=8){
            if(elementtab.getElem(x,y)!=NULL){
                distance=getDistance(Position(element.getX()
                        ,element.getY()),Position(x,y));
                distancetab.push_back(distance);
            }
        }
    }
}

void PathMap::update(const state::Element& element){
    
}

int PathMap::getX() const{
    return x;
}

int PathMap::getY() const{
    return y;
}

void PathMap::setX(int x){
    this->x = x;
}

void PathMap::setY(int y){
    this->y = y;
}

int PathMap::getDistance(const Position& a, const Position& b) const{
    int distance;
    distance= abs(a.getX()-b.getX())+abs(a.getY()-b.getY());
    return distance;
}

const std::vector<int>& PathMap::getDistancetab() const{
    return distancetab;
}

void PathMap::setDistancetab(const std::vector<int>& distancetab){
    this->distancetab=distancetab;
}
