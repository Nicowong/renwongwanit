// Generated by dia2code
#ifndef RENDER__UNITTILESET__H
#define RENDER__UNITTILESET__H

#include <string>

namespace render {
  class Tile;
  class TileSet;
}

#include "TileSet.h"

namespace render {

  /// class UnitTileSet - 
  class UnitTileSet : public render::TileSet {
    // Operations
  public:
    int getCellWidth () const;
    int getCellHeight () const;
    std::string getFile () const;
    const Tile& getTile (int id) const;
    // Setters and Getters
  };

};

#endif
