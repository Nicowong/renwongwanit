// Generated by dia2code
#ifndef ENGINE__REPAIRECOMMAND__H
#define ENGINE__REPAIRECOMMAND__H


namespace engine {
  class Command;
}

#include "state/UnitType.h"
#include "Command.h"

namespace engine {

  /// class RepaireCommand - 
  class RepaireCommand : public engine::Command {
    // Attributes
  protected:
    int elementID;
    // Operations
  public:
    void RepairCommand (int element, state::UnitType unit);
    CommandTypeId const getTypeId ();
    void excute (state::State& state);
    // Setters and Getters
    int getElementID() const;
    void setElementID(int elementID);
  };

};

#endif