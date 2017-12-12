#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
//#include <fstream>

#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

#include "rules.h"

#include "mapGeneration.h"

#define WIDTH 10
#define HEIGHT 10
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16+64

using namespace std ;
using namespace render ;
using namespace engine ;
using namespace ai ;

using namespace mapGeneration;

void testHeuristic_ai(){/*
	srand(time(NULL));

	State state(WIDTH, HEIGHT);
	generateMap(state);
	generateUnits(state);

	Render render(state);

	Engine engine(state);

	Unit* u = nullptr ;
	size_t i=0, j=0 ;
	ElementTab& utab = state.getUnitTab();
	while(u==nullptr && i<WIDTH && j<HEIGHT){
		u = (Unit*)utab.getElem(i,j);
		i++;
		if(i>=WIDTH){
			i=0 ; j++ ;
		}
	}

	RandomAi ai(state);
	std::vector<Command*> coms;
	ai.listCommands(coms, *u);

	sf::RenderWindow window(sf::VideoMode(WINWIDTH, WINHEIGHT), "test Heuristic_ai | run com");
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
        
        render.update();
        render.draw(window);
        
        window.display();
    }*/
}