#include "CellTileSet.h"

using namespace std ;
using namespace state ;
using namespace render ;

int CellTileSet::getTileWidth () const{
    return 16 ;
}
int CellTileSet::getTileHeight () const{
    return 16 ;
}
std::string CellTileSet::getFile ()const{
    return "res/cells.png" ;
}
//obsolete
const Tile CellTileSet::getTile (int id) const{
    return Tile(id*16, 0, 16, 16);
}

const Tile CellTileSet::getCellTile(const state::Cell& c, int id)const{
	int x = id*16 ;
	int y = (c.getCellType())*16 ;
	int w = 16 ;
	int h = 16 ;

	return Tile(x, y, w, h);
}
state::TypeId CellTileSet::getType()const{
	return T_CELL ;
}
