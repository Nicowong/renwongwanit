#include "CommandService.hpp"

using namespace server;

CommandService::CommandService(){
	ticks.resize(2);
	ticks[0] = 0 ;
	ticks[1] = 0 ;
}

HttpStatus CommandService::get (Json::Value& out, int id) const{
	out = coms[ticks[id]] ;
	ticks[id]++ ;
	return HttpStatus::OK ;
}

HttpStatus CommandService::put (Json::Value& out, const Json::Value& in){
	coms.push_back(in);
	return HttpStatus::OK ;
}
