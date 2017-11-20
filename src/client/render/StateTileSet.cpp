#include "StateTileSet.h"
//
using namespace std ;
using namespace render ;

int StateTileSet::getTileWidth () const{
    return 16 ;
}
int StateTileSet::getTileHeight()const{
    return 16 ;
}
std::string StateTileSet::getFile () const{
    return "res/state.png" ;
}
const Tile StateTileSet::getTile (int id) const{
    return Tile(id*16, 0, 16, 16);
}
