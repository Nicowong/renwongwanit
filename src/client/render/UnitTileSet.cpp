#include "../shared/render/UnitTileSet.h"
//
using namespace std ;
using namespace render ;

int UnitTileSet::getCellWidth () const{
    return 16 ;
}
int UnitTileSet::getCellHeight () const{
    return 16 ;
}
std::string UnitTileSet::getFile () const{
    return "res/unit.png" ;
}
const Tile UnitTileSet::getTile (int id) const{
    return Tile(id*16, (id%18)*16, 16, 16);
}
