#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <thread>
#include <unistd.h>
#include <ctime>
#include <mutex>

#include "state.h"
#include "render.h"
#include "engine.h"

#include "network.hpp"

#include "mapGeneration.h"
#include "CommandGeneration.h"

#define WIDTH   12
#define HEIGHT  12
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16+64

using namespace std ;
using namespace state ;
using namespace render ;
using namespace engine ;

using namespace mapGeneration ;
using namespace CommandGeneration ;

enum ClientStatus{WAITING=0, INGAME=1, QUIT=2};
void queryGameStatus(sf::Http& http, ClientStatus& status, std::mutex& mtx);
void playGame(sf::Http& http, int id);

// MAIN FUNCTION

void network(const string& name, int port){
    // Setting host
    sf::Http http;
    string url("http://localhost");
    cout << "host : " << url << ":" << port << endl << endl ;
    http.setHost(url, port);

    int id = putPlayer(http, name, true);
    getPlayerList(http, true);
    
    if(id > -1){
        ClientStatus cstatus = ClientStatus::WAITING ;
        std::mutex mtx ;
        thread thReq(&queryGameStatus, std::ref(http), std::ref(cstatus), std::ref(mtx));
        cout << "---Press <Enter> to quit lobby---" << endl ;
        (void) getc(stdin);
        if(cstatus == ClientStatus::WAITING) cstatus = ClientStatus::QUIT ;
        thReq.join();

        if(cstatus == ClientStatus::INGAME){
            playGame(http, id);
            cstatus = ClientStatus::QUIT ;
        }

        removePlayer(http, id, true);
        getPlayerList(http, true);
    }else{
        cout << "Cannot join game : room is full." << endl ;
    }
}

// QUERY GAME STATUS

void queryGameStatus(sf::Http& http, ClientStatus& status, std::mutex& mtx){
    time_t t0, t1 ;
    Json::Value data ;
    while(status==ClientStatus::WAITING){        
        time(&t1);
        if(difftime(t1, t0) > 1.0/2){
            data = getPlayerList(http);
            if(data[0]["name"]!="Open" && data[1]["name"]!="Open"){
                std::lock_guard<std::mutex> lock(mtx);
                status = ClientStatus::INGAME ;
            }
            time(&t0);
        }
    }
    if(status == ClientStatus::INGAME)
        cout << "Game Started. Press <Enter> to join." << endl ;
    else
        cout << "Exit Game" << endl ;
}

// launch th game
void playGame(sf::Http& http, int id){
    int tick = 0 ;

    State state(WIDTH, HEIGHT);

    generateTestMap(state);
    generateTestUnits(state);

    Engine engine(state);
    if(id == 0){
        cout << "Client 1 creating coms..." << endl ;
        vector<Command*> coms ;
        generateCommandList(engine, coms);
        cout << "Command list generated !" << endl ;

        for(int i=0 ; i<(int)(coms.size()) ; i++){
            cout << "putting " << i << " of " << (int)(coms.size()) << " : " << coms[i] << endl ;
            putCommand(http, coms[i]);
        }
        cout << "finished"<< endl ;
    }

    Render render(state);
    render.update();

    time_t rendT0, rendT1 ;
    time_t engT0, engT1 ;

    sf::RenderWindow window(sf::VideoMode(WINWIDTH, WINHEIGHT), "Network");

    time(&rendT0);
    time(&rendT1);



    thread thEng(&Engine::run, std::ref(engine));
    engine.setStatus(RUN);
    
    render.update();
    window.clear();
    render.draw(window);
    window.display();

    while(window.isOpen()){
        //check event
        sf::Event event ;
        while(window.pollEvent(event)){
//---POLLEVENT LOOP
            switch(event.type){
                case sf::Event::Closed :    //close request
                    window.close();
                    break;
                /*case sf::Event::KeyReleased :
                    {
                    Command * com = getCommand(http, engine, tick);
                    if(com != nullptr)
                        engine.addCommand(com);
                    }
                    break ;*/
                default :
                    break;
            }
//---END POLLEVENT LOOP
        }

        time(&rendT1);
        if(difftime(rendT1, rendT0) > 1.0/60.0){
            render.update();
            window.clear();
            render.draw(window);
            window.display();
            time(&rendT0);
        }
        
        time(&engT1);
        if(difftime(engT1, engT0) > 1.0/1.5){
            Command * com = getCommand(http, engine, tick);
            if(com != nullptr)
                engine.addCommand(com);
            time(&engT0);
        }
    }

    engine.setStatus(EngineStatus::QUIT);
    thEng.join();
}

// REQUEST CODE
// Send a request and get request return value
Json::Value sendRequest(sf::Http& http, sf::Http::Request& req, bool debug){
    sf::Http::Response resp = http.sendRequest(req);
    sf::Http::Response::Status status = resp.getStatus();
    if(debug==true) std::cout << "Status " << status << std::endl;

    Json::Value data ;

    if (status == sf::Http::Response::Ok || 
        status == sf::Http::Response::Created || 
        status == sf::Http::Response::Accepted)
    {
        if(debug==true) std::cout << resp.getBody() << std::endl;
        Json::Reader reader ;
        reader.parse(resp.getBody(), data);
    }else
        data["id"] = -1 ;

    return data ;
}

