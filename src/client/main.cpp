#include <iostream>
#include <string>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"

using namespace std;
using namespace state;

/*--- Prototype des fonctions de test ---*/
void testUnit();
void unitShow(const Unit& unit);
void testBuilding();
void buildingShow(const Building& b);


/*--- Fonction main ---*/

int main(int argc,char* argv[]) {
    int retVal = -1 ;
    std::cout << "Bonjour le monde !" << std::endl ;
    
    // affichage de la liste des arguments
    for(int i=0 ; i<argc ; i++)
        std::cout << "argc = " << argc << " ; argv[" << i << "]: " << argv[i] << std::endl<<std::endl ;
    
    for(int i=1 ; i<argc ; i++){
        std::cout << std::endl << ">>>argv["<<i<<"] : "<<argv[i] << std::endl;
        
        //command STATE pour les tests unitaires
        if(std::string(argv[i])=="state"){
            testUnit();
            std::cout << "-------------------------" <<std::endl;
            testBuilding();
            
        //commande RENDER pour les tests de rendus
        }else if(std::string(argv[i])=="render"){
            sf::Window window(sf::VideoMode(400,300), "My window");
            
            while(window.isOpen()){
                //check event
                sf::Event event ;
                while(window.pollEvent(event)){
                    //close request
                    if(event.type == sf::Event::Closed)
                        window.close();
                }
            }
            
        //Pas de commande
        }else{
            std::cout << "Error : command not found." << std::endl ;
        }
    }
    
    
    std::cout << endl ;
    return retVal;
}

/*--- Fonctions de test ---*/
void unitShow(const Unit& unit){
    std::cout<< std::endl ;
    std::cout<< "type : " << unit.getUnitType() << std::endl ;
    std::cout<< "team : " << unit.getUnitTeam() << std::endl ;
    std::cout<< "x : " << unit.getX() << " ; y : " << unit.getY() << std::endl ;
    std::cout<< "health : " << unit.getHealth() << " ; ammo : " << unit.getAmmo() << std::endl;
    std::cout<< "fuel : " << unit.getFuel() << " ; vision : " << unit.getVision() << std::endl ;
}
void buildingShow(const Building& b){
    std::cout<< std::endl ;
    std::cout<< "type : " << b.getBuildingType() << std::endl ;
    std::cout<< "team : " << b.getBuildingTeam() << std::endl ;
    std::cout<< "x : " << b.getX() << " ; y : " << b.getY() << std::endl ;
    std::cout<< "capture : " << b.getCapturePoints() << std::endl;
}
  
void testUnit(){
    std::cout<< "Creation de Unit par defaut."<< std::endl ;
    Unit unit ;
    unitShow(unit);
    
    std::cout<< std::endl << "Changement de valeurs attribut."<<std::endl ;
    unit.setX(10);
    unit.setY(12);
    unit.setAmmo(50);
    unit.setFuel(25);
    unit.setUnitTeam(UT_PLAYER2);
    unit.setUnitType(UT_RECON);
    unit.setVision(4);
    unitShow(unit);
    
    std::cout<< std::endl << "Creation de Unit de type INFANTRY."<<std::endl ;
    Unit unitInf(3,4, UT_INFANTRY, UT_PLAYER2);
    unitShow(unitInf);
    std::cout<< std::endl << "Creation de Unit de type MECH."<<std::endl ;
    Unit unitMech(5,6, UT_MECH, UT_PLAYER1);
    unitShow(unitMech);
    std::cout<< std::endl << "Creation de Unit de type RECON."<<std::endl ;
    Unit unitRecon(7,8, UT_RECON, UT_PLAYER2);
    unitShow(unitRecon);
}

void testBuilding(){
    std::cout << "Creation de Building par defaut" << std::endl ;
    Building b1 ;
    buildingShow(b1);
    
    std::cout<< "Changement d'attribut" << endl << endl;
    
    b1.setX(1);
    b1.setY(2);
    b1.setCapturePoints(10);
    b1.setBuildingTeam(BT_PLAYER1);
    b1.setBuildingType(BT_BASE);
    buildingShow(b1);
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