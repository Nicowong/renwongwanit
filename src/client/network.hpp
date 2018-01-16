#ifndef __Network_hpp__
#define __Network_hpp__

#include <SFML/Network.hpp>

#include "json/json.h"
#include "json/json-forwards.h"

using namespace std ;

Json::Value sendRequest(sf::Http& http, sf::Http::Request& req, bool debug=false);
void getVersion(sf::Http& http, bool debug=false);
void getPlayer(sf::Http& http, int id=-1, bool debug=false);
Json::Value getPlayerList(sf::Http& http, bool debug=false);
int putPlayer(sf::Http& http, const string& name, bool debug=false);
void postPlayer(sf::Http& http, const string& newname, int id, bool debug=false);
void removePlayer(sf::Http& http, int id, bool debug=false);

#endif
