#include <iostream>

#include "../shared/state/Building.h"

using namespace std ;
using namespace state ;

Building::Building(Team team, CellType cellType, size_t x, size_t y):
    Cell(cellType, x,y), capturePoints(20){
    this->type = T_BUILDING ;
    this->team = team ;
}
bool Building::isInCapture()const{
    if (capturePoints < 20)
        return true;
    else
        return false;
}
//Setters and Getters
int Building::getCapturePoints() const{
    return capturePoints ;
}
void Building::setCapturePoints(int capturePoints){
    this->capturePoints = capturePoints ;
}

void Building::debug()const{
    std::cout << "Building::" ;
    Cell::debug();
    std::cout << "capturePoint : "<<capturePoints << std::endl ;
}
