#include <iostream>
#include <fstream>
#include <thread>
#include "state.h"
#include "engine.h"
#include "json/json.h"
#include "json/json-forwards.h"

#include "mapGeneration.h"
#include "CommandGeneration.h"

using namespace std ;
using namespace state ;
using namespace engine ;

using namespace mapGeneration ;
using namespace CommandGeneration ;

#define WIDTH 10
#define HEIGHT 10
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16+64
#define RDMAPGENITER 6000

using namespace std ;
using namespace state ;
using namespace engine ;

using namespace mapGeneration;
using namespace CommandGeneration ;

//void engineHandler(Engine *engine);
//bool engineQuit = false ;

void testRecord(){
	srand(time(NULL));
	State state(WIDTH, HEIGHT);

	generateTestMap(state);
	generateTestUnits(state);

    Engine engine(state, true);
    generateCommand(engine);

    //create a thread for engine. The engine starts in STOP mode
    thread thEng(&Engine::run, std::ref(engine));

    // set the engine in RUN mode. Run the engine until another setStatus(PAUSE or QUIT)
    // Json is written
    engine.setStatus(RUN);

    while(engine.getCurrentCommands().size()>0);

    //quit the engine
    engine.setStatus(QUIT);

    // join engine thread
    thEng.join();
}
/*
void engineHandler(Engine* engine){
    cout << "Engine Handler is running" << endl ;

    while(!engineQuit){
        //cout << "Engine Handler in while ..." << endl ;
        usleep(1000000/2);

        engine->update();

    }

    cout << "Engine Handler closing" << endl ;
}*/


/*
void testRecord(){
	srand(time(NULL));
	State state(WIDTH, HEIGHT);

	generateTestMap(state);
	generateTestUnits(state);

    Engine engine(state);
    generateCommand(engine);

    Json::Value root ;

    std::string encoding = root.get("encoding", "UTF-8").asString();
    cout << "encoding : " << encoding << endl ;

    const Json::Value plugins = root["plug-ins"];

	Json::StyledStreamWriter writer;
	// Make a new JSON document for the configuration. Preserve original comments.

	// You can also use streams.  This will put the contents of any JSON
	// stream at a particular sub-value, if you'd like.
	//std::cin >> root["subtree"];

	// And you can write to a stream, using the StyledWriter automatically.
	root["test"]["mem_A"] = 2 ;
	root["test"]["mem_B"] = "hello" ;
	root["test"]["mem_C"] = (char)'r' ;

	std::cout << root;

	ofstream ofs ;
	ofs.open("replay.txt", ofstream::out | ofstream::trunc);

	writer.write(ofs, root);

	ofs.close();

}*/
