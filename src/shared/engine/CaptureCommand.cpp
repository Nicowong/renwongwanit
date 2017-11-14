#include <iostream>

#include "CaptureCommand.h"

using namespace std ;
using namespace engine ;

CommandTypeId CaptureCommand::getCommandTypeId() const{
    return COM_CAPTURE;
}
