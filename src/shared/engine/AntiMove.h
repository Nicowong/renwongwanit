// Generated by dia2code
#ifndef ENGINE__ANTIMOVE__H
#define ENGINE__ANTIMOVE__H


namespace state {
  class State;
};
namespace engine {
  class AntiCommand;
}

#include "AntiCommand.h"

namespace engine {

  /// class AntiMove - 
  class AntiMove : public engine::AntiCommand {
    // Operations
  public:
    void execute (state::State& state);
    // Setters and Getters
  };

};

#endif
