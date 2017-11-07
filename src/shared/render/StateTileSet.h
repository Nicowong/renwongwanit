// Generated by dia2code
#ifndef RENDER__STATETILESET__H
#define RENDER__STATETILESET__H

#include <string>

namespace render {
  class Tile;
  class TileSet;
}

#include "Tile.h"
#include "TileSet.h"

namespace render {

  /// class StateTileSet - 
  class StateTileSet : public render::TileSet {
    // Operations
  public:
    int getCellWidth () const;
    int getCellHeight () const;
    std::string getFile () const;
    const Tile getTile (int i) const;
    // Setters and Getters
  };

};

#endif
