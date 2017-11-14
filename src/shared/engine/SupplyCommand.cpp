#include <iostream>

#include "SupplyCommand.h"

using namespace std ;
using namespace engine ;

CommandTypeId SupplyCommand::getCommandTypeId() const{
    return COM_SUPPLY;
}
