// Generated by dia2code
#ifndef ENGINE__LOADCOMMAND__H
#define ENGINE__LOADCOMMAND__H


namespace state {
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
  public:
    state::Unit& unit;
  protected:
    state::Unit& carrier;
    // Operations
  public:
    LoadCommand (state::Unit& carrier, state::Unit& unit);
    CommandTypeId getCommandTypeId () const;
    void execute (state::State& state);
    // Setters and Getters
    state::Unit& getCarrier() const;
    void setCarrier(const state::Unit&& carrier);
  };

};

#endif
