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
    
    Unit& u1 = *(Unit*)(&selected);
        
    // chercher les elements autours d'element choisit
    
    for( size_t i=x-2; i<x+2;i++){
        for(size_t j=y-2; j<y+2;j++){
            target= search->getElem(i,j);
        }
    }
    
    //soit il n'y pas ennemie autours d'element choisit, on fait MoveCommand
    if(!target){
        cmd = new MoveCommand(u1,2,2);
        engine.addCommand(cmd);
    }
    //soit il trouve un ennemie, il l'attacque.
    else if(target->isUnit()){
        Unit& u=*(Unit*)(&target);
        cmd = new AttackCommand(u1,u);
        engine.addCommand(cmd);
        
    }else if(target->isBuilding()){
        Building& b=*(Building*)(&target);  
        cmd = new CaptureCommand(b,u1);
        engine.addCommand(cmd);
    }
}

