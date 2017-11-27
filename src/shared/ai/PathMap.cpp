#include "PathMap.h"

using namespace std;
using namespace ai;
using namespace state;

void PathMap::init(const state::ElementTab& element){
    
}

void PathMap::update(const state::ElementTab& element){
    
   
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

int PathMap::getDistance(const Point& a, const Point& b) const{
    int distance;
    distance= abs(a.getX()-b.getX())+abs(a.getY()-b.getY());
    return distance;
}
