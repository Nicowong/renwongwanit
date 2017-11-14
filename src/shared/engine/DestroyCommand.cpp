#include <iostream>

#include "DestroyCommand.h"

using namespace std ;
using namespace engine ;

CommandTypeId DestroyCommand::getCommandTypeId() const{
    return COM_DESTROY ;
}
