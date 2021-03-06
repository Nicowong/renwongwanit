// Generated by dia2code
#ifndef ENGINE__ENDTURNCOMMAND__H
#define ENGINE__ENDTURNCOMMAND__H

#include <json/json.h>

namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class EndTurnCommand - 
  class EndTurnCommand : public engine::Command {
    // Attributes
  protected:
    state::State& state;
    // Operations
  public:
    EndTurnCommand (state::State& state);
    CommandTypeId getCommandTypeId () const;
    void execute (state::State& state);
    void debug () const;
    Json::Value toJson () const;
    // Setters and Getters
    state::State& getState() const;
    void setState(const state::State&& state);
  };

};

#endif
