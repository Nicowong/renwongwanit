#include "CellTileSet.h"

using namespace std ;
using namespace render ;

int CellTileSet::getCellWidth () const{
    return 16 ;
}
int CellTileSet::getCellHeight () const{
    return 16 ;
}
std::string CellTileSet::getFile () const{
    return "res/cells.png" ;
}
const Tile CellTileSet::getTile (int id) const{
    return Tile(id*16, 0, 16, 16);
}
