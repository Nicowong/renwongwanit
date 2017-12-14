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
void testJson();

/*--- Fonction main ---*/

int main(int argc,char* argv[]) {
    int retVal = -1 ;
    
    // affichage de la liste des arguments
    for(int i=0 ; i<argc ; i++)
        std::cout << "argc = " << argc << " ; argv[" << i << "]: " << argv[i] << std::endl<<std::endl ;
    
    if(argc<2)
        return 2;
    //commandes pour les tests unitaires
    // --- test hello
    if(std::string(argv[1])=="hello"){
        testHello();
    }
    // --- test state
    else if(std::string(argv[1])=="state"){
        testState();
    }
    else if(string(argv[1])=="engine"){
        testEngine();
    //--- AI pour les test d'ai
    }else if(string(argv[1])=="random_ai"){
        testRandom_ai();
    //Pas de commande
    }else if(string(argv[1])=="heuristic_ai"){
        testHeuristic_ai();
    }else if(string(argv[1])=="record"){
        testJson();

    //Pas de commande
    }else{
        std::cout << "Error : command not found." << std::endl ;
    }
    
    std::cout << endl ;
    
    retVal = 0;
    return retVal;
}
