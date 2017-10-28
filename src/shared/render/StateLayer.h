// Generated by dia2code
#ifndef RENDER__STATELAYER__H
#define RENDER__STATELAYER__H


namespace state {
  class Unit;
  class Building;
  class Cell;
};
namespace render {
  class Layer;
}

#include "Layer.h"
#include "state/Building.h"
#include "state/Unit.h"

namespace render {

  /// class StateLayer - 
  class StateLayer : public render::Layer {
    // Associations
    // Attributes
  private:
    const Unit& unitLayer;
    const Building& buildingLayer;
    const Cell& cellLayer;
    // Operations
  public:
    virtual CellLayer (const cell:Cell& cell);
    UnitLayer (const unit:Unit& unit);
    BuildingLayer (const building:Building& building);
    virtual void initSurface ();
  protected:
    virtual void printUnit () = 0;
    virtual void printBuilding () = 0;
    virtual void printCell () = 0;
    // Setters and Getters
  };

};

#endif
