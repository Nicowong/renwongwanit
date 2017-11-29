// Generated by dia2code
#ifndef RENDER__STATUSLAYER__H
#define RENDER__STATUSLAYER__H


namespace render {
  class Surface;
  class TileSet;
};
namespace state {
  class State;
};
namespace render {
  class Layer;
}

#include "Layer.h"
#include "state/State.h"

namespace render {

  /// class StatusLayer - 
  class StatusLayer : public render::Layer {
    // Operations
  public:
    StatusLayer (Surface* surface, TileSet* tileset);
    StatusLayer ();
    void update (const state::State& state);
    // Setters and Getters
  };

};

#endif
