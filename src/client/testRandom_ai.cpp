#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
//#include <fstream>

#include "../shared/state.h"
#include "render.h"
#include "../shared/ai/Ai.h"
#include "../shared/engine.h"
#include "../shared/ai.h"

#include "../shared/rules.h"

#include "../shared/mapGeneration.h"

#define WIDTH 10
#define HEIGHT 10
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16+64

using namespace std ;
using namespace render ;
using namespace engine ;
using namespace ai ;

using namespace mapGeneration;

void testRandom_ai(){
    srand(time(NULL));
    int tick=0;

    State newState(WIDTH, HEIGHT);
    generateMap(newState);
    Engine eng(newState);
    generateUnits(newState);
    Render render(newState) ;
    render.update();
    
    ElementTab& Utab = newState.getUnitTab();

    RandomAi ai(newState);
    
    for(size_t j=0 ; j<HEIGHT ; j++){
	for(size_t i=0 ; i<WIDTH ; i++){
	    Unit* u = (Unit*)Utab.getElem(i,j);
	    if(u != nullptr){
		u->setMoved(false);
		u->setAvailable(true);
	    }
	}
    }
    
    int x=0, y=0 ;
    Unit* u = nullptr ;
    Element& selected = *(Element*) u;
    
    sf::RenderWindow window(sf::VideoMode(WINWIDTH, WINHEIGHT), "My window - test sprite");
    while(window.isOpen()){
        //check event
        sf::Event event ;
        while(window.pollEvent(event)){
            
            switch(event.type){
                case sf::Event::Closed :    //close request
                    window.close();
                    break;
                case sf::Event::KeyPressed :
			cout << "<<< tick : "<< tick << " >>>"<< endl ;
			tick++;

		    //select an unit 
			cout << "choosing an unit"<<endl ;
			x=rand()%WIDTH ;
			y=rand()%HEIGHT ;
			u = (Unit*) Utab.getElem(x, y);
			while(u==nullptr || u->getTeam()!=newState.getTurn()){
			    x++ ;
			    if(x==WIDTH){
				x = 0 ;
                    		y++;
			    }
			    if(y==HEIGHT)
				y=0;
			    u = (Unit*) Utab.getElem(x, y);
			  
			    
			}
			cout <<"chosed :";
			u->debug();
			cout<<endl;
                        cout <<"------------------------------------"<<endl;
			selected = *(Element*) u;
			ai.run(eng,selected);
                   

			eng.debug();
			render.update();

			newState.turnIncr();

			cout << "<<< tick : "<< tick << " >>>"<< endl ;
			break ;

                default :
			break;
            }
        }
        
        window.clear(sf::Color::Black);
        
        render.draw(window);
        
        window.display();
    }
}
