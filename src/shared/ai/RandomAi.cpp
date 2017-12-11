#include "RandomAi.h"  
#include "engine/MoveCommand.h"
#include "engine/AttackCommand.h"
#include "engine/CaptureCommand.h"
#include "engine/DestroyCommand.h"
#include "engine/SupplyCommand.h"
#include "engine/RepairCommand.h"

using namespace engine;
using namespace state;
using namespace ai;

RandomAi::RandomAi(state::State& state):Ai(state){

}

void RandomAi::run(Engine& engine, Element& selected)
{
    Element* target;
    ElementTab* search;
    Command* cmd = nullptr;
    size_t x;
    size_t y;
    x = selected.getX();
    y = selected.getY();
    
    Unit& caractor = *(Unit*)(&selected);
        
    for( size_t i=x-2; i<x+2;i++){
        for(size_t j=y-2; j<y+2;j++){
            target= search->getElem(i,j);
        }
    }
    
    if(!target){
        cmd = new MoveCommand(caractor,2,2);
        engine.addCommand(cmd);
    }
    
    else if(target->isUnit()){
        Unit& unit=*(Unit*)(target);
        
        if(unit.getTeam()!=caractor.getTeam()){
            cmd = new AttackCommand(caractor,unit);
            engine.addCommand(cmd);
            if(unit.getHealth() <= 0){
                cmd = new DestroyCommand(unit);
            }   
        }
        if(unit.getTeam()==caractor.getTeam()){
            if(unit.getHealth()<30){
                cmd = new RepairCommand(unit);
                engine.addCommand(cmd);
            }
            else if(unit.getUnitType()){
                cmd = new SupplyCommand(unit);
                engine.addCommand(cmd);
            }
        }
            
        
    }
    
    else if(target->isBuilding()){
        Building& building = *(Building*)(target);  
        cmd = new CaptureCommand(building,caractor);
        engine.addCommand(cmd);
    }
}

