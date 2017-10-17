#include <iostream>
#include <SFML/Graphics.hpp>

#include "state.h"

using namespace std ;
using namespace state ;

void testRender(){
    sf::RenderWindow window(sf::VideoMode(480,320), "My window - test sprite");
    
    window.setFramerateLimit(60);
    
    sf::Texture tex_road;
    sf::Texture tex_inftRed ;
    
    if(!tex_road.loadFromFile("res/road_5.png"))
        cout<< "couldn't load texture res/road_5.png" << endl ;
    if(!tex_inftRed.loadFromFile("res/infantry_red.png"))
        cout<< "couldn't load texture res/infantry_red.png" << endl ;
    
    sf::Sprite spr_road ;
    sf::Sprite spr_inftrRed;
    spr_road.setTexture(tex_road);
    spr_inftrRed.setTexture(tex_inftRed);
    
    spr_road.setPosition(sf::Vector2f(0,0));
    spr_inftrRed.setPosition(sf::Vector2f(16,0));
    
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
        
        for(int x=0 ; x<30 ; x++)
            for(int y=0 ; y<20 ; y++){
                spr_road.setPosition(sf::Vector2f(x*16, y*16));
                window.draw(spr_road);
            }
        window.draw(spr_inftrRed);
        
        window.display();
    }
}