// Queries  functions
void getVersion(sf::Http& http, bool debug){
    if(debug==true) cout << ">>> getVersion :"<< endl ;
    sf::Http::Request req("/version");
    // Check the status code and display the result
    sendRequest(http, req, debug);
}
void getPlayer(sf::Http& http, int id, bool debug){
    if(debug==true) cout << ">>> Get Player " << id << " :" << endl ;
    sf::Http::Request req("/player/"+to_string(id));
    // Check the status code and display the result
    sendRequest(http, req, debug);
}

Json::Value getPlayerList(sf::Http& http, bool debug){
    if(debug==true) cout << ">>> Get Player list :"<<endl ;
    sf::Http::Request req("/player/-1");
    // Check the status code and display the result
    return sendRequest(http, req, debug);
}

int putPlayer(sf::Http& http, const string& name, bool debug){
    if(debug==true) cout << ">>> Put Player " << name << " :" << endl ;
    sf::Http::Request req("/player");
    req.setMethod(sf::Http::Request::Put);
    req.setHttpVersion(1, 1);
    req.setField("Content-Type", "application/x-www-form-urlencoded");

    Json::Value data ;
    data["name"] = name ;
    req.setBody(data.toStyledString());

    // Check the status code and display the result
    Json::Value val = sendRequest(http, req, debug);
    int id = val["id"].asInt();
    return id ;
}

void postPlayer(sf::Http& http, const string& newname, int id, bool debug){
    if(debug==true) cout << ">>> Post Player " << id << " " << newname << " :" << endl ;
    sf::Http::Request req("/player/"+to_string(id));
    req.setMethod(sf::Http::Request::Post);
    req.setHttpVersion(1, 1);
    req.setField("Content-Type", "application/x-www-form-urlencoded");

    Json::Value data ;
    data["name"] = newname ;
    req.setBody(data.toStyledString());

    // Check the status code and display the result
    sendRequest(http, req, debug);
}

void removePlayer(sf::Http& http, int id, bool debug){
    if(debug==true) cout << ">>> Delete Player " << id << " :" << endl ;
    sf::Http::Request req("/player/"+to_string(id));
    req.setMethod(sf::Http::Request::Delete);
    req.setHttpVersion(1, 1);
    req.setField("Content-Type", "application/x-www-form-urlencoded");

    // Check the status code and display the result
    sendRequest(http, req, debug);
}

// COMMANDS

void putCommand(sf::Http& http, const Command* com){
    cout << "putCommand execute..." << endl ;
    if(com == nullptr){
        cout << "putCommand : com=nullptr" << endl ;
        throw nullptr ;
    }

    sf::Http::Request req("/command");
    req.setMethod(sf::Http::Request::Put);
    req.setHttpVersion(1, 1);
    req.setField("Content-Type", "application/x-www-form-urlencoded");

    cout << "converting to Json ..." <<endl ;
    Json::Value data = com->toJson();

    cout << "setbody ..." << endl ;
    req.setBody(data.toStyledString());

    // Check the status code and display the result
    cout << "sending request ... "<< endl ;
    Json::Value val = sendRequest(http, req);
    //cout << "putCommand : " << com << endl ;
}

Command* getCommand(sf::Http& http, Engine& engine, int& tick){
    sf::Http::Request req("/command/"+to_string(tick));
    req.setMethod(sf::Http::Request::Get);
    // Check the status code and display the result
    Json::Value data = sendRequest(http, req, true);
    if(data["id"]==-1)
        return nullptr ;
    Command* com = nullptr ;
    //const ElementTab& utab = engine.getState().getUnitTab();
    if(data["CommandTypeId"]==COM_ATTACK){
        /*Int(), ay = data["Attacker"]["y"].asUInt();
        Unit* a = (Unit*)utab.getElem(ax, ay);
        size_t dx = data["Defender"]["x"].asUInt(), dy = data["Defender"]["y"].asUInt();
        Unit* d = (Unit*)utab.getElem(dx, dy);
        com = new AttackCommand(*a,*d);
        */
        int attId = data["attId"].asInt();
        int defId = data["defId"].asInt();
        com = new AttackCommand(engine.getState(), attId, defId);
        tick++ ;
    }else if(data["CommandTypeId"] == COM_MOVE){
        /*
        size_t x = data["Unit"]["x"].asUInt(), y = data["Unit"]["y"].asUInt();
        Unit& u = *(Unit*)utab.getElem(x, y);
        size_t mx = data["x"].asUInt(), my = data["y"].asUInt();
        com = new MoveCommand(u, mx, my);
        */
        int unitId = data["unitId"].asInt() ;
        size_t x = data["x"].asUInt(), y = data["y"].asUInt();
        com = new MoveCommand(engine.getState(), unitId, x, y);
        tick++ ;
    }else if(data["CommandTypeId"] == COM_ENDTURN){
        com = new EndTurnCommand(engine.getState());
        tick++ ;
    }else{
        cout << "in network::getCommand, error : no Command" << endl ;
    }
    //cout << "getCommand : " << com << endl ;
    return com ;
}
