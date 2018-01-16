#include "CommandService.hpp"

using namespace std ;
using namespace server;

CommandService::CommandService(): AbstractService("/command"){
	coms.resize(0);
}

HttpStatus CommandService::get(Json::Value& out, int id)const{
	if(id < 0){
		//cout << "getCommand with id<0" << endl ;
		for(size_t i = 0 ; i < coms.size() ; i++){
			//cout << "i:" << i << "coms.size():" << coms.size() << endl ;
			out[i] = coms[i];
		}
		return HttpStatus::OK ;
	}else if(id >= (int)(coms.size()) ){
		out["CommandTypeId"] = -1 ;
		throw ServiceException(HttpStatus::BAD_REQUEST, "BAD REQUEST : coms.size()="+to_string(coms.size())+" id="+to_string(id));
	}else{
		out = coms[id] ;
		return HttpStatus::OK ;
	}
}

HttpStatus CommandService::put (Json::Value& out, const Json::Value& in){
	coms.push_back(in);
	out["id"] = coms.size()-1 ;
	out["com"] = in ;
	//cout << "CommandService::put" <<endl ;
	return HttpStatus::OK ;
}
