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

void testNetwork(int port){
    // Setting host
    sf::Http http;
    string url("http://localhost");
    cout << "host : " << url << ":" << port << endl << endl ;
    http.setHost(url, port);

    getVersion(http);

    cout << "---Press <Enter> to continue---" << endl;
    (void) getc(stdin);
    getPlayerList(http);

    cout << "---Press <Enter> to continue---" << endl;
    (void) getc(stdin);
    putPlayer(http, "Patrick");
    getPlayerList(http);

    cout << "---Press <Enter> to continue---" << endl;
    (void) getc(stdin);
    postPlayer(http, "Bob", 2);
    getPlayerList(http);

    cout << "---Press <Enter> to continue---" << endl;
    (void) getc(stdin);
    removePlayer(http, 1);
    getPlayerList(http);
}
