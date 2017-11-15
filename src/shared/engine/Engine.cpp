#include <iostream>

#include "Engine.h"

using namespace std ;
using namespace engine ;

Engine::Engine (size_t w, size_t h): currentState(w,h){

}
Engine::Engine (string filename): currentState(filename){

}
Engine::~Engine (){

}
const state::State& Engine::getState () const{
	return currentState ;
}
void Engine::addCommand (int priority, Command* cmd){

}
void Engine::update (){

}
// Setters and Getters
const state::State& Engine::getCurrentState() const{
	return currentState ;
}
void Engine::setCurrentState(const state::State& currentState){
	this->currentState = currentState ;
}
const std::map<int,std::shared_ptr<Command>>& Engine::getCurrentCommands() const{
	return currentCommands ;
}
void Engine::setCurrentCommands(const std::map<int,std::shared_ptr<Command>>& currentCommands){
	this->currentCommands = currentCommands ;
}
