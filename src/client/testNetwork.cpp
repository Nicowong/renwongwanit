#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "state.h"
#include "network.hpp"

using namespace std ;

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
