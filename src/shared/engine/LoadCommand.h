// Generated by dia2code
#ifndef ENGINE__LOADCOMMAND__H
#define ENGINE__LOADCOMMAND__H


namespace state {
  class Unit;
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class LoadCommand - 
  class LoadCommand : public engine::Command {
    // Attributes
  protected:
    state::Unit& carrier;
    state::Unit& unit;
    // Operations
  public:
    LoadCommand (state::Unit& carrier, state::Unit& unit);
    CommandTypeId getCommandTypeId () const;
    void execute (state::State& state);
    // Setters and Getters
    state::Unit& getCarrier() const;
    void setCarrier(const state::Unit&& carrier);
    state::Unit& getUnit() const;
    void setUnit(const state::Unit&& unit);
  };

};

#endif
