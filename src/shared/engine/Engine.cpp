#include <iostream>

#include "Engine.h"

using namespace std ;
using namespace engine ;

Engine::Engine (size_t w, size_t h): currentState(w,h){

}
Engine::Engine (string filename): currentState(filename){

}
Engine::~Engine (){
	currentCommands.clear();
}
const state::State& Engine::getState () const{
	return currentState ;
}
void Engine::addCommand (Command* cmd){
	currentCommands.push_back(cmd);
}
void Engine::update(){
	if(currentCommands.size()>0){
		Command* c = currentCommands[0];
		c->execute(currentState);
		currentCommands.erase(currentCommands.begin());
	}else
		cout << "no command" << endl ;
}
// Setters and Getters
const state::State& Engine::getCurrentState() const{
	return currentState ;
}
void Engine::setCurrentState(const state::State& currentState){
	this->currentState = currentState ;
}
const std::vector<Command*>& Engine::getCurrentCommands() const{
	return currentCommands ;
}
void Engine::setCurrentCommands(const std::vector<Command*>& currentCommands){
	this->currentCommands = currentCommands ;
}

void Engine::debug()const{
	cout << "Engine::debug() :" << endl ;
	currentState.debug() ;
	cout << endl ;
	for(size_t i=0 ; i<currentCommands.size() ; i++){
		cout << currentCommands[i] << " " ;
	}
	cout << endl ;
}
