/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "SelectCommand.h"

using namespace std ;
using namespace state;
using namespace engine;

SelectCommand::SelectCommand(int elementID){
    state::ElementTab elemtab;
    elemtab.getElem(elementID);
    std::cout<<elemtab.getElem(elementID)<<" has been chosen"<<std::endl;
}

int SelectCommand::getElementID() const{
    return elementID;
}

void SelectCommand::setElementID(int elementID){
    this->elementID=elementID;
}

void SelectCommand::execute(state::State& state){
    
}

engine::CommandTypeId engine::SelectCommand::getCommandTypeId() const{
    return engine::commandTypeId;
}

void engine::SelectCommand::setCommandTypeId(engine::CommandTypeId commandTypeId){
    this->commandTypeId=engine::commandTypeId;
}