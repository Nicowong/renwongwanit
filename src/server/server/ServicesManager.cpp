/** 
 * @file ServicesManager.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "ServicesManager.hpp"

using namespace std;

void ServicesManager::registerService (unique_ptr<AbstractService> service) {
    services.push_back(move(service));
}

AbstractService* ServicesManager::findService (const string& url) const {
    for(size_t id=0 ; id<services.size() ; id++)
        if(services[id]->getPattern()==url)
            return services[id].get();
    throw ServiceException(HttpStatus::NOT_FOUND, "ServiceManager::findService : Service not found : "+url);
}

HttpStatus ServicesManager::queryService (string& out, const string& in, const string& url, const string& method) { 
    try{
        // /version/1/
        string tmp = url.substr(1); // = version/1/
        size_t pos = tmp.find("/");
        string sUrl ;
        int id = 0 ;
        if(pos == string::npos) sUrl = url ;
        else{
            sUrl = url.substr(0,pos+1); // = /version
            tmp = tmp.substr(pos+1);    // = 1/
            if(!tmp.empty()){
                pos = tmp.find("/");
                if(pos == string::npos) id = stoi(tmp);
                else id = stoi(tmp.substr(0,pos));
            }
        }
        AbstractService* service = findService(sUrl);
        if(method=="GET"){
            Json::Value val ;
            HttpStatus status = service->get(val, id);
            out = val.toStyledString();
            return status ;
        }
        if(method=="POST"){
            Json::Reader reader ;
            Json::Value val ;
            if(!reader.parse(in, val))
                throw ServiceException(HttpStatus::BAD_REQUEST, "Bad Json Format.");
            HttpStatus status = service->post(val, id);
            return status ;
        }
        if(method=="PUT"){
            Json::Reader reader ;
            Json::Value val ;
            if(!reader.parse(in, val))
                throw ServiceException(HttpStatus::BAD_REQUEST, "Bad Json Format.");
            HttpStatus status = service->put(valOut, valIn);
            out = valOut.toStyledString();
            return status ;
        }
        if(method=="REMOVE"){
            HttpStatus status = service->remove(id);
            return status ;
        }
        throw ServiceException(HttpStatus::BAD_REQUEST, "method="+method);
    }catch(ServiceException e){
        throw ;
    }
}


