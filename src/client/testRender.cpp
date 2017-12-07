#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "state.h"
#include "render.h"
#include "mapGeneration.h"

#define WIDTH 30
#define HEIGHT 20
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16
#define RDMAPGENITER 6000

using namespace std ;
using namespace state ;
using namespace render ;

using namespace mapGeneration ;

void testRender(int mode, string fname){
    srand(time(NULL));
    State state(WIDTH, HEIGHT);
    
    generateMap(state);
    generateUnits(state);

    //state.debug();

    Render render(state) ;

    cout << "render.update();" << endl ;

    render.update();

    cout << "<<Opening window>>" << endl ;

    sf::RenderWindow window(sf::VideoMode(WINWIDTH, WINHEIGHT), "My window - test sprite");
    while(window.isOpen()){
        //check event
        sf::Event event ;
        while(window.pollEvent(event)){
            
            switch(event.type){
                case sf::Event::Closed :    //close request
                    window.close();
                    break;
                default :
                    break;
            }
        }
        
        window.clear(sf::Color::Black);
        
        render.draw(window);
        
        window.display();
    }
}
