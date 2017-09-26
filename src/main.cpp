#include <cstdlib>
#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"

#include "definitions.h"

using namespace std;
//using namespace state;

int main(int argc,char* argv[]) 
{
    Exemple exemple;
    exemple.setX(53);

    cout << "It works !" << endl;
    cout << "Bonjour le monde ! src/main.cpp" << endl;

    return 0;
}
