#include <iostream>
//#include <cstdlib>
#include <SFML/Graphics.hpp>
//#include <fstream>

#include "state.h"
#include "engine.h"
//#include "render.h"

#include "mapGeneration.h"
#include "CommandGeneration.h"

using namespace std ;
using namespace state ;
//using namespace render ;
using namespace engine ;

// #define RDMAPGENITER 480
#define WIDTH   8 
#define HEIGHT  6
//#define WINWIDTH WIDTH*16
//#define WINHEIGHT HEIGHT*16+64

using namespace mapGeneration ;
using namespace CommandGeneration ;

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

    generateCommand(eng);

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
