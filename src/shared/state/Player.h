// Generated by dia2code
#ifndef STATE__PLAYER__H
#define STATE__PLAYER__H

#include <vector>

namespace state {
  class Unit;
  class Building;
}

#include "Building.h"
#include "Unit.h"

namespace state {

  /// class Player - 
  class Player {
    // Associations
    // Attributes
  protected:
    int PlayerID;
    std::vector<Unit*> UnitList;
    std::vector<Building*> BuildingList;
    // Operations
  public:
    Building* getBuilding (int i);
    Unit* getUnit (int i);
    // Setters and Getters
    int getPlayerID() const;
    void setPlayerID(int playerID);
    const std::vector<Unit*>& getUnitList() const;
    void setUnitList(const std::vector<Unit*>& unitList);
    const std::vector<Building*>& getBuildingList() const;
    void setBuildingList(const std::vector<Building*>& buildingList);
  };

};

#endif
