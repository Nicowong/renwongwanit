#include <iostream>
#include <fstream>
#include <thread>
#include "state.h"
#include "engine.h"
#include "json/json.h"

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
