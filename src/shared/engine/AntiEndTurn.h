// Generated by dia2code
#ifndef ENGINE__ANTIENDTURN__H
#define ENGINE__ANTIENDTURN__H


namespace state {
  class State;
};
namespace engine {
  class AntiCommand;
}

#include "AntiCommand.h"

namespace engine {

  /// class AntiEndTurn - 
  class AntiEndTurn : public engine::AntiCommand {
    // Operations
  public:
    void execute (state::State& state);
    // Setters and Getters
  };

};

#endif
