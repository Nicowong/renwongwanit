#include "CommandeService.h"
#include <string>

using namespace engine;
using namespace server;
using namespace std;

CommandeService::CommandeService(Engine& engine): AbstractService("/commande")
{

}

HttpStatus CommandeService::get(Json::Value& out, int id) const
{
    
    return server::AbstractService::get(out, id);
}


HttpStatus CommandeService::put(Json::Value& out, const Json::Value& in) const
{

}


