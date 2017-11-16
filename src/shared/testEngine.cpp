#include <iostream>
//#include <cstdlib>
//#include <SFML/Graphics.hpp>
//#include <fstream>

#include "state.h"
#include "engine.h"

using namespace std ;
using namespace state ;
using namespace engine ;

#define RDMAPGENITER 480
#define WIDTH	6 
#define HEIGHT	4

namespace engineTest{
	CellType* generateMap(int w, int h, string fname = "level.txt");
	CellType generateCell();
	void generateRoad(int x, int y, CellType* map);
	void saveMap(CellType *map, int w, int h, string fname="level.txt");
	int* loadMap(string fname="level.txt");
	void generateMap(State &state);
	void generateUnits(State &state);
	void generateUnits(State &state);
};

using namespace engineTest ;

void testEngine(){
    Engine eng(WIDTH, HEIGHT);
    //eng.debug(); 

    State newState(WIDTH, HEIGHT);
    generateMap(newState);
    eng.debug();
    generateUnits(newState);

    eng.setCurrentState(newState);
    eng.debug();

}

namespace engineTest{

CellType* generateMap(int w, int h, string fname){
    CellType *tileMap = new CellType[w * h];
    
    for(int i=0 ; i<w ; i++)
        for(int j=0 ; j<h ; j++){
            tileMap[i + j*w] = generateCell() ; // plaine, foret, montagne, mer
        }
    
    for(int n=0 ; n<RDMAPGENITER ; n++){    //traitement de carte (homogeneisation)
        int x = rand()%w ; // selectionne une case
        int y = rand()%h ;
        
        if(rand()%100 < 60){ //prend la valeur d'un voisin, sinon rien
            int vx=x, vy=y ;
            if(rand()%2==0)
                vx += (rand()%2)*2 -1 ;
            else
                vy += (rand()%2)*2 -1 ;
            
            if(vx>=0 && vx<w && vy>=0 && vy<h)
                tileMap[vx + vy*w] = tileMap[x + y*w];
        }
        if(n%(RDMAPGENITER/10) == 0)
            cout << "." ;
    }
    
    cout << endl ;
    
    // placement de villes, routes
    do{
        int x = rand()%w ;
        int y = rand()%h ;
        tileMap[x+y*w] = CT_CITY ;
        generateRoad(x, y, tileMap);
    }while(rand()%100 < 90);
    
    int x = rand()%w ; //placement du QG
    int y = rand()%h ;
    
    generateRoad(x, y, tileMap);
    tileMap[x+y*w] = CT_BASE ;
    
    /*if(fname != "NULL");
        saveMap(tileMap, w, h, fname);*/
    
    return tileMap ;
}

CellType generateCell(){
    const int pG=40, pS=15, pM=15, pF=20 ;
    int ct = rand()%(pG+pS+pM+pF) ;
    if(ct < pG)
        return CT_PLAIN ;
    else if(ct < pG+pS)
        return CT_SEA ;
    else if(ct < pG+pS+pM)
        return CT_MOUNTAIN ;
    else
        return CT_FOREST ;
}

void generateRoad(int x, int y, CellType* map){
    do{
        if(rand()%2 == 0)
            x = x+ (rand()%2)*2-1;
        else
            y = y+ (rand()%2)*2-1;
            
        if(x<0 || y<0 || x>=WIDTH || y>=HEIGHT)
            break;
            
        if(map[x+y*WIDTH]==CT_SEA)
            map[x+y*WIDTH]=CT_BRIDGE ;
        else
            map[x+y*WIDTH]=CT_ROAD ;
    }while(rand()%100<75);
    if(rand()%100 < 75)
        map[x+y*WIDTH] = CT_CITY ;
}
void generateMap(State &state){
    CellType* map = generateMap(state.getW(), state.getH(), "level.txt");
    ElementTab& ctab = state.getCellTab();
    for(size_t j=0 ; j<state.getH() ; j++){
        for(size_t i=0 ; i<state.getW() ; i++){
            Element *c = new Cell(map[i+j*state.getW()], i,j);
            //cout << c << " " ;
            //c->debug() ;
            ctab.addElem(c);
        }
    }
    
}
void generateUnits(State &state){
	ElementTab& unitTab = state.getUnitTab();
	Unit* p1u1 = new Unit(PLAYER1, UT_INFANTRY, 0,0);
	//cout << endl << "p1u1:" << p1u1 << endl ;
	//p1u1->debug();
	Unit* p1u2 = new Unit(PLAYER1, UT_RECON, 1,0);
	Unit* p2u1 = new Unit(PLAYER2, UT_INFANTRY, 2,0);
	Unit* p2u2 = new Unit(PLAYER2, UT_RECON, 3,0);
	unitTab.addElem(p1u1);
	unitTab.addElem(p1u2);
	unitTab.addElem(p2u1);
	unitTab.addElem(p2u2);
}

};