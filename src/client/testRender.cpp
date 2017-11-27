#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "state.h"
#include "render.h"

#include "mapGeneration.h"

#ifndef __CLIENT__
#define __CLIENT__
#endif

#define WIDTH 30
#define HEIGHT 20
#define WINWIDTH WIDTH*16
#define WINHEIGHT HEIGHT*16+64

using namespace std ;
using namespace state ;
using namespace render ;

using namespace mapGeneration;

void testRender(int mode, string fname){
    srand(time(NULL));
    State state(WIDTH, HEIGHT);
    
    generateMap(state);
    generateUnits(state);

    state.debug();

    ElementTab& etab = state.getUnitTab();

    Render render(state) ;

    cout << "render.update();" << endl ;

    render.update();

    cout << "<<Opening window>>" << endl ;

    sf::RenderWindow window(sf::VideoMode(WINWIDTH, WINHEIGHT), "My window - test sprite");
    while(window.isOpen()){
        //check event
        sf::Event event ;
        while(window.pollEvent(event)){
            
            switch(event.type){
                case sf::Event::Closed :    //close request
                    window.close();
                    break;
                case sf::Event::KeyReleased :
                    switch(event.key.code){
                        case sf::Keyboard::Space :
                            size_t x1, x2, y1, y2, z ;
                            z=0 ;
                            do{
                                x1=rand()%WIDTH ;
                                y1=rand()%HEIGHT ;
                                z++ ;
                            }while(etab.getElem(x1,y1)==nullptr && z<50);
                            z=0;
                            do{
                                x2=rand()%WIDTH ;
                                y2=rand()%HEIGHT ;
                                z++ ;
                            }while(etab.getElem(x2,y2)!=nullptr && z<50);

                            etab.moveElem(x1,y1,x2,y2);

                            render.update();
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
