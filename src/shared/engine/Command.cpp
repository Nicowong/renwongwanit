/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "json/json.h"
#include "json/json-forwards.h"

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

void Command::debug()const{
	cout << "Command::debug()" << endl ;
}

Json::Value Command::toJson()const{
	Json::Value data ;
	return data ;
}
