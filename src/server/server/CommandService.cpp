#include "CommandService.hpp"

using namespace engine;
using namespace server;
using namespace state;

CommandService::CommandService(Engine& engine): AbstractService("/command"),
        engine(engine),state(state){
}


Engine& CommandService::getEngine(){
    return engine;
}

HttpStatus CommandService::get(Json::Value& out, int id) const{
    if(id < 0 ){
	for(int i=0; i < (int) engine.getCurrentCommands().size(); i++){
	    out[i] = engine.getCurrentCommands()[i];
	}
	return HttpStatus::OK;    
    }else if(id >(int) engine.getCurrentCommands().size())
    {
        throw ServiceException(HttpStatus::BAD_REQUEST, "Not existed command");
    }
    else {
        out = engine.getCurrentCommands()[id];
	throw ServiceException(HttpStatus::NOT_FOUND,"Invalid command id"); 
    }
}

HttpStatus CommandService::put(Json::Value& out, const Json::Value& in)
{
    engine::Command* cmd = nullptr;
    /*switch(in["CommandTypeId"]){
        case COM_ATTACK:   
            cmd = new engine::AttackCommand((in["attId"]),(in["defId"]));
            break;
        case COM_LOAD:
            cmd = new engine::LoadCommand();
            break;
        case COM_SELECT:
            cmd = new engine::SelectCommand();
            break;
        case COM_MOVE:
            cmd = new engine::MoveCommand();
            break;
        case COM_CAPTURE:
            cmd = new engine::CaptureCommand();
            break;
        case COM_SUPPLY:
            cmd = new engine::SupplyCommand();
            break;
        case COM_REPAIR:
            cmd = new engine::ReCommand();
            break;
        case COM_DESTROY:
            cmd = new engine::DestroyCommand();
            break;
        case COM_ENDTURN:
            cmd = new engine::EndTurnCommand();
            break;
        case COM_CREATEUNIT:
            cmd = new engine::CreateUnitCommand();
            break;
        defaut : 
            throw ServiceException(HttpStatus::BAD_REQUEST, "Error command");
            break;
            
    }*/
    engine.addCommand(cmd);
    engine.update();
    out["id"] = engine.getCurrentCommands().size()-1;
    out["com"] = in;
    return HttpStatus::CREATED;
}

