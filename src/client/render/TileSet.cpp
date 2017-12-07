#include <iostream>
#include "TileSet.h"

using namespace std;
using namespace state ;
using namespace render;

const Tile TileSet::getChar(char c)const{
	cout << "ERROR : TileSet::getChar()" << endl ;
	return Tile(0,0,0,0);
}
const Tile TileSet::getUnitTile(const state::Unit& u)const{
	cout << "ERROR : TileSet::getUnitTile()" << endl ;
	return Tile(0, 0, 0, 0);
}
const Tile TileSet::getCellTile(const state::Cell& c, int id)const{
	cout << "ERROR : TileSet::getCellTile()" << endl ;
	return Tile(0, 0, 0, 0);
}
const Tile TileSet::getBuildingTile(const state::Building& b)const{
	cout << "ERROR : TileSet::getBuildingTile()" << endl ;
	return Tile(0, 0, 0, 0);
}
state::TypeId TileSet::getType()const{
	return T_NONE ;
}
