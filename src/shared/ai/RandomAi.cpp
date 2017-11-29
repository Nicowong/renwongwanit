#include "RandomAi.h"  
#include "engine/MoveCommand.h"
#include "engine/AttackCommand.h"
#include "engine/CaptureCommand.h"

using namespace engine;
using namespace state;
using namespace ai;

RandomAi::RandomAi()
{
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
        
    // chercher les elements autours d'element choisit
    
    for( size_t i=x-2; i<x+2;i++){
        for(size_t j=y-2; j<y+2;j++){
            target= search->getElem(i,j);
        }
    }
    
    //soit il n'y pas ennemie autours d'element choisit, on fait MoveCommand
    if(!target){
        cmd = new MoveCommand(caractor,2,2);
        engine.addCommand(cmd);
    }
    //soit il trouve un ennemie, il l'attacque.
    else if(target->isUnit()){
        Unit& unit=*(Unit*)(target);
        cmd = new AttackCommand(caractor,unit);
        engine.addCommand(cmd);
        
    }else if(target->isBuilding()){
        Building& building = *(Building*)(target);  
        cmd = new CaptureCommand(building,caractor);
        engine.addCommand(cmd);
    }
}

