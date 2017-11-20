#include <iostream>
#include "BoardLayer.h"

using namespace std ;
using namespace sf ;
using namespace state ;
using namespace render ;

void BoardLayer::update(const state::ElementTab* tab){
	sf::VertexArray vertices ;
	for(size_t j=0 ; j<tab->getH() ; j++){
		for(size_t i=0 ; i<tab->getW() ; i++){

		}
	}
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(12*4);
}