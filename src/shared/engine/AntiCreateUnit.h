// Generated by dia2code
#ifndef ENGINE__ANTICREATEUNIT__H
#define ENGINE__ANTICREATEUNIT__H


namespace state {
  class State;
};
namespace engine {
  class AntiCommand;
}

#include "AntiCommand.h"

namespace engine {

  /// class AntiCreateUnit - 
  class AntiCreateUnit : public engine::AntiCommand {
    // Operations
  public:
    void execute (state::State& state);
    // Setters and Getters
  };

};

#endif
