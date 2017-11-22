// Generated by dia2code
#ifndef AI__RANDOMAI__H
#define AI__RANDOMAI__H


namespace engine {
  class Engine;
};
namespace state {
  class Element;
};
namespace ai {
  class Ai;
};
namespace state {
  class State;
}

#include "Ai.h"
#include "state/State.h"

namespace ai {

  /// class RandomAi - 
  class RandomAi : public ai::Ai {
    // Operations
  public:
    RandomAi ();
    void run (engine::Engine& engine, state::Element& selected);
    // Setters and Getters
  };

};

#endif
