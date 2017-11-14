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
}

#include "Ai.h"

namespace ai {

  /// class RandomAi - 
  class RandomAi : public ai::Ai {
    // Operations
  public:
    RandomAi ();
    void run (engine::Engine& engine, Element& selected);
    // Setters and Getters
  };

};

#endif
