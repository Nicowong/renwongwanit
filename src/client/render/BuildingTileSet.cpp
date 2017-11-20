#include "BuildingTileSet.h"
//
using namespace std ;
using namespace render ;

int BuildingTileSet::getTileWidth () const{
    return 16 ;
}
int BuildingTileSet::getTileHeight () const{
    return 16 ;
}
std::string BuildingTileSet::getFile () const{
    return "res/buildings.png" ;
}
const Tile BuildingTileSet::getTile (int id) const{
    return Tile(id*16, (id%5)*16, 16, 16);
}
