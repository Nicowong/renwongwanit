#include <iostream>
#include <cstdlib>
//#include <fstream>

#include "state.h"
#include "engine.h"
#include "ai.h"

#include "rules.h"

#include "mapGeneration.h"

#define WIDTH 10
#define HEIGHT 10 

using namespace std ;
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
    
    ElementTab& Utab = newState.getUnitTab();
    
    RandomAi ai(newState);
    

    int x=0, y=0 ;
    Unit* u = nullptr ;
  
    do{
	string a;
	cin >> a ;
	cout << "<<< tick : "<< tick << " >>>"<< endl ;
	tick++;

        cout << "finding an unit to move"<<endl ;
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
            u->setMoved(true);
	    u->debug();
	    Element& selected = *(Element*) u;
	    ai.run(eng,selected);
	    
	    eng.debug();
	    newState.turnIncr();
	    
	    cout << "<<< tick : "<< tick << " >>>"<< endl ;
    }while(!eng.getCurrentCommands().size());
}
