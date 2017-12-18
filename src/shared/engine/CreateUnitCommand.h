// Generated by dia2code
#ifndef ENGINE__CREATEUNITCOMMAND__H
#define ENGINE__CREATEUNITCOMMAND__H


namespace state {
  class State;
  class Unit;
};
namespace engine {
  class Command;
}

#include "state/Unit.h"
#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class CreateUnitCommand - 
  class CreateUnitCommand : public engine::Command {
    // Attributes
  protected:
    state::State& state;
    state::Unit unit;
    // Operations
  public:
    CreateUnitCommand (state::State& state, state::UnitType utype, state::Team uteam, int x, int y, bool available = false, int health = 100, int ammo = 99);
    CreateUnitCommand (state::State& state, state::Unit& unit);
    CommandTypeId getCommandTypeId () const;
    void execute ();
    // Setters and Getters
    state::State& getState() const;
    void setState(const state::State&& state);
    const state::Unit& getUnit() const;
    void setUnit(const state::Unit& unit);
  };

};

#endif