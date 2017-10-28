#include "../shared/state/Building.h"

using namespace std ;
using namespace state ;

Building::Building(Team team, CellType type, int x, int y):
    Cell(type, x,y), capturePoints(20){
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
