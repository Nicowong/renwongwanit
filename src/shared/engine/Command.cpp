/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Command.h"

using namespace state;
using namespace engine;

CommandTypeId Command::getTypeId() const{
    return commandTypeId;
}

void Command::execute(state::State& state){
    
}