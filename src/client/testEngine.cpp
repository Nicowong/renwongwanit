#include <iostream>
//#include <cstdlib>
#include <SFML/Graphics.hpp>
//#include <fstream>

#include "state.h"
#include "engine.h"
#include "render.h"

//#include "mapGeneration.h"

using namespace std ;
using namespace state ;
using namespace render ;
using namespace engine ;

// #define RDMAPGENITER 480
#define WIDTH	12
#define HEIGHT	12
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16+64

namespace engineTest{
	CellType* generateMap(int w, int h, string fname = "level.txt");
	void generateMap(State &state);
	void generateUnits(State &state);
};

using namespace engineTest ;

void testEngine(){
    int tick=0;

    State newState(WIDTH, HEIGHT);
    generateMap(newState);

    Engine eng(newState);
    eng.debug();
    generateUnits(newState);

    //eng.setCurrentState(newState);

// CLIENT ONLY
    Render render(newState) ;
    render.update();
//------------

    Unit& uRI   = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(1,0));
    Unit& uRR   = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(0,1));
    Unit& uRML  = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(0,4));
    Unit& uBT   = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(5,2));
    Unit& uBM   = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(4,3));
    Unit& uBMGT = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(3,4));
    Command* comMov1 = new MoveCommand(uRI, 2,2);
    Command* comMov2 = new MoveCommand(uRR, 3,3);
    Command* comAtt1 = new AttackCommand(uRR, uBM);
    Command* comMov3 = new MoveCommand(uBM, 3,2);
    Command* comAtt2 = new AttackCommand(uBM, uRI);
    Command* comMov4 = new MoveCommand(uBT, 4,3);
    Command* comAtt3 = new AttackCommand(uBT, uRR);
    Command* comAtt4 = new AttackCommand(uBMGT, uRR);
    Command* comAtt5 = new AttackCommand(uRML, uBMGT);
    eng.addCommand(comMov1);
    eng.addCommand(comMov2);
    eng.addCommand(comAtt1);
    eng.addCommand(comMov3);
    eng.addCommand(comAtt2);
    eng.addCommand(comMov4);
    eng.addCommand(comAtt3);
    eng.addCommand(comAtt4);
    eng.addCommand(comAtt5);

    eng.debug();
// CLIENT ONLY
    sf::RenderWindow window(sf::VideoMode(WINWIDTH, WINHEIGHT), "My window - test sprite");
    while(window.isOpen()){
        //check event
        sf::Event event ;
        while(window.pollEvent(event)){
            
            switch(event.type){
                case sf::Event::Closed :    //close request
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    cout << "<<< tick : "<< tick << " >>>"<< endl ;
                    tick++;
                    eng.update();
                    eng.debug();
                    render.update();
                    break ;
                default :
                    break;
            }
        }
        
        window.clear(sf::Color::Black);
        
        render.draw(window);
        
        window.display();
    }
//------------

}

namespace engineTest{

CellType* generateMap(int w, int h, string fname){
    CellType *tileMap = new CellType[w * h];
    
    int j;
    for(int j=0 ; j<HEIGHT-2 ; j++)
        for(int i=0 ; i<WIDTH ; i++)
            tileMap[i + j*WIDTH] = CT_PLAIN ; // plaine
    j=HEIGHT-2 ;
    for(int i=0 ; i<WIDTH ; i++)
        tileMap[i + j*WIDTH] = CT_SEA ; // mer
    j=HEIGHT-1 ;
    for(int i=0 ; i<WIDTH ; i++)
        tileMap[i + j*WIDTH] = CT_MOUNTAIN ; // montagne
    
    // placement de villes, routes
    tileMap[1+1*WIDTH] = CT_CITY ;
    tileMap[2+1*WIDTH] = CT_ROAD ;
    tileMap[2+2*WIDTH] = CT_BASE ;
    tileMap[2+3*WIDTH] = CT_ROAD ;
    tileMap[1+3*WIDTH] = CT_CITY ;
    tileMap[0+0*WIDTH] = CT_FOREST ;
    
    return tileMap ;
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