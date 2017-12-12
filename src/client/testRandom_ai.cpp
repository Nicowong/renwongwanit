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

 
    Unit& uRI   = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(1,0));
    Unit& uRR   = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(0,1));
    Unit& uRML  = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(0,4));
    Unit& uBT   = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(5,2));
    Unit& uBM   = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(4,3));
    Unit& uBMGT = *(Unit*)(eng.getCurrentState().getUnitTab().getElem(3,4));
    
    uRI.setTeam(PLAYER1);
    uRR.setTeam(PLAYER1);
    uRML.setTeam(PLAYER1);
    uBT.setTeam(PLAYER2);
    uBM.setTeam(PLAYER2);
    uBMGT.setTeam(PLAYER2);
    
    
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
    UnitType ut = UT_NONE ;
    Command* com = nullptr ;
    int mvRg = 0 ;
    int x2=0, y2=0 ;
    int dist = 0 ;
    
    Unit* u2 = nullptr ;
    int rgmin = 0, rgmax = 0 ;
    size_t ux = 0, uy = 0 ;
    size_t imin = 0, imax = 0 ;
    size_t jmin = 0, jmax = 0 ;
    size_t j=0, i=0 ;

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
                    cout << "moving unit "<< endl ;
                    ut = u->getUnitType();
                    mvRg = moveRangeRule[ut];
                    x2=x+rand()%(2*mvRg+1)-mvRg ;
                    y2=y+rand()%(2*mvRg+1)-mvRg ;
                    while(0>x2 || x2>=WIDTH || 0>y2 || y2>=HEIGHT || Utab.getElem(x2,y2)!=nullptr){
                    	x2=x+rand()%(2*mvRg+1)-mvRg ;
                    	y2=y+rand()%(2*mvRg+1)-mvRg ;
                    	cout << x2 << " ; " << y2 << endl ;
                    }

		    com = new MoveCommand(*u, x2, y2);
		    eng.addCommand(com);
		    eng.update();

		    cout << "checking attack possibilities"<<endl ;
		    dist = 0;
		    u2 = nullptr ;
		    rgmin = minRangeRule[ut] ;
		    rgmax = maxRangeRule[ut];
		    ux = u->getX();
		    uy = u->getY();
		    imin = max(0, (int)ux-rgmax);
		    imax = min(WIDTH-1, (int)ux+rgmax);
		    jmin = max(0, (int)uy-rgmax);
		    jmax = min(HEIGHT-1, (int)uy+rgmax);

		    j=jmin ;
		    i=imin ;
		    cout << "entering while" << endl;
		    while(j<=jmax && i<=imax && (u2==nullptr || u2->getTeam()==u->getTeam()) ){
			dist = abs((int)ux-(int)i) + abs((int)uy-(int)j);
			cout << i << " " << j << " " << dist << endl ;
			if(rgmin<=dist && dist<=rgmax){
			    cout << "getUnit()"<<endl ;
			    u2 = (Unit*)Utab.getElem(i, j);
			    }

			i++ ;
			if(i>imax){
			    i=imin ;
			    j++ ;
			}
		    }

		    if(u2!=nullptr){
			cout << "attacking unit" << endl ;
			Command* attack = new AttackCommand(*u, *u2);
			eng.addCommand(attack);
			eng.update();
		    }

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
