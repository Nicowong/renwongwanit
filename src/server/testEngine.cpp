#include <iostream>
//#include <cstdlib>
#include <SFML/Graphics.hpp>
//#include <fstream>

#include "state.h"
#include "engine.h"
//#include "render.h"

#include "engineTestGenerator.hpp"

using namespace std ;
using namespace state ;
//using namespace render ;
using namespace engine ;

// #define RDMAPGENITER 480
#define WIDTH   8 
#define HEIGHT  6
//#define WINWIDTH WIDTH*16
//#define WINHEIGHT HEIGHT*16+64

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
//    Render render(newState) ;
//    render.update();
//------------

    Unit* puRI = (Unit*)(eng.getCurrentState().getUnitTab().getElem(1,0));
    Unit* puRR = (Unit*)(eng.getCurrentState().getUnitTab().getElem(0,1));
    Unit* puBT = (Unit*)(eng.getCurrentState().getUnitTab().getElem(5,2));
    Unit* puBM = (Unit*)(eng.getCurrentState().getUnitTab().getElem(4,3));
    Unit& RI = *puRI ;
    Unit& RR = *puRR ;
    Unit& BT = *puBT ;
    Unit& BM = *puBM ;
    Command* comMov1 = new MoveCommand(RI, 2,2);
    Command* comMov2 = new MoveCommand(RR, 3,3);
    Command* comAtt1 = new AttackCommand(RR, BM);
    Command* comMov3 = new MoveCommand(BM, 3,2);
    Command* comAtt2 = new AttackCommand(BM, RI);
    Command* comMov4 = new MoveCommand(BT, 4,3);
    Command* comAtt3 = new AttackCommand(BT, RR);
    eng.addCommand(comMov1);
    eng.addCommand(comMov2);
    eng.addCommand(comAtt1);
    eng.addCommand(comMov3);
    eng.addCommand(comAtt2);
    eng.addCommand(comMov4);
    eng.addCommand(comAtt3);

    eng.debug();
//SERVER ONLY

    cout << "<<< tick : "<< tick << " >>>"<< endl ;
    tick++;
    eng.update();
    eng.debug();

// CLIENT ONLY
/*    sf::RenderWindow window(sf::VideoMode(WINWIDTH, WINHEIGHT), "My window - test sprite");
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
    }*/
//------------

}
