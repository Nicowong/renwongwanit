#include "StateTileSet.h"
//
using namespace std ;
using namespace render ;

int StateTileSet::getTileWidth () const{
    return 8 ;
}
int StateTileSet::getTileHeight()const{
    return 7 ;
}
std::string StateTileSet::getFile () const{
    return "res/status.png" ;
}
const Tile StateTileSet::getTile (int id) const{
    return Tile(id*8, 0, 8, 7);
}
