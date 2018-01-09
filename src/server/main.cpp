#include <iostream>
#include <string>


//#include "state.h"

using namespace std;
//using namespace state;

/*fonctions de test unitaire*/
void testHello();
void testState(int test=0);
//void testRender(int mode=0, string fname="level.txt");
void testEngine();
void testRandom_ai();
void testHeuristic_ai();
void testRecord();
int testListen(int port=8080);

/*--- Fonction main ---*/

int main(int argc,char* argv[]) {
    int retVal = -1 ;
    
    // affichage de la liste des arguments
    for(int i=0 ; i<argc ; i++)
        std::cout << "argc = " << argc << " ; argv[" << i << "]: " << argv[i] << std::endl<<std::endl ;
    
    if(argc<2)
        return 2;
    string com(argv[1]);
    //commandes pour les tests unitaires
// --- test hello
    if(com=="hello"){
        testHello();
    }
// --- test state
    else if(com=="state"){
        if(argc > 2)
            testState(atoi(argv[2]));
        else
            testState(0x10);
    }
// test Engine
    else if(com=="engine"){
        testEngine();
    }
//--- AI pour les test d'ai
    else if(com=="random_ai"){
        testRandom_ai();
    }
//--- heuristic ai
    else if(com=="heuristic_ai"){
        testHeuristic_ai();
    }
    else if(com=="record"){
        testRecord();
    }
    else if(com=="listen"){
        retVal = testListen(8080);
    }
//Pas de commande
    else{
        std::cout << "Error : command not found." << std::endl ;
    }
    
    std::cout << endl ;
    
    retVal = 0;
    return retVal;
}
