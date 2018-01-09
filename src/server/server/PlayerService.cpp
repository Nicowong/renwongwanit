#include "PlayerService.hpp"

using namespace server;

PlayerService::PlayerService(Game& game): AbstractService("/player"),
        game(game){
}
HttpStatus PlayerService::get(Json::Value& out, int id) const{
    if(id<0){
        for(size_t i=0 ; i<game.getPlayers().size() ; i++)
            out[i]["name"] = game.player(i).name ;
        return HttpStatus::OK ;
    }else{
        try{
            out["name"] =  game.player(id).name ;
            return HttpStatus::OK;
        }catch(...){
            throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
        }
    }
}

HttpStatus PlayerService::put(Json::Value& out, const Json::Value& in){
    string name = in["name"].asString();
    out["id"] = game.addPlayer(make_unique<Player>(name));
    return HttpStatus::CREATED;
}

HttpStatus PlayerService::remove(int id){
    game.removePlayer(id);
    return HttpStatus::NO_CONTENT;
}

HttpStatus PlayerService::post(const Json::Value& in, int id){
    string name = in["name"].asString();
    game.setPlayer(make_unique<Player>(name), id);
    return HttpStatus::NO_CONTENT;
}
