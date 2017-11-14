#include <iostream>

#include "MoveCommand.h"

using namespace std ;
using namespace engine ;

CommandTypeId MoveCommand::getCommandTypeId() const{
    return COM_MOVE ;
}
