#include <iostream>

#include "RepairCommand.h"

using namespace std ;
using namespace engine ;

CommandTypeId RepairCommand::getCommandTypeId() const{
    return COM_REPAIR ;
}
