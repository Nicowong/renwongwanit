// Generated by dia2code
#ifndef ENGINE__ENGINE__H
#define ENGINE__ENGINE__H

#include <vector>
#include <stdlib.h>
#include <string>

namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "state/State.h"
#include "Command.h"

namespace engine {

  /// class Engine - 
  class Engine {
    // Associations
    // Attributes
  protected:
    state::State currentState;
    std::vector<Command*> currentCommands;
    // Operations
  public:
    Engine (size_t w = 30, size_t h = 20);
    Engine (std::string filename);
    ~Engine ();
    const state::State& getState () const;
    void addCommand (Command* cmd);
    void update ();
    // Setters and Getters
    const state::State& getCurrentState() const;
    void setCurrentState(const state::State& currentState);
    const std::vector<Command*>& getCurrentCommands() const;
    void setCurrentCommands(const std::vector<Command*>& currentCommands);
  };

};

#endif
