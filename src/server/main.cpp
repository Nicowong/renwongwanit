#include <iostream>
#include <string>


//#include "state.h"

using namespace std;
//using namespace state;

/*fonctions de test unitaire*/
void testHello();
void testState();
//void testRender(int mode=0, string fname="level.txt");
void testEngine();
void testRandom_ai();
void testHeuristic_ai();

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
    /*else if(std::string(argv[1])=="render"){
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
    }*/
    else if(string(argv[1])=="engine"){
        testEngine();
    //--- AI pour les test d'ai
    }else if(string(argv[1])=="random_ai"){
        testRandom_ai();
    //Pas de commande
    }else if(string(argv[1])=="heuristic_ai"){
        testHeuristic_ai();
    //Pas de commande
    }else{
        std::cout << "Error : command not found." << std::endl ;
    }
    
    std::cout << endl ;
    
    retVal = 0;
    return retVal;
}
