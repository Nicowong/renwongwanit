/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ChooseElementCommand.h"
#include <iostream>
using namespace state;
using namespace engine;

void ChooseElementCommand::chooseElementCommand(int elementID){
    state::ElementTab elemtab;
    elemtab.getElem(elementID);
    std::cout<<elemtab.getElem(elementID)<<" has been chosen"<<std::endl;
}

int ChooseElementCommand::getElementID() const{
    return elementID;
}

void ChooseElementCommand::setElementID(int elementID){
    this->elementID=elementID;
}

void ChooseElementCommand::execute(state::State& state){
    
}

engine::CommandTypeId engine::ChooseElementCommand::getCommandTypeId() const{
    return engine::commandTypeId;
}

void engine::ChooseElementCommand::setCommandTypeId(engine::CommandTypeId commandTypeId){
    this->commandTypeId=engine::commandTypeId;
}