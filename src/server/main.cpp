#include <iostream>
#include <string>



using namespace std;

/*fonctions de test unitaire*/
void testHello();
void testState();
//void testRender(int mode=0, string fname="level.txt");
void testEngine();
void testAi();

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
        #ifdef __CLIENT__
        cout << "CLIENT DEFINED : BUILD ERROR" << endl ;
        #else
        cout << "COMMAND 'render' UNAVAILABLE" << endl ;
        #endif
    //--- ENGINE pour les tests de moteur
    }
    else if(string(argv[1])=="engine"){
        testEngine();
    //--- AI pour les test d'ai
    }else if(string(argv[1])=="ai"){
        testAi();
    //Pas de commande
    }else{
        std::cout << "Error : command not found." << std::endl ;
    }
    
    std::cout << endl ;
    
    retVal = 0;
    return retVal;
}
