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

HttpStatus PlayerService::post(const Json::Value& in, int id){
    /*const Player* player = &(game.player(id));
    if(!player)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
    unique_ptr<Player> playermod (new Player(*player));
    if (in.isMember("name")){
        playermod->name =  in["name"].asString();
    }
    game.setPlayers(std::move(playermod),id);*/
    return HttpStatus::NO_CONTENT;
}

HttpStatus PlayerService::put(Json::Value& out, const Json::Value& in){
    string name = in["name"].asString();
    out["id"] = game.addPlayer(make_unique<Player>(name));
    return HttpStatus::CREATED;
}

HttpStatus PlayerService::remove(int id){
    /*
    const Player* player = game.getPlayers(id);
    if(!player)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid player id");
    game;
    */
    return HttpStatus::NO_CONTENT;
}
