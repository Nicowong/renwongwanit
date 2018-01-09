 /*
 * @file GameDB.hpp                                                      
 * @author Philippe-Henri Gosselin                                       
 * @date 9 décembre 2015                                                 
 * @copyright CNRS                                                       
 */

#ifndef __Game_hpp__
#define __Game_hpp__

#include <memory>
#include <map>

using std::unique_ptr;
using std::map;

#include "ServiceException.hpp"
#include "Player.hpp"
#include "Game.h"

template<class T,typename ... Args>
std::unique_ptr<T> make_unique(Args ... args) {
    return std::unique_ptr<T>(new T(args ...));
}

#endif


