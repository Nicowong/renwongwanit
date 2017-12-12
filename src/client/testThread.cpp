#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <SFML/Graphics.hpp>
//#include <fstream>

#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

#include "mapGeneration.h"

#define WIDTH 16
#define HEIGHT 12
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16+64
#define RDMAPGENITER 6000

using namespace std ;
using namespace state ;
using namespace render ;
using namespace engine ;
using namespace ai ;

using namespace mapGeneration;

void engineHandler(Engine *engine);

void testThread(){
	srand(time(NULL));
	State state(WIDTH, HEIGHT);

	generateMap(state);
	generateUnits(state);

    Engine engine(state);

	Render render(state);
	render.update();

    thread thEngine(engineHandler, &engine);

	sf::RenderWindow window(sf::VideoMode(WINWIDTH, WINHEIGHT), "testThread");
    while(window.isOpen()){
        //check event
        sf::Event event ;
        while(window.pollEvent(event)){
//---POLLEVENT LOOP
            switch(event.type){
                case sf::Event::Closed :    //close request
                    window.close();
                    break;
                default :
                    break;
            }
//---END POLLEVENT LOOP
        }
        
        window.clear();
        
        render.draw(window);
        
        window.display();
    }

    thEngine.join();

}

void engineHandler(Engine* engine){
    cout << "Engine Handler is running" << endl ;
}
