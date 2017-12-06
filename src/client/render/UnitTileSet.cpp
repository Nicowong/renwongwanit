#include "UnitTileSet.h"
//
using namespace std ;
using namespace state ;
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
    return Tile((id%22+1)*16, (id/22)*16, 16, 16);
}

const Tile UnitTileSet::getUnitTile(const state::Unit& u)const{
	int x = ((int)u.getUnitType()+1)*16 ;
	int y = (u.getTeam()-1)*16 ;
	if(!u.getAvailable() && u.getMoved())
		y+=80 ;
	int w = 16 ;
	int h = 16 ;
	return Tile(x, y, w, h);
}