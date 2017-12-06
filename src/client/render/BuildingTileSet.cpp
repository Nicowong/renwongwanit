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
    return Tile((id%5)*16, (id/5)*16, 16, 16);
}
const Tile BuildingTileSet::getBuildingTile (const state::Building& b) const{
	int x = (b.getCellType()-7)*32 ;
	int y = (c.getTeam())*32 ;
	int w = 32 ;
	int h = 32 ;

	return Tile(x, y, w, h);
}
