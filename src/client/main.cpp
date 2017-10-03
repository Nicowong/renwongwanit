#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

//#include "state.h"

using namespace std;
//using namespace state;

int main(int argc,char* argv[]) 
{
    //Exemple exemple;
    //exemple.setX(53);

    //cout << "It works !" << endl;
    cout << "Bonjour le monde ! src/client/main.cpp" << endl;
    
    /*-----------------TEST SFML----------------*/
/*
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!", sf::Style::Default);
    sf::CircleShape shapeG(100.f);
    shapeG.setFillColor(sf::Color::Green);
    
    sf::CircleShape shapeR(100.f);
    shapeR.setFillColor(sf::Color::Red);
    
    int i = 0 ;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        if(i == 0){
            window.draw(shapeG);
            i=1;
        }else{
            window.draw(shapeR);
            i=0;
        }
        window.display();
        
        sf::sleep(sf::seconds(1.0f));
    }
*/
    return 0;
}
