// Generated by dia2code
#ifndef RENDER__TILESET__H
#define RENDER__TILESET__H

#include <string>

namespace render {
  class Tile;
}

#include "Tile.h"

namespace render {

  /// class TileSet - 
  class TileSet {
    // Associations
    // Operations
  public:
    ~TileSet ();
    int const getCellWidth ();
    int const getCellHeight ();
    const std::string const getImageFile ();
    const Tile& const getTile (const state::Element& e);
    // Setters and Getters
  };

};

#endif
