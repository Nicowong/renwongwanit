#include "HeuristicAI.h"
#include "engine/MoveCommand.h"
#include "engine/AttackCommand.h"
#include "engine/CaptureCommand.h"
#include "engine/DestroyCommand.h"
#include "engine/SupplyCommand.h"
#include "engine/RepairCommand.h"


using namespace ai;
using namespace engine;
using namespace state;
using namespace std;


const PathMap HeuristicAI::getCellMap() const{
    return cellMap;
}

const PathMap HeuristicAI::getUnitMap() const{
    return unitMap;
}

void HeuristicAI::setCellMap(const PathMap& cellMap){
    this->cellMap=cellMap;
}

void HeuristicAI::setUnitMap(const PathMap& unitMap){
    this->unitMap=unitMap;
}

void HeuristicAI::run(Engine& engine, Element& selected)
{
    
    Element* target;
    Command* cmd = nullptr;
    
    std::vector<int> distancetab;
    std::vector<Position> positiontab;
    
    distancetab = PathMap.getDistaceTab();
    positiontab = PathMap.getDistaceTab();
    
    int min_i,min_v=distancetab[1];
    for(size_t i=0;i<sizeof(distancetab);i++){
        if(distancetab[i]<min_v){
            min_i=i;
            min_v=distancetab[i];
        }
    }
    
    target= ElementTab.getElem(positiontab[min_i].getX(),positiontab[min_i].getY());
   
    Unit& caractor = *(Unit*)(&selected);
        

    
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