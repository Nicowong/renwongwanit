#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <fstream>
#include <string>

#include "json/json.h"
#include "json/json-forwards.h"

#include "state.h"

using namespace std ;

Json::Value sendRequest(sf::Http& http, sf::Http::Request& req);
void getVersion(sf::Http& http);
void getPlayer(sf::Http& http, int id=-1);
void getPlayerList(sf::Http& http);
int putPlayer(sf::Http& http, const string& name);
void postPlayer(sf::Http& http, const string& newname, int id);
void removePlayer(sf::Http& http, int id);

void network(const string& name, int port){
    // Setting host
    sf::Http http;
    string url("http://localhost");
    cout << "host : " << url << ":" << port << endl << endl ;
    http.setHost(url, port);

    int id = putPlayer(http, name);
    getPlayerList(http);
    
    if(id > -1){
        cout << "---Press <Enter> to continue---" << endl;
        (void) getc(stdin);
        removePlayer(http, id);
        getPlayerList(http);
    }else{
        cout << "Cannot join game : room is full." << endl ;
    }
}

Json::Value sendRequest(sf::Http& http, sf::Http::Request& req){
    sf::Http::Response resp = http.sendRequest(req);
    sf::Http::Response::Status status = resp.getStatus();
    std::cout << "Status " << status << std::endl;

    Json::Value data ;

    if (status == sf::Http::Response::Ok || 
        status == sf::Http::Response::Created || 
        status == sf::Http::Response::Accepted)
    {
        std::cout << resp.getBody() << std::endl;
        Json::Reader reader ;
        reader.parse(resp.getBody(), data);
    }else
        data["id"] = -1 ;

    return data ;
}

void getVersion(sf::Http& http){
    cout << ">>> getVersion :"<< endl ;
    sf::Http::Request req("/version");
    // Check the status code and display the result
    sendRequest(http, req);
}
void getPlayer(sf::Http& http, int id){
    cout << ">>> Get Player " << id << " :" << endl ;
    sf::Http::Request req("/player/"+to_string(id));
    // Check the status code and display the result
    sendRequest(http, req);
}

void getPlayerList(sf::Http& http){
    cout << ">>> Get Player list :"<<endl ;
    sf::Http::Request req("/player/-1");
    // Check the status code and display the result
    sendRequest(http, req);
}

int putPlayer(sf::Http& http, const string& name){
    cout << ">>> Put Player " << name << " :" << endl ;
    sf::Http::Request req("/player");
    req.setMethod(sf::Http::Request::Put);
    req.setHttpVersion(1, 1);
    req.setField("Content-Type", "application/x-www-form-urlencoded");

    Json::Value data ;
    data["name"] = name ;
    req.setBody(data.toStyledString());

    // Check the status code and display the result
    Json::Value val = sendRequest(http, req);
    int id = val["id"].asInt();
    return id ;
}

void postPlayer(sf::Http& http, const string& newname, int id){
    cout << ">>> Post Player " << id << " " << newname << " :" << endl ;
    sf::Http::Request req("/player/"+to_string(id));
    req.setMethod(sf::Http::Request::Post);
    req.setHttpVersion(1, 1);
    req.setField("Content-Type", "application/x-www-form-urlencoded");

    Json::Value data ;
    data["name"] = newname ;
    req.setBody(data.toStyledString());

    // Check the status code and display the result
    sendRequest(http, req);
}

void removePlayer(sf::Http& http, int id){
    cout << ">>> Delete Player " << id << " :" << endl ;
    sf::Http::Request req("/player/"+to_string(id));
    req.setMethod(sf::Http::Request::Delete);
    req.setHttpVersion(1, 1);
    req.setField("Content-Type", "application/x-www-form-urlencoded");

    // Check the status code and display the result
    sendRequest(http, req);
}
