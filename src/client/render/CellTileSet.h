// Generated by dia2code
#ifndef RENDER__CELLTILESET__H
#define RENDER__CELLTILESET__H

#include <string>

namespace render {
  class Tile;
};
namespace state {
  class Cell;
};
namespace render {
  class TileSet;
}

#include "Tile.h"
#include "state/TypeId.h"
#include "TileSet.h"

namespace render {

  /// class CellTileSet - 
  class CellTileSet : public render::TileSet {
    // Operations
  public:
    int getTileWidth () const;
    int getTileHeight () const;
    std::string getFile () const;
    const Tile getTile (int id) const;
    const Tile getCellTile (const state::Cell& c, int id = 0) const;
    state::TypeId getType () const;
    // Setters and Getters
  };

};

#endif
