#include "CalculDistance.h"
#include <iostream>
#include <stdlib.h>

using namespace ai;

int CalculDistance::Calculator(const Point& a, const Point& b){
    
    distance = abs(a.getX()-b.getX())+abs(a.getY()-b.getY());
    return distance;
}