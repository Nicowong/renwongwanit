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

#include "engineTestGenerator.hpp"

#define WIDTH   12
#define HEIGHT  12
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16+64

using namespace std ;
using namespace render ;
using namespace engine ;

using namespace engineTest ;

enum ClientStatus{WAITING=0, INGAME=1, QUIT=2};
void queryGameStatus(sf::Http& http, ClientStatus& status, std::mutex& mtx);
void playGame();

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
            playGame();
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
void playGame(){
    int tick = 0 ;

    State state(WIDTH, HEIGHT);
    generateMap(state);
    generateUnits(state);

    Engine eng(state);

    Render render(state) ;
    render.update();

    sf::RenderWindow window(sf::VideoMode(WINWIDTH, WINHEIGHT), "My window - test sprite");
    while(window.isOpen()){
        //check event
        sf::Event event ;
        while(window.pollEvent(event)){
            
            switch(event.type){
                case sf::Event::Closed :    //close request
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    cout << "<<< tick : "<< tick << " >>>"<< endl ;
                    tick++;
                    eng.update();
                    eng.debug();
                    render.update();
                    cout << endl ;
                    break ;
                case sf::Event::MouseButtonReleased :
                    cout << "click"<<endl ;
                    break ;
                default :
                    break;
            }
        }
        
        window.clear(sf::Color::Black);
        
        render.draw(window);
        
        window.display();
    }

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
