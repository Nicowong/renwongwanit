#include <iostream>
#include <string>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne

#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

//#include "state.h"

using namespace std;
//using namespace state;

/*fonctions de test unitaire*/
void testHello();
void testState();
void testRender(int mode=0, string fname="level.txt");
void testEngine();
void testRandomAi();

/*--- Fonction main ---*/

int main(int argc,char* argv[]) {
    int retVal = -1 ;
    
    // affichage de la liste des arguments
    for(int i=0 ; i<argc ; i++)
        std::cout << "argc = " << argc << " ; argv[" << i << "]: " << argv[i] << std::endl<<std::endl ;
    
    //commandes pour les tests unitaires
    // --- test hello
    if(std::string(argv[1])=="hello"){
        testHello();
    }
    // --- test state
    else if(std::string(argv[1])=="state"){
        testState();
    }
    //--- RENDER pour les tests de rendus
    else if(std::string(argv[1])=="render"){
        int mode ;
        string fname ;
        if(argc>2 && (string)argv[2]=="load")
            mode = 1 ;
        else
            mode = 0 ;
        if(argc>3)
            fname = argv[3];
        else
            fname = "level.txt";
    
        testRender(mode, fname);
    //--- ENGINE pour les tests de moteur
    }else if(string(argv[1])=="engine"){
        testEngine();
    //--- AI pour les test d'ai
    }else if(string(argv[1])=="ai" || string(argv[1])=="random" || string(argv[1])=="randomAi"){
        testRandomAi();
    //Pas de commande
    }else{
        std::cout << "-- Error : command not found. --" << std::endl ;
        std::cout << "> Available commands : " << std::endl ;
        cout << "hello  test print 'Hello'" << endl ;
        cout << "state  test state classes" << endl ;
        cout << "engine test engine classes" << endl ;
        cout << "ai     test ai classes" << endl ;
    }
    
    std::cout << endl ;
    
    retVal = 0;
    return retVal;
}
