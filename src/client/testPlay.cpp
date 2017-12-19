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

/*
#define WIDTH 10
#define HEIGHT 10
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16+64
*/
  
void testPlay(){
    cout << "Replaying from replay.txt" << endl ;

    ifstream ifs("replay.txt", ifstream::in);
    Json::Reader reader;
    Json::Value root;

    reader.parse(ifs, root);

    int w,h ;
    cout << "reading State ..." << endl ;
    w = root["w"].asUInt();
    h = root["h"].asUInt();
    cout << "mapSize is : w=" << w << " h=" << h << endl ;
    State state(w,h);
    ElementTab& ctab = state.getCellTab();
    ElementTab& utab = state.getUnitTab();

    for(int j=0 ; j<h ; j++)
        for(int i=0 ; i<w ; i++){
            CellType ct = (CellType)root["ctab"][i+j*w]["ctype"].asInt();
            if(ct<CT_BASE){
                Cell *c = new Cell(ct, i, j);
                ctab.addElem(c);
            }else{
                Team tm = (Team)root["ctab"][(unsigned int)(i+j*w)]["team"].asInt();
                int cp = root["ctab"][(unsigned int)(i+j*w)]["cp"].asInt();
                Building *b = new Building(tm, ct, i, j);
                b->setCapturePoints(cp);
                ctab.addElem(b);
            }
            bool noUnit = root["utab"][(unsigned int)(i+j*w)]["empty"].asBool();
            if(!noUnit){
                UnitType ut = (UnitType)root["utab"][(unsigned int)(i+j*w)]["utype"].asInt();
                Team tm = (Team)root["utab"][(unsigned int)(i+j*w)]["team"].asInt();
                Unit *u = new Unit(tm, ut, i, j, true);
                int health = root["utab"][(unsigned int)(i+j*w)]["health"].asInt();
                int ammo = root["utab"][(unsigned int)(i+j*w)]["ammo"].asInt();
                u->setHealth(health);
                u->setAmmo(ammo);
                utab.addElem(u);
            }
        }
    cout << "finished reading state." << endl ;

    Render render(state);
    render.update();

    Engine engine(state, false); //no record
    cout << "reading commands ..." << endl ;

    reader.parse(ifs, root);
    for(int ncom = 0 ; ncom < root["ncom"].asInt() ; ncom++){
        Command *com = nullptr ;
        string scom = root["com"][ncom]["CommandType"].asString();
        if(scom == "COM_ATTACK"){
            size_t ax = root["com"][ncom]["Attacker"]["x"].asUInt(), ay = root["com"][ncom]["Attacker"]["y"].asUInt();
            Unit* a = (Unit*)utab.getElem(ax, ay);
            size_t dx = root["com"][ncom]["Defender"]["x"].asUInt(), dy = root["com"][ncom]["Defender"]["y"].asUInt();
            Unit* d = (Unit*)utab.getElem(dx, dy);
            com = new AttackCommand(*a,*d);
        }else if(scom == "COM_MOVE"){
            size_t x = root["com"][ncom]["Unit"]["x"].asUInt(), y = root["com"][ncom]["Unit"]["y"].asUInt();
            Unit& u = *(Unit*)utab.getElem(x, y);
            size_t mx = root["com"][ncom]["x"].asUInt(), my = root["com"][ncom]["y"].asUInt();
            com = new MoveCommand(u, mx, my);
        }else if(scom == "COM_ENDTURN"){
            com = new EndTurnCommand(state);
        }else{
            cout << "in TestPlay, error : no Command" << endl ;
            break ;
        }
        engine.addCommand(com);
    }
    cout << "finished reading commands." << endl ;
    ifs.close();

    time_t prvt=0, now=0 ;

    sf::RenderWindow window(sf::VideoMode(w*16, h*16+64), "testPlay");

    time(&prvt);
    time(&now);

    engine.debug();
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
                default :
                    break;
            }
//---END POLLEVENT LOOP
        }

        time(&now);
        if(difftime(now, prvt) > 1.0/60.0){
            
            render.update();
            window.clear();
            render.draw(window);
            window.display();
            time(&prvt);
            
        }
    }

    engine.setStatus(QUIT);
    thEng.join();
}