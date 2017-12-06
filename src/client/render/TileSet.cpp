#include <iostream>
#include "TileSet.h"

using namespace std;
using namespace render;

const Tile TileSet::getChar(char c)const{
	cout << "ERROR : TileSet::getChar()" << endl ;
	return Tile(0,0,0,0);
}
const Tile TileSet::getUnitTile(const state::Unit& u)const{
	cout << "ERROR : TileSet::getChar()" << endl ;
	return Tile(0, 0, 0, 0);
}