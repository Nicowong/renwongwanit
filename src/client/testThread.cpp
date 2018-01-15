#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <ctime>
//#include <fstream>

#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

#include "mapGeneration.h"
#include "CommandGeneration.h"

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
using namespace CommandGeneration ;

void testThread(){
	srand(time(NULL));
	State state(WIDTH, HEIGHT);

	generateTestMap(state);
	generateTestUnits(state);

    Engine engine(state);
    generateCommand(engine);

	Render render(state);
	render.update();

    time_t prvt, now ;

	sf::RenderWindow window(sf::VideoMode(WINWIDTH, WINHEIGHT), "testThread");

    time(&prvt);
    time(&now);

    thread thEng(&Engine::run, std::ref(engine));
    engine.setStatus(RUN);
    
    render.update();
    window.clear();
    render.draw(window);
    window.display();

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

        time(&now);
        if(difftime(now, prvt) > 1.0/60.0){
            
            render.update();
            window.clear();
            render.draw(window);
            window.display();
            time(&prvt);
            
        }
    }

    engine.setStatus(QUIT);
    thEng.join();
}
