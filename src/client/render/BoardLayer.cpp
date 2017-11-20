#include <iostream>
#include "BoardLayer.h"

using namespace std ;
using namespace sf ;
using namespace state ;
using namespace render ;

BoardLayer::BoardLayer(Surface* surface, TileSet* tileset): Layer(surface, tileset){

}

void BoardLayer::update(const state::ElementTab& tab){
	size_t nTile = tab.length();
	surface->initVertices(nTile);
	for(size_t n=0 ; n<nTile ; n++){
		const Element* elem = tab.getElem(n);
	//cout << "BoardLayer::update:: surface->setSpriteLocation(n, elem->getX(), elem->getY());" << endl ;
		surface->setSpriteLocation(n, elem->getX(), elem->getY());

		if(elem->getType() == T_UNIT){
			Unit* u = (Unit*)elem ;
			surface->setSpriteTexture(n, tileSet->getTile(u->getUnitType()+22*(u->getTeam()-1)));
		}else if(elem->getType() == T_BUILDING){
			//cout << "void BoardLayer::update(const state::ElementTab& tab):: elem->getType() == T_BUILDING" << endl ;
			//cout << "Cell* b = (Cell*)elem ; elem=" << elem << endl ; 
			Cell* b = (Cell*)elem ;
			//cout << "surface->setSpriteTexture(..." << elem << endl ; 
			surface->setSpriteTexture(n, tileSet->getTile((b->getCellType()-7)+5*(b->getTeam())));
		}else{
			//cout << "void BoardLayer::update(const state::ElementTab& tab):: elem->getType() == T_CELL" << endl ;
			//cout << "Cell* c = (Cell*)elem ; elem=" << elem << endl ; 
			Cell* c = (Cell*)elem ;
			//cout << "surface->setSpriteTexture(..." << elem << endl ; 
			//cout <<"surface="<<surface << " ; n=" <<n<< " ; tileSet="<<tileSet << " ; c="<<c <<endl ;
			surface->setSpriteTexture(n, tileSet->getTile(c->getCellType()-7) );
		}
	}
}