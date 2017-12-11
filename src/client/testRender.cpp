#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "state.h"
#include "render.h"

#define WIDTH 30
#define HEIGHT 20
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16
#define RDMAPGENITER 6000

using namespace std ;
using namespace state ;
using namespace render ;

namespace renderTest{
    CellType* generateMap(int w, int h, string fname = "level.txt");
    CellType generateCell();
    void generateRoad(int x, int y, CellType* map);
    void saveMap(CellType *map, int w, int h, string fname="level.txt");
    int* loadMap(string fname="level.txt");
    void generateMap(State &state);
    void generateUnits(State &state);
};

using namespace renderTest;

void testRender(int mode, string fname){

    sf::RenderWindow window(sf::VideoMode(WINWIDTH, WINHEIGHT), "My window - test sprite");

    srand(time(NULL));
    State state(WIDTH, HEIGHT);
    
    generateMap(state);
    generateUnits(state);

    state.debug();

    Render render(state) ;

    cout << "render.update();" << endl ;

    render.update();

    cout << "<<Opening window>>" << endl ;

    while(window.isOpen()){
        //check event
        sf::Event event ;
        while(window.pollEvent(event)){
            
            switch(event.type){
                case sf::Event::Closed :    //close request
                    window.close();
                    break;
                default :
                    break;
            }
        }
        
        window.clear(sf::Color::Black);
        
        render.draw(window);
        
        window.display();
    }
}
/*
void testRenderNoClass(int mode, string fname){
    srand(time(NULL));
    
    //window.setFramerateLimit(60);
    
    cout << "Generation de terrain ..." << endl ;
    CellType *tileMap ;
    //if(mode == 0)
        tileMap = generateMap(WIDTH, HEIGHT, fname);
    //else
        //tileMap = loadMap(fname);
    cout << "Generation terminee" << endl ;
    
    sf::Texture tex_tileset ;
    sf::Texture tex_inftRed ;
    
    sf::VertexArray tileVertices ;
    
    cout << "Chargement des textures ..." << endl ;
    
    if(!tex_tileset.loadFromFile("res/_cells_test.png"))
        cout<< "couldn't load texture res/_cells_test.png" << endl ;
    if(!tex_inftRed.loadFromFile("res/infantry_red.png"))
        cout<< "couldn't load texture res/infantry_red.png" << endl ;
    
    cout << "Chargement des fichiers termine" << endl ;
    
    tileVertices.setPrimitiveType(sf::Quads);
    tileVertices.resize(20*30*4);
    for(int j=0 ; j<20 ; j++)
        for(int i=0 ; i<30 ; i++){
            int tileType = (int)tileMap[i+j*WIDTH] ;
            
            sf::Vertex* quad = &tileVertices[(i+j*30)*4];
            
            quad[0].position = sf::Vector2f(i*16, j*16);
            quad[1].position = sf::Vector2f((i+1)*16, j*16);
            quad[2].position = sf::Vector2f((i+1)*16, (j+1)*16);
            quad[3].position = sf::Vector2f(i*16, (j+1)*16);
            
            quad[0].texCoords = sf::Vector2f(tileType*16, 0);
            quad[1].texCoords = sf::Vector2f((tileType+1)*16, 0);
            quad[2].texCoords = sf::Vector2f((tileType+1)*16, 16);
            quad[3].texCoords = sf::Vector2f(tileType*16, 16);
        }
    
    cout << "Chargement des tiles termine" << endl ;
    
    sf::Sprite spr_inftrRed;
    spr_inftrRed.setTexture(tex_inftRed);
    
    cout << "Chargement de texture unit terminee" << endl ;
    
    spr_inftrRed.setPosition(sf::Vector2f(16,0));
    
    cout << "Chargement des textures termine, ouverture de fenetre" << endl ;
    
    sf::RenderWindow window(sf::VideoMode(WINWIDTH, WINHEIGHT), "My window - test sprite");
    
    while(window.isOpen()){
        //check event
        sf::Event event ;
        while(window.pollEvent(event)){
            
            switch(event.type){
                case sf::Event::Closed :    //close request
                    window.close();
                    break;
                case sf::Event::KeyReleased :        //Keyboard Commands
                    switch(event.key.code){
                        case sf::Keyboard::Right :
                            spr_inftrRed.move(sf::Vector2f(16,0));
                            break;
                        case sf::Keyboard::Down :
                            spr_inftrRed.move(sf::Vector2f(0,16));
                            break;
                        case sf::Keyboard::Left :
                            spr_inftrRed.move(sf::Vector2f(-16,0));
                            break;
                        case sf::Keyboard::Up :
                            spr_inftrRed.move(sf::Vector2f(0,-16));
                            break;
                            
                        default :
                            break;
                    }
                    break;
                    
                default :
                    break;
            }
        }
        
        window.clear(sf::Color::Black);
        
        window.draw(tileVertices, &tex_tileset);
        window.draw(spr_inftrRed);
        
        window.display();
    }
    
    delete[] tileMap; // detruit la carte generee dynamiquement
    
}
*/
namespace renderTest{

CellType* generateMap(int w, int h, string fname){
    CellType *tileMap = new CellType[w * h];
    
    for(int i=0 ; i<w ; i++)
        for(int j=0 ; j<h ; j++){
            tileMap[i + j*w] = generateCell() ; // plaine, foret, montagne, mer
        }
    
    for(int n=0 ; n<RDMAPGENITER ; n++){    //traitement de carte (homogeneisation)
        int x = rand()%w ; // selectionne une case
        int y = rand()%h ;
        
        if(rand()%100 < 60){ //prend la valeur d'un voisin, sinon rien
            int vx=x, vy=y ;
            if(rand()%2==0)
                vx += (rand()%2)*2 -1 ;
            else
                vy += (rand()%2)*2 -1 ;
            
            if(vx>=0 && vx<w && vy>=0 && vy<h)
                tileMap[vx + vy*w] = tileMap[x + y*w];
        }
        if(n%(RDMAPGENITER/10) == 0)
            cout << "." ;
    }
    
    cout << endl ;
    
    // placement de villes, routes
    do{
        int x = rand()%w ;
        int y = rand()%h ;
        tileMap[x+y*w] = CT_CITY ;
        generateRoad(x, y, tileMap);
    }while(rand()%100 < 90);
    
    int x = rand()%w ; //placement du QG
    int y = rand()%h ;
    
    generateRoad(x, y, tileMap);
    tileMap[x+y*w] = CT_BASE ;
    
    if(fname != "NULL");
        saveMap(tileMap, w, h, fname);
    
    return tileMap ;
}

CellType generateCell(){
    const int pG=40, pS=15, pM=15, pF=20 ;
    int ct = rand()%(pG+pS+pM+pF) ;
    if(ct < pG)
        return CT_PLAIN ;
    else if(ct < pG+pS)
        return CT_SEA ;
    else if(ct < pG+pS+pM)
        return CT_MOUNTAIN ;
    else
        return CT_FOREST ;
}

void generateRoad(int x, int y, CellType* map){
    do{
        if(rand()%2 == 0)
            x = x+ (rand()%2)*2-1;
        else
            y = y+ (rand()%2)*2-1;
            
        if(x<0 || y<0 || x>=WIDTH || y>=HEIGHT)
            break;
            
        if(map[x+y*WIDTH]==CT_SEA)
            map[x+y*WIDTH]=CT_BRIDGE ;
        else
            map[x+y*WIDTH]=CT_ROAD ;
    }while(rand()%100<75);
    if(rand()%100 < 75)
        map[x+y*WIDTH] = CT_CITY ;
}

void saveMap(CellType *map, int w, int h, string fname){
    ofstream file;
    file.open(fname.c_str());
    file << w << "\n" << h << "\n" ;
    for(int j=0 ; j<h ; j++){
        for(int i=0 ; i<w ; i++){
            file << (int)map[i+j*w];
            if(i!=h-1)
                file<<" ";
        }
        file << "\n" ;
    }
    file.close();
}

void generateMap(State &state){
    CellType* map = generateMap(state.getW(), state.getH(), "level.txt");
    ElementTab& ctab = state.getCellTab();
    for(size_t j=0 ; j<state.getH() ; j++){
        for(size_t i=0 ; i<state.getW() ; i++){
            Element *c = new Cell(map[i+j*state.getW()], i,j);
            //cout << c << " " ;
            //c->debug() ;
            ctab.addElem(c);
        }
    }
    delete[] map ;
}

void generateUnits(State &state){
    ElementTab& ctab = state.getCellTab();
    ElementTab& utab = state.getUnitTab();
    for(int j=0 ; j<HEIGHT ; j++)
        for(int i=0 ; i<WIDTH ; i++)
            if(rand()%100 <= 15){
                Element* u ;
                int uteam = rand()%2+1 ;
                CellType ct = ((Cell*)ctab.getElem(i,j))->getCellType();
                if(ct==CT_MOUNTAIN || ct==CT_RIVER){
                    int ut = rand()%7;
                    if(ut>1) ut+=10 ;
                    u = new Unit(uteam, ut, i, j);
                }else if(ct==CT_SEA){
                    int ut = rand()%10 + 12 ;
                    u = new Unit(uteam, ut, i, j);
                }else{
                    int ut = rand()%17 ;
                    u = new Unit(uteam, ut, i, j);
                }
                utab.addElem(u);
            }
}

};