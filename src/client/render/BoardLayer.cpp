#include <iostream>
#include "BoardLayer.h"
#include "CellSpriteRule.h"

using namespace std ;
using namespace sf ;
using namespace state ;
using namespace render ;

extern const int cellSpriteRule[16];

BoardLayer::BoardLayer(Surface* surface, TileSet* tileset): Layer(surface, tileset){
}

void BoardLayer::update(const state::ElementTab& tab){
	size_t nTile = tab.length();
	surface->initVertices(nTile);
	size_t n=0 ;
	TypeId ttid = tab.getType();
	TypeId ltid = tileSet->getType();
	if(ttid==T_UNIT && ltid==T_UNIT){
		//cout << "UNIT TAB"<< endl;
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
	else if((ttid==T_CELL || ttid==T_BUILDING) && ltid==T_BUILDING){
		//cout << "BUILDING TAB"<< endl;
		for(size_t j=0 ; j<tab.getH() ; j++){
			for(size_t i=0 ; i<tab.getW() ; i++){
				const Element* elem = tab.getElem(i,j);
				if(elem != nullptr){
					Cell* c = (Cell*)elem ;
					TypeId tid = c->getType();
					CellType ct = c->getCellType();
					if(tid == T_BUILDING || tid == T_CELL){
						if(ct>=7){
							//if(ct == CT_BASE) cout << "CT_BASE" << endl ;
							surface->setSpriteTexture(n, tileSet->getBuildingTile(*(Building*)c) );
							surface->setSpriteLocation(n, Tile(i*16, (j-1)*16, 32, 32) );
						}else{
							surface->setSpriteTexture(n, Tile(0,0,16,16) );
							surface->setSpriteLocation(n, Tile(i*16, j*16, 16, 16) );
						}
						n++ ;
					}
				}
			}
		}
	}
	else if((ttid==T_CELL || ttid==T_BUILDING) && ltid==T_CELL){
		//cout << "CELL TAB"<< endl;
		for(size_t j=0 ; j<tab.getH() ; j++){
			for(size_t i=0 ; i<tab.getW() ; i++){
				const Element* elem = tab.getElem(i,j);
				if(elem != nullptr){
					Cell* c = (Cell*)elem ;
					TypeId tid = c->getType();
					CellType ct = c->getCellType();
					if(tid == T_CELL){
						int id=0, csr=0;
						if(ct == CT_ROAD || ct == CT_RIVER || ct == CT_SEA){
							Cell *cr=(Cell*)(tab.getElem(i+1,j)), *cu=(Cell*)(tab.getElem(i,j-1));
							Cell *cl=(Cell*)(tab.getElem(i-1,j)), *cd=(Cell*)(tab.getElem(i,j+1));
							if(cr!=nullptr && cr->getCellType()==ct) csr += 1 ;
							if(cu!=nullptr && cu->getCellType()==ct) csr += 2 ;
							if(cl!=nullptr && cl->getCellType()==ct) csr += 4 ;
							if(cd!=nullptr && cd->getCellType()==ct) csr += 8 ;
							id = cellSpriteRule[csr];
							if(csr==0 && ct==CT_SEA) id = 11 ;
						}
						if(ct<7){
							surface->setSpriteTexture(n, tileSet->getCellTile(*c, id) );
							surface->setSpriteLocation(n, Tile(i*16, j*16, 16, 16) );
						}else{
							if(ct==CT_SEAPORT)
								surface->setSpriteTexture(n, tileSet->getCellTile(Cell(CT_SEA), 0) );
							else
								surface->setSpriteTexture(n, tileSet->getCellTile(Cell(CT_PLAIN), 0) );
							surface->setSpriteLocation(n, Tile(i*16, j*16, 16, 16) );
						}
						n++ ;
					}
				}
			}
		}
	}
	else
		cout << "ERROR1 : BoardLayer::update()" << endl ;
}
