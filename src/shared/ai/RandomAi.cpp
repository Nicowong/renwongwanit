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
    ElementTab& unitTab = state.getUnitTab();
    Command* cmd = nullptr;
    size_t x;
    size_t y;
    x = selected.getX();
    y = selected.getY();
    
    cmd = new SelectCommand(selected);
    engine.addCommand(cmd);
    engine.update();
    
    for (size_t i=x-2;i<x+2;i++){
      for (size_t j = y-2;j<y+2;j++){
	  target=unitTab.getElem(i,j);
      }
    }
    Unit& caractor = *(Unit*)(&selected);
    Unit& unitTarget = *(Unit*)(target);
    Building& buildTarget = *(Building*)(target);
     
    if(!target){
        cmd = new MoveCommand(caractor,2,0);
        engine.addCommand(cmd);
	engine.update();
    }
    
    else if(target->isUnit()){
       
            if(unitTarget.getTeam()!=caractor.getTeam()){
                cmd = new AttackCommand(caractor,unitTarget);
                engine.addCommand(cmd);
                engine.update();
                if(unitTarget.getHealth() <= 0){
                    cmd = new DestroyCommand(unitTarget);
                    engine.update();
                    }   
                }
            if(unitTarget.getTeam()==caractor.getTeam()){
                if(unitTarget.getHealth()<30){
                    cmd = new RepairCommand(unitTarget);
                    engine.addCommand(cmd);
                    engine.update();
                }
            else if(unitTarget.getUnitType()){
                cmd = new SupplyCommand(unitTarget);
                engine.addCommand(cmd);
		engine.update();
            }
        }
        else {
            if(buildTarget.getTeam()!=caractor.getTeam()){
                cmd = new CaptureCommand(buildTarget,caractor);
                engine.addCommand(cmd);
                engine.update();
            } 
            else{
                cmd = new MoveCommand(caractor,2,0);
                engine.addCommand(cmd);
                engine.update();
            }
        }
            
        
    }
}

