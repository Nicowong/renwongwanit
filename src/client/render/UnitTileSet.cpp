#include "UnitTileSet.h"
//
using namespace std ;
using namespace render ;

int UnitTileSet::getTileWidth () const{
    return 16 ;
}
int UnitTileSet::getTileHeight () const{
    return 16 ;
}
std::string UnitTileSet::getFile () const{
    return "res/units.png" ;
}
const Tile UnitTileSet::getTile (int id) const{
    return Tile((id%22)*16, (id/22)*16, 16, 16);
}
