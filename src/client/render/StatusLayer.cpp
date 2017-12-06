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
	size_t nChar = 0 ;
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
				//u->debug();
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
				if(0 < u->getHealth() && u->getHealth() < 91)		// count health boxes
					nHealthBox++;
			}
		}
	}

	nTiles = nHealthBox ; //nUnits[0]+nUnits[1]+nBuildings[0]+nBuildings[1]+nBuildings[2]+nHealthBox ;
	string day= "Day : "+to_string(state.getDay());
	string turn= "Turn : "+to_string(state.getTurn());
	nChar = day.length()+turn.length();
	surface->initVertices(nTiles+nChar);

//place health boxes
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
//print text
	
	int tx, ty;
	tx = 0 ;
	ty = state.getH()*16;
	print(tx, ty, "Day : "+to_string(state.getDay())+'\n');
	tx = 0 ;
	ty = state.getH()*16+10;
	if(state.getTurn()==PLAYER1){
		cout << "--"<<"TURN : Player 1\n" ;
		print(tx, ty, "TURN : Player 1");//\n");
	}
	else{
		cout << "--"<<"TURN : Player 2\n" ;
		print(tx, ty, "TURN : Player 2");//\n");
	}

}

void StatusLayer::print(int& x, int& y, const std::string& text){
	size_t l = text.length();
	unsigned int vl0 = surface->getVertices().getVertexCount()/4;
	int tx=x, ty=y ;
	surface->addVertices(l);
	for(size_t i=0 ; i<l ; i++){
		if(text[i]=='\n'){
			tx = x ;
			ty += 10 ;
		}else{
			surface->setSpriteLocation(vl0+i, Tile(tx, ty, 7, 10));
			surface->setSpriteTexture(vl0+i, tileSet->getChar(text[i]));
			tx += 7 ;
		}
	}
	x = tx ;
	y = ty ;
}