#include "RandomAi.h"  
#include <iostream>
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
    
     
    if(!target){
        
	if(caractor.getTeam() == 1){
	    cmd = new MoveCommand(caractor,x+2,y);
	    engine.addCommand(cmd);
	    engine.update();
	}
	else{
	    cmd = new MoveCommand(caractor,x-2,y);
	    engine.addCommand(cmd);
	    engine.update();
	  
	}
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

