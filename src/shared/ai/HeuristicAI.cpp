#include "HeuristicAI.h"
#include "engine/MoveCommand.h"
#include "engine/AttackCommand.h"
#include "engine/CaptureCommand.h"
#include "engine/DestroyCommand.h"
#include "engine/SupplyCommand.h"
#include "engine/RepairCommand.h"
#include "engine/SelectCommand.h"


using namespace ai;
using namespace engine;
using namespace state;
using namespace std;




void HeuristicAI::run(Engine& engine, Element& selected)
{
    Command* cmd = nullptr;
    
    cmd = new SelectCommand(selected);
    engine.addCommand(cmd);
    engine.update();
    
    std::vector<int> unitdistancetab= unitMap.getDistancetab();
    std::vector<Position> unitpositiontab= unitMap.getPositiontab();
    std::vector<int> buildingdistancetab= cellMap.getDistancetab();
    std::vector<Position> buildingpositiontab= cellMap.getPositiontab();
   
    ElementTab unitTab =  engine.getCurrentState().getUnitTab();
    ElementTab buildingTab = engine.getCurrentState().getCellTab();
    
    // chercher l'unit le plus proche que l'element original
    int min_ui=0,min_uv=unitdistancetab[1];
    for(size_t i=0;i<sizeof(unitdistancetab);i++){
        if(unitdistancetab[i]<min_uv){
            min_ui=i;
            min_uv=unitdistancetab[i];
        }
    }
    
    //chercher le batiment le plue proche que l'element original
    int min_bi=0,min_bv=buildingdistancetab[1];
    for(size_t i=0;i<sizeof(buildingdistancetab);i++){
        if(buildingdistancetab[i]<min_bv){
            min_bi=i;
            min_bv=unitdistancetab[i];
        }
    }
    
    ElementTab* uTab = &unitTab;
    ElementTab* bTab = &buildingTab;
    
    Element* uTarget= uTab->getElem(unitpositiontab[min_ui].getX(),
                                        unitpositiontab[min_ui].getY());
    Element* bTarget= bTab->getElem(buildingpositiontab[min_bi].getX(),
                                        buildingpositiontab[min_bi].getY());
    
    
    Unit& unitTarget= *(Unit*)(uTarget);
    Building& buildingTarget = *(Building*)(bTarget);
    Unit& unitSelected = *(Unit*)(&selected);   
    
    if(min_uv > unitSelected.getVision()||min_bv>unitSelected.getVision()){
        if(unitSelected.getHealth()>30){
            cmd = new MoveCommand(unitSelected,2,2);
            engine.addCommand(cmd);
        }
        else{
            cmd = new RepairCommand(unitSelected);
        }
    }
    else if(min_uv < min_bv){
        if(unitSelected.getTeam()!=unitTarget.getTeam()){
            cmd = new AttackCommand(unitSelected,unitTarget);
            engine.addCommand(cmd);
            if(unitTarget.getHealth() <= 0){
                cmd = new DestroyCommand(unitTarget);
              engine.addCommand(cmd);
          }
      }
    }
    else{
        cmd = new CaptureCommand(buildingTarget,unitSelected);
        engine.addCommand(cmd);
    }

}

const PathMap& HeuristicAI::getCellMap() const{
    return cellMap;
}

const PathMap& HeuristicAI::getUnitMap() const{
    return unitMap;
}

void HeuristicAI::setCellMap(const PathMap& cellMap){
    this->cellMap=cellMap;
}

void HeuristicAI::setUnitMap(const PathMap& unitMap){
    this->unitMap=unitMap;
}