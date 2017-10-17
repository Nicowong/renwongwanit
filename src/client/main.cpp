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

/*fonctions de test unitaire*/
void testHello();
void testState();
void testRender();

/*--- Fonction main ---*/

int main(int argc,char* argv[]) {
    int retVal = -1 ;
    
    // affichage de la liste des arguments
    for(int i=0 ; i<argc ; i++)
        std::cout << "argc = " << argc << " ; argv[" << i << "]: " << argv[i] << std::endl<<std::endl ;
    
    for(int i=1 ; i<argc ; i++){
        std::cout << std::endl << ">>>argv["<<i<<"] : "<<argv[i] << std::endl;
        
        //command STATE pour les tests unitaires
        // --- test hello
        if(std::string(argv[i])=="hello"){
            testHello();
        }
        // --- test state
        else if(std::string(argv[i])=="state"){
            testState();
        }
        //commande RENDER pour les tests de rendus
        else if(std::string(argv[i])=="render"){
            testRender();
            
        //Pas de commande
        }else{
            std::cout << "Error : command not found." << std::endl ;
        }
    }
    
    std::cout << endl ;
    
    retVal = 0;
    return retVal;
}
