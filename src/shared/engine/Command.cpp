/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Command.h"

using namespace std ;
using namespace state;
using namespace engine;

Command::~Command(){
	
}

CommandTypeId Command::getCommandTypeId() const{
    return COM_NONE ;
}


void Command::execute(state::State& state){
    if(this->getCommandTypeId() != COM_NONE)
    	this->execute(state);
    else
    	cout<< "error : Command::execute()";
}