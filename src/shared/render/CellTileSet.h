// Generated by dia2code
#ifndef RENDER__CELLTILESET__H
#define RENDER__CELLTILESET__H

#include <string>

namespace render {
  class Tile;
  class TileSet;
}

#include "Tile.h"
#include "TileSet.h"

namespace render {

  /// class CellTileSet - 
  class CellTileSet : public render::TileSet {
    // Operations
  public:
    int getCellWidth () const;
    int getCellHeight () const;
    std::string getFile () const;
    const Tile getTile (int id) const;
    // Setters and Getters
  };

};

#endif
