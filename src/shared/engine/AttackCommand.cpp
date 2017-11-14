#include "AttackCommand.h"
#include "state/ElementTab.h"

using namespace state;
using namespace engine;

void AttackCommand::attackCommand(int elementID, int targetID){
    state::ElementTab elemTab;
    elemTab.getElem(elementID);
    state::ElementTab targetTab;
    targetTab.getElem(targetID);
    
    
    
}

int AttackCommand::getElementID() const{
    return elementID;
}

void AttackCommand::setElementID(int elementID){
    this->elementID=elementID;
}

CommandTypeId AttackCommand::getCommandTypeId() const{
    return COM_ATTACK;
}

void engine::AttackCommand::setCommandTypeId(engine::CommandTypeId commandTypeId){
    this->commandTypeId=engine::commandTypeId;
}

void AttackCommand::execute(state::State& state){
    
}