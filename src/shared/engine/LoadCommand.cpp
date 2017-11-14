#include <iostream>

#include "LoadCommand.h"

using namespace std ;
using namespace engine ;

CommandTypeId LoadCommand::getCommandTypeId() const{
    return COM_LOAD ;
}
