#include <iostream>
#include "StatusLayer.h"

using namespace std ;
using namespace state ;
using namespace render ;

StatusLayer::StatusLayer(Surface* surface, TileSet* ts): Layer(surface, ts){

}
StatusLayer::StatusLayer(){
	
}

void StatusLayer::update(const state::State& state){
	size_t nUnits[2] = {0,0} ;
	size_t nBuildings[3]={0,0,0} ;
	size_t nHealthBox = 0 ;
	size_t nTiles = 0 ;
	size_t n=0;

	const state::ElementTab& cellTab = state.getCellTab();
	const state::ElementTab& unitTab = state.getUnitTab();

	//count nb buildings, nb units, nb hp boxes
	for(size_t j=0 ; j<state.getH() ; j++){
		for(size_t i=0 ; i<state.getW() ; i++){
			//Building count
			state::Cell* c = (Cell*)cellTab.getElem(i,j);
			if(c != nullptr){
				state::CellType ct = c->getCellType();
				if(ct==CT_BASE || ct==CT_CITY || ct==CT_FACTORY || ct==CT_AIRPORT || ct==CT_SEAPORT){
					state::Team team = c->getTeam();
					switch(team){
						case NEUTRAL :
							nBuildings[0]++;
							break;
						case PLAYER1 :
							nBuildings[1]++;
							break;
						case PLAYER2 :
							nBuildings[2]++;
							break;
						default :
							break;
					}
				}
			}
			//Unit count
			state::Unit* u = (Unit*)unitTab.getElem(i,j);
			if(u != nullptr){
				state::Team team = u->getTeam();
				switch(team){
					case PLAYER1 :
						nUnits[0]++;
						break;
					case PLAYER2 :
						nUnits[1]++;
						break;
					default :
						break;
				}
				if(u->getHealth() < 91)
					nHealthBox++;
			}
		}
	}

	nTiles = nHealthBox ; //nUnits[0]+nUnits[1]+nBuildings[0]+nBuildings[1]+nBuildings[2]+nHealthBox ;
	surface->initVertices(nTiles);

	for(size_t j=0 ; j<state.getH() ; j++){
		for(size_t i=0 ; i<state.getW() ; i++){
			state::Unit* u = (Unit*)unitTab.getElem(i,j);
			if(u!=nullptr && u->getHealth()<91){
				surface->setSpriteLocation(n, Tile(i*16+8, j*16+8, 8,7) );
				surface->setSpriteTexture(n, tileSet->getTile( (u->getHealth()-1)/10 ));
				n++ ;
			}
		}
	}
}
