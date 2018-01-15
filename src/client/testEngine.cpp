#include <iostream>
//#include <cstdlib>
#include <SFML/Graphics.hpp>
//#include <fstream>

#include "state.h"
#include "engine.h"
#include "render.h"

#include "engineTestGenerator.hpp"

using namespace std ;
using namespace state ;
using namespace render ;
using namespace engine ;

// #define RDMAPGENITER 480
#define WIDTH	12
#define HEIGHT	12
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16+64

using namespace engineTest ;

void testEngine(){
    int tick=0;

    State state(WIDTH, HEIGHT);
    generateMap(state);
    generateUnits(state);

    Engine eng(state);
    eng.debug();

    //eng.setCurrentState(newState);

// CLIENT ONLY
    Render render(state) ;
    render.update();
//------------

    Unit& uRI   = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(1,0));
    Unit& uRR   = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(0,1));
    Unit& uRML  = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(0,4));
    Unit& uBT   = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(5,2));
    Unit& uBM   = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(4,3));
    Unit& uBMGT = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(3,4));
    Command* cMvRID1    = new MoveCommand(uRI, 2,2);
    Command* cMvRRD1    = new MoveCommand(uRR, 3,3);
    Command* cAtRRD1    = new AttackCommand(uRR, uBM);
    Command* cAtRMlD1   = new AttackCommand(uRML, uBMGT);
    Command* cEdRD1     = new EndTurnCommand(state);
    Command* cMvBMD1    = new MoveCommand(uBM, 3,2);
    Command* cAtBMD1    = new AttackCommand(uBM, uRI);
    Command* cMvBTD1    = new MoveCommand(uBT, 4,3);
    Command* cAtBTD1    = new AttackCommand(uBT, uRR);
    Command* cAtBMgtD1  = new AttackCommand(uBMGT, uRR);
    Command* cEdBD1     = new EndTurnCommand(state);
    Command* cAtRMlD2   = new AttackCommand(uRML, uBMGT);
    Command* cEdRD2     = new EndTurnCommand(state);
    eng.addCommand(cMvRID1)     ;   //move inftr
    eng.addCommand(cMvRRD1)     ;   //move recon
    eng.addCommand(cAtRRD1)     ;   //recon attack mech
    eng.addCommand(cAtRMlD1)    ;   //missileLauncher attack megatank
    eng.addCommand(cEdRD1)      ;   //-endTurn-
    eng.addCommand(cMvBMD1)     ;   //move mech
    eng.addCommand(cAtBMD1)     ;   //mech attack inftr
    eng.addCommand(cMvBTD1)     ;   //move tank
    eng.addCommand(cAtBTD1)     ;   //tank attack recon
    eng.addCommand(cAtBMgtD1)   ;   //megatank attack recon
    eng.addCommand(cEdBD1)      ;   //-endTurn-
    eng.addCommand(cAtRMlD2)    ;   //missileLauncher attack megatank
    eng.addCommand(cEdRD2)      ;   //-endTurn-

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
                    cout << endl ;
                    break ;
                case sf::Event::MouseButtonReleased :
                    cout << "click"<<endl ;
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
