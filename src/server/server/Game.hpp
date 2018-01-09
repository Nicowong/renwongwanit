#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <map>

using std::unique_ptr;
using std::map;

#include "Game.hpp"
#include "Game.h"

template<class T,typename ... Args>
std::unique_ptr<T> make_unique(Args ... args) {
    return std::unique_ptr<T>(new T(args ...));
}

#endif /* GAME_HPP */

