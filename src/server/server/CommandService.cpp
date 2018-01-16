#include "CommandService.hpp"

using namespace std ;
using namespace server;

CommandService::CommandService(): AbstractService("/command"){
	ticks.resize(2);
	ticks[0] = 0 ;
	ticks[1] = 0 ;
}

HttpStatus CommandService::get (Json::Value& out, int id){
	if(id < 0){
		out["ticks"][0] = ticks[0];
		out["ticks"][1] = ticks[1];
		for(int i = 0 ; i < (int)coms.size() ; i++)
			out["ticks"][i] = coms[i];
	}
	if(ticks[id] >= (int)coms.size()){
		out["CommandTypeId"] = -1 ;
		throw ServiceException(HttpStatus::BAD_REQUEST, "coms.size()="+to_string(coms.size())+" ticks[id]="+to_string(ticks[id]));
	}
	out = coms[ticks[id]] ;
	ticks[id]++ ;
	return HttpStatus::OK ;
}

HttpStatus CommandService::put (Json::Value& out, const Json::Value& in){
	coms.push_back(in);
	return HttpStatus::OK ;
}
