// Generated by dia2code
#ifndef RENDER__LAYER__H
#define RENDER__LAYER__H

#include <memory>

namespace render {
  class Surface;
  class TileSet;
}

#include "Surface.h"
#include "TileSet.h"

namespace render {

  /// class Layer - 
  class Layer {
    // Associations
    // Attributes
  protected:
    std::unique_ptr<Surface> surface;
    std::shared_ptr<TileSet> tileSet;
    // Operations
  public:
    void update ();
    // Setters and Getters
    const std::unique_ptr<Surface>& getSurface() const;
    void setSurface(const std::unique_ptr<Surface>& surface);
    const std::shared_ptr<TileSet>& getTileSet() const;
    void setTileSet(const std::shared_ptr<TileSet>& tileSet);
  };

};

#endif
