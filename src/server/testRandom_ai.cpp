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

    ElementTab& Utab = newState.getUnitTab();

    for(size_t j=0 ; j<HEIGHT ; j++)
    	for(size_t i=0 ; i<WIDTH ; i++){
    		Unit* u = (Unit*)Utab.getElem(i,j);
    		if(u != nullptr){
    			u->setMoved(false);
    			u->setAvailable(true);
    		}
    	}

    Engine eng(newState);
    generateUnits(newState);

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

                    newState.turnIncr();

                    cout << "<<< tick : "<< tick << " >>>"<< endl ;
    }while(!eng.getCurrentCommands().size());
}
