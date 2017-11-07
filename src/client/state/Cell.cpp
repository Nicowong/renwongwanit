#include <iostream>

#include "../shared/state/Cell.h"
using namespace std; 
using namespace state;

Cell::Cell (CellType cellType, int x, int y):
    Element(T_CELL, NEUTRAL, x, y), cellType(cellType){
    
}
// Setters and Getters
CellType Cell::getCellType() const{
    return cellType ;
}
void Cell::setCellType(CellType cellType){
    this->cellType = cellType ;
}

void Cell::debug()const{
    std::cout << "Cell::";
    Element::debug();
    std::cout << "cellType : "<<cellType << std::endl ;
}
