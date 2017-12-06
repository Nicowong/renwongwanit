#include "PathMap.h"

using namespace std;
using namespace ai;
using namespace state;

void PathMap::init(const state::Element& element,const state::ElementTab& others){
    
    int distance=0;
    for(size_t i=0; i<sizeof(others.getElemTab());i++){
        distance=getDistance(Position(element.getX(),element.getY())
                ,Position(others.getElemTab()[i]->getX(),others.getElemTab()[i]->getY()));
        if(distance!=0){
            distancetab.push_back(distance);
            positiontab.push_back(Position(others.getElemTab()[i]->getX()
                                ,others.getElemTab()[i]->getY()));
        }
    }
    setDistancetab(distancetab);
    setPositiontab(positiontab);
}

void PathMap::update(const state::Element& element,const state::ElementTab& others){
    
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

const std::vector<Position>& PathMap::getPositiontab() const{
    return positiontab;
}

void PathMap::setPositiontab(const std::vector<Position>& positiontab){
    this->positiontab=positiontab;
}
