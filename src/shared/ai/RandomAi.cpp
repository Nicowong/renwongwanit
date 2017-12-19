#include "RandomAi.h"  
#include <iostream>
#include <stdlib.h>
#include <string>

#include "engine/MoveCommand.h"
#include "engine/AttackCommand.h"
#include "engine/CaptureCommand.h"
#include "engine/DestroyCommand.h"
#include "engine/SupplyCommand.h"
#include "engine/RepairCommand.h"
#include "engine/SelectCommand.h"

using namespace engine;
using namespace state;
using namespace ai;
using namespace std;

#define WIDTH 10
#define HEIGHT 10
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16+64


RandomAi::RandomAi(state::State& state):Ai(state){

}

void RandomAi::run(Engine& engine, Element& selected)
{
    Element* target = nullptr;
    ElementTab uTab = engine.getCurrentState().getUnitTab();
    ElementTab* unittab = &uTab;
    Command* cmd = nullptr;
    
    cmd = new SelectCommand(selected);
    engine.addCommand(cmd);
    engine.update();
    
    Unit& caractor = *(Unit*)(&selected);
    
    size_t x = selected.getX();
    size_t y = selected.getY();
    
    for (size_t i=x-2;i<x+2;i++){
      for (size_t j = y-2;j<y+2;j++){
	  target=unittab->getElem(i,j);
      }
    }
    if(target ==nullptr ){
	int dx = rand() % 5 - 2 ;
	int dy = rand() % 5 - 2 ;
	while(x+dx<0 || x+dx >= WIDTH || y+dy < 0 || y+dy>= HEIGHT){
	    
	    dx = rand() % 5 - 2 ;
	    dy = rand() % 5 - 2 ;
	}
	
	std::cout << dx << " " <<dy<<std::endl;
	cmd = new MoveCommand(caractor,x+dx,y+dy);
	engine.addCommand(cmd);
	engine.update();
    }
    
    else{
        Unit& tunit=*(Unit*)(target);
        
        if(tunit.getTeam()!=caractor.getTeam()){
            cmd = new AttackCommand(caractor,tunit);
            engine.addCommand(cmd);
	    engine.update();
            if(tunit.getHealth() <= 0){
                cmd = new DestroyCommand(tunit);
		engine.update();
            }   
        }
        if(tunit.getTeam()==caractor.getTeam()){
            if(tunit.getHealth()<30){
                cmd = new RepairCommand(tunit);
                engine.addCommand(cmd);
		engine.update();
            }
            else if(tunit.getUnitType()){
                cmd = new SupplyCommand(tunit);
                engine.addCommand(cmd);
		engine.update();
            }
        }  
    }
}

