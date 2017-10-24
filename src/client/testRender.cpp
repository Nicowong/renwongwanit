#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "state.h"

#define WIDTH 30
#define HEIGHT 20
#define RDMAPGENITER 6000

using namespace std ;
using namespace state ;

int* generateMap();
int generateCell();
void generateRoad(int x, int y, int* map);

void testRender(){
    srand(time(NULL));
    
    //window.setFramerateLimit(60);
    
    cout << "Generation de terrain ..." << endl ;
    int *tileMap = generateMap();
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
            int tileType = tileMap[i+j*WIDTH] ;
            
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
    
    sf::RenderWindow window(sf::VideoMode(480,320), "My window - test sprite");
    
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

int* generateMap(){
    int *tileMap = new int[WIDTH * HEIGHT];
    
    for(int i=0 ; i<WIDTH ; i++)
        for(int j=0 ; j<HEIGHT ; j++){
            tileMap[i + j*WIDTH] = generateCell() ; // plaine, foret, montagne, mer
        }
    
    for(int n=0 ; n<RDMAPGENITER ; n++){
        int x = rand()%WIDTH ; // selectionne une case
        int y = rand()%HEIGHT ;
        
        int luck = rand()%2 ;   //si pile : prend la valeur d'un voisin, sinon rien
        if(luck == 1){
            int vh, pm ;
            do{
                vh = rand()%2 ; //choix du voisin : vertical ou horizontal
                pm = (rand()%2) *2 -1 ;
            }while((vh==0 && (x+pm<0 || x+pm>=WIDTH)) || (vh==1 && (y+pm<0 || y+pm>=HEIGHT)));
            if(vh == 0 )
                tileMap[x+y*WIDTH] = tileMap[x+pm +y*WIDTH];
            else
                tileMap[x+y*WIDTH] = tileMap[x+(y+pm)*WIDTH];
        }
        if(n%(RDMAPGENITER/10) == 0)
            cout << "." ;
    }
    
    cout << endl ;
    
    // placement de villes, routes
    do{
        int x = rand()%WIDTH ;
        int y = rand()%HEIGHT ;
        tileMap[x+y*WIDTH] = CT_BUILDING ;
        generateRoad(x, y, tileMap);
    }while(rand()%100 < 95);
    
    int x = rand()%WIDTH ; //placement du QG
    int y = rand()%HEIGHT ;
    
    tileMap[x+y*WIDTH] = CT_BASE ;
    generateRoad(x, y, tileMap);
    
    return tileMap ;
}

int generateCell(){
    const int pG=40, pS=15, pM=15, pF=20 ;
    int ct = rand()%(pG+pS+pM+pF) ;
    if(ct < pG)
        return CT_GROUND ;
    else if(ct < pG+pS)
        return CT_SEA ;
    else if(ct < pG+pS+pM)
        return CT_MOUNTAIN ;
    else
        return CT_FOREST ;
}

void generateRoad(int x, int y, int* map){
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
        map[x+y*WIDTH] = CT_BUILDING ;
}
