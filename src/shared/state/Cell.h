// Generated by dia2code
#ifndef STATE__CELL__H
#define STATE__CELL__H


namespace state {
  class Building;
  class Unit;
}

#include "CellType.h"
#include "Building.h"
#include "Unit.h"

namespace state {

  /// class Cell - 
  class Cell {
    // Associations
    // Attributes
  protected:
    int x;
    int y;
    Building* building;
    Unit* unit;
    CellType cellType;
    // Operations
  public:
    Cell ();
    Cell (CellType cType, int x = 0, int y = 0);
    Building* getBuilding ();
    Unit* getUnit ();
    CellType getCellType () const;
    // Setters and Getters
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    void setBuilding(const Building*& building);
    void setUnit(const Unit*& unit);
    void setCellType(CellType cellType);
  };

};

#endif
