#include <iostream>
#include <string>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"

//using namespace std;
using namespace state;

/*--- Prototype des fonctions de test ---*/
void testUnit();
void testBuilding();


/*--- Fonction main ---*/

int main(int argc,char* argv[]) {
    int retVal = -1 ;
    std::cout << "Bonjour le monde !" << std::endl ;
    
    for(int i=0 ; i<argc ; i++)
        std::cout << "argc = " << argc << " ; argv[" << i << "]: " << argv[i] << std::endl ;
    
    for(int i=1 ; i<argc ; i++){
        std::cout << ">>>argv["<<i<<"] : "<<argv[i] << std::endl;
        if(std::string(argv[i])=="state"){
            testUnit();
        }else{
            std::cout << "Error : command not found." << std::endl ;
        }
    }
    
    return retVal;
}

/*--- Fonctions de test ---*/

void testUnit(){
    std::cout<< "Creation de Unit par defaut."<< std::endl ;
    Unit unit ;
    std::cout<< "type : " << unit.getUnitType() << std::endl ;
    std::cout<< "team : " << unit.getTeam() << std::endl ;
    std::cout<< "x : " << unit.getX() << " ; y : " << unit.getY() << std::endl ;
    
    
}



    
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