#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "state.h"
#include "render.h"

#include "mapGeneration.h"

#ifndef __CLIENT__
#define __CLIENT__
#endif

#define WIDTH 30
#define HEIGHT 20
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16+64

using namespace std ;
using namespace state ;
using namespace render ;

using namespace mapGeneration;

void testRender(int mode, string fname){
    srand(time(NULL));
    State state(WIDTH, HEIGHT);
    
    generateMap(state);
    generateUnits(state);

    state.debug();

    ElementTab& etab = state.getUnitTab();

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
                case sf::Event::KeyReleased :
                    switch(event.key.code){
                        case sf::Keyboard::Space :
                            size_t x1, x2, y1, y2, z ;
                            z=0 ;
                            do{
                                x1=rand()%WIDTH ;
                                y1=rand()%HEIGHT ;
                                z++ ;
                            }while(etab.getElem(x1,y1)==nullptr && z<50);
                            z=0;
                            do{
                                x2=rand()%WIDTH ;
                                y2=rand()%HEIGHT ;
                                z++ ;
                            }while(etab.getElem(x2,y2)!=nullptr && z<50);

                            etab.moveElem(x1,y1,x2,y2);

                            render.update();
                            break;
                        default :
                            break;
                    }
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
