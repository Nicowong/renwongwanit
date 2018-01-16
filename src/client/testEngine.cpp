#include <iostream>
//#include <cstdlib>
#include <SFML/Graphics.hpp>
//#include <fstream>

#include "state.h"
#include "engine.h"
#include "render.h"

#include "mapGeneration.h"
#include "CommandGeneration.h"

using namespace std ;
using namespace state ;
using namespace render ;
using namespace engine ;

// #define RDMAPGENITER 480
#define WIDTH	12
#define HEIGHT	12
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16+64

using namespace mapGeneration ;
using namespace CommandGeneration ;

void testEngine(){
    int tick=0;

    State state(WIDTH, HEIGHT);
    generateTestMap(state);
    generateTestUnits(state);

    Engine eng(state);
    eng.debug();

    //eng.setCurrentState(newState);

// CLIENT ONLY
    Render render(state) ;
    render.update();
//------------

    generateCommand(eng);
    
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
