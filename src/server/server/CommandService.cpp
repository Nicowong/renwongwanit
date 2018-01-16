#include "CommandService.hpp"

using namespace engine;
using namespace server;

CommandService::CommandService(Engine& engine): AbstractService("/command"),engine(engine){

}

Engine& CommandService::getEngine(){
    return engine;
}

HttpStatus CommandService::get(Json::Value& out, int id) const{
    if(id > 0 ){
	for(int i=0; i < (int) engine.getCurrentCommands().size(); i++){
	    out[i] = engine.getCurrentCommands()[i];
	}
	return HttpStatus::OK;    
    }
    else {
	throw ServiceException(HttpStatus::NOT_FOUND,"Invalid command id"); 
    }
}

HttpStatus CommandService::put(Json::Value& out, const Json::Value& in)
{
    return server::AbstractService::put(out, in);
}

