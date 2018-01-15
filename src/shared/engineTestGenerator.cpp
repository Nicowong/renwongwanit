#include "engineTestGenerator.hpp"

namespace engineTest{

CellType* generateMap(int w, int h, string fname){
    CellType *tileMap = new CellType[w * h];
    
    int j;
    for(int j=0 ; j<h-2 ; j++)
        for(int i=0 ; i<w ; i++)
            tileMap[i + j*w] = CT_PLAIN ; // plaine
    j=h-2 ;
    for(int i=0 ; i<w ; i++)
        tileMap[i + j*w] = CT_SEA ; // mer
    j=h-1 ;
    for(int i=0 ; i<w ; i++)
        tileMap[i + j*w] = CT_MOUNTAIN ; // montagne
    
    // placement de villes, routes
    tileMap[1+1*w] = CT_CITY ;
    tileMap[2+1*w] = CT_ROAD ;
    tileMap[2+2*w] = CT_BASE ;
    tileMap[2+3*w] = CT_ROAD ;
    tileMap[1+3*w] = CT_CITY ;
    tileMap[0+0*w] = CT_FOREST ;
    
    return tileMap ;
}

void generateMap(State &state){
    CellType* map = generateMap(state.getW(), state.getH(), "level.txt");
    ElementTab& ctab = state.getCellTab();
    for(size_t j=0 ; j<state.getH() ; j++){
        for(size_t i=0 ; i<state.getW() ; i++){
            Element *c ;
            if(i==2 && j==2)
                c = new Building(PLAYER1, CT_BASE, i, j);
            else
                c = new Cell(map[i+j*state.getW()], i,j);
            ctab.addElem(c);
        }
    }
}

void generateUnits(State &state){
	ElementTab& unitTab = state.getUnitTab();
	Unit* p1u1 = new Unit(PLAYER1, UT_INFANTRY, 1,0);
	Unit* p1u2 = new Unit(PLAYER1, UT_RECON, 0,1);
    Unit* p1u3 = new Unit(PLAYER1, UT_MISSILELAUNCHER, 0,4);
	Unit* p2u1 = new Unit(PLAYER2, UT_TANK, 5,2);
	Unit* p2u2 = new Unit(PLAYER2, UT_MECH, 4,3);
    Unit* p2u3 = new Unit(PLAYER2, UT_MEGATANK, 3,4);
	unitTab.addElem(p1u1);
	unitTab.addElem(p1u2);
    unitTab.addElem(p1u3);
	unitTab.addElem(p2u1);
	unitTab.addElem(p2u2);
    unitTab.addElem(p2u3);
}

};