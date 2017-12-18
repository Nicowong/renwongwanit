#include <iostream>
#include <fstream>
#include <thread>
#include "state.h"
#include "render.h"
#include "engine.h"
#include "json/json.h"
#include "json/json-forwards.h"

#include "mapGeneration.h"
#include "CommandGeneration.h"

using namespace std ;
using namespace state ;
using namespace render ;
using namespace engine ;


#define WIDTH 10
#define HEIGHT 10
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16+64

void testPlay(){
    ifstream ifs("replay.txt", ifstream::in);

    State state(WIDTH, HEIGHT);

    Render render(state);
    render.update();

    Engine engine(state, true);

    ifs.close();

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
