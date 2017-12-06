#include <iostream>
#include "BoardLayer.h"
#include "CellSpriteRule.h"

using namespace std ;
using namespace sf ;
using namespace state ;
using namespace render ;

extern const int CellSpriteRule[16];

BoardLayer::BoardLayer(Surface* surface, TileSet* tileset): Layer(surface, tileset){
}

void BoardLayer::update(const state::ElementTab& tab){
	size_t nTile = tab.length();
	surface->initVertices(nTile);
	size_t n=0 ;
	if(tab.getType()==T_UNIT){
		for(size_t j=0 ; j<tab.getH() ; j++){
			for(size_t i=0 ; i<tab.getW() ; i++){
				const Element* elem = tab.getElem(i,j);
				if(elem != nullptr && elem->getType() == T_UNIT){
					Unit* u = (Unit*)elem ;
					surface->setSpriteTexture(n, tileSet->getUnitTile(*u) );
					surface->setSpriteLocation(n, Tile(i*16, j*16, 16, 16));
					n++ ;
				}
			}
		}
	}
	else if(tab.getType()==T_CELL || tab.getType()==T_BUILDING){
		for(size_t j=0 ; j<tab.getH() ; j++){
			for(size_t i=0 ; i<tab.getW() ; i++){
				const Element* elem = tab.getElem(i,j);
				if(elem != nullptr){
					Cell* c = (Cell*)elem ;
					TypeId tid = c->getType();
					CellType ct = c->getCellType();
					if(tid == T_BUILDING){
						surface->setSpriteTexture(n, tileSet->getBuildingTile(*(Building*)c) );
						surface->setSpriteLocation(n, Tile(i*16, (j-1)*16, 32, 32) );
						n++ ;
					}else if(tid == T_CELL){
						int id=0, csr=0;
						if(ct == CT_ROAD || ct == CT_RIVER || ct == CT_SEA){
							Cell* cr=(Cell*)(tab.getElem(i+1,j)), cu=(Cell*)(tab.getElem(i,j-1));
							Cell* cl=(Cell*)(tab.getElem(i-1,j)), cd=(Cell*)(tab.getElem(i,j+1));
							if(cr!=nullptr && cr->getCellType()==ct) csr += 1 ;
							if(cu!=nullptr && cu->getCellType()==ct) csr += 2 ;
							if(cl!=nullptr && cl->getCellType()==ct) csr += 4 ;
							if(cd!=nullptr && cd->getCellType()==ct) csr += 8 ;
							id = CellSpriteRule[csr];
							if(csr==0 && ct==CT_SEA) id = 11 ;
						}
						surface->setSpriteTexture(n, tileSet->getCellTile(*c, id) );
						surface->setSpriteLocation(n, Tile(i*16, j*16, 16, 16) );
						n++ ;
					}else
						cout << "ERROR2 : BoardLayer::update()" << endl ;
				}
			}
		}
	}
	else
		cout << "ERROR1 : BoardLayer::update()" << endl ;
}
