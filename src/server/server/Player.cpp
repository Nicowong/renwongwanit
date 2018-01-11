/** 
 * @file Player.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "Player.hpp"

using namespace server ;

Player::Player (string name, bool free) : name(name),free(free) {
    
}

const std::string& Player::getName () const{
	return name ;
}
