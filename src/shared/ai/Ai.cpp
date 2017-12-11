#include <iostream>

#include "Ai.h"
#include "rules.h"

#include "engine/commands.h"

using namespace std;
using namespace state;
using namespace engine;
using namespace ai;

extern const int moveRangeRule[22];
extern const int dmgRule[22*22];
extern const int maxRangeRule[22];
extern const int minRangeRule[22];

Ai::Ai(State& state): state(state){
}

void dijkstraRec(vector<Command*>& list, Unit& u, ElementTab& ctab, ElementTab& utab, int movrg, int x, int y, vector<bool>& check){
	size_t w=ctab.getW() ;//, h=ctab.getH();
	if(check[x+y*w]==false){
		check[x+y*w] = true ;
		Unit *u2 = (Unit*)utab.getElem(x, y);
		if(u2==nullptr && movrg>=0){
			Command* com = new MoveCommand(u, x, y);
			list.push_back(com);
			dijkstraRec(list,u,ctab,utab,movrg-1,x+1,y,check);
			dijkstraRec(list,u,ctab,utab,movrg-1,x-1,y,check);
			dijkstraRec(list,u,ctab,utab,movrg-1,x,y+1,check);
			dijkstraRec(list,u,ctab,utab,movrg-1,x,y-1,check);
		}
		else if(u2!=nullptr && u2->getTeam()==u.getTeam() && movrg>=0){
			dijkstraRec(list,u,ctab,utab,movrg-1,x+1,y,check);
			dijkstraRec(list,u,ctab,utab,movrg-1,x-1,y,check);
			dijkstraRec(list,u,ctab,utab,movrg-1,x,y+1,check);
			dijkstraRec(list,u,ctab,utab,movrg-1,x,y-1,check);
		}
		else if(u2!=nullptr && u.getAmmo()>0 && !(u.isRanged()) && u2->getTeam()!=u.getTeam() &&
		 		dmgRule[u.getUnitType()*22+u2->getUnitType()]>0){

			Command* com = new AttackCommand(u, *u2);
			list.push_back(com);
		}
	}
}
void Ai::listCommands(std::vector<engine::Command*>& list, state::Element& sel){
	sel.debug();

    ElementTab& ctab = state.getCellTab();
    ElementTab& utab = state.getUnitTab();

    if(sel.getType()==T_UNIT){
    	Unit& u = (Unit&)sel ;
    	int movrg = min(moveRangeRule[u.getUnitType()], u.getFuel());
    	vector<bool> check ;
    	check.resize(ctab.length(), false);

    	dijkstraRec(list, u, ctab, utab, movrg, u.getX(), u.getY(), check);
    	cout << "dijkstraRec end" << endl ;
    	if(u.isRanged() && u.getAmmo()>0){
    		int x=(int)u.getX(), y=(int)u.getY(), w=(int)ctab.getW(), h=(int)ctab.getH();
    		int rg=maxRangeRule[u.getUnitType()];
    		int imin=max(0, x-rg), jmin=max(0,y-rg);
    		int imax=min(w-1, x+rg), jmax=min(h-1, y+rg);
    		for(int j=jmin ; j<jmax ; j++)
    			for(int i=imin ; i<imax ; i++){
	    			int d = abs(i-x)+abs(j-y) ;
	    			if(d>=minRangeRule[u.getUnitType()] && d <= rg){
    					Unit *u2 = (Unit*)utab.getElem((size_t)i,(size_t)j);
	    				if(u2 != nullptr && u2->getTeam()!=u.getTeam()){
	    					Command* com = new AttackCommand(u, *u2);
		    				list.push_back(com);
		    			}
		    		}
    			}
    	}
    }

    for(size_t t=0 ; t<list.size() ; t++)
    	list[t]->debug();
}
