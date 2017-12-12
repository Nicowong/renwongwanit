#include <iostream>

#include "Engine.h"
#include "AttackCommand.h"
#include "DestroyCommand.h"

using namespace std ;
using namespace engine ;

Engine::Engine (state::State& state): currentState(state){

}

Engine::~Engine (){
	currentCommands.clear();
}
const state::State& Engine::getState () const{
	return currentState ;
}
void Engine::addCommand (Command* cmd){
	lock_guard<mutex> lockg(engineMutex);
	currentCommands.push_back(cmd);
}
void Engine::update(){
	lock_guard<mutex> lockg(engineMutex);
	if(currentCommands.size()>0){
		Command* c = currentCommands[0];
		c->execute(currentState);
		if(c->getCommandTypeId() == COM_ATTACK){
			AttackCommand* ac = (AttackCommand*)c ;
			if(ac->getAttacker().getHealth() <= 0){
				DestroyCommand* d = new DestroyCommand(ac->getAttacker());
				d->execute(currentState);
				delete d ;
			}else if(ac->getDefender().getHealth() <= 0){
				DestroyCommand* d = new DestroyCommand(ac->getDefender());
				d->execute(currentState);
				delete d ;
			}
		}
		currentCommands.erase(currentCommands.begin());
	}else
		cout << "no command" << endl ;
}
// Setters and Getters
state::State& Engine::getCurrentState() const{
	return currentState ;
}
void Engine::setCurrentState(const state::State&& currentState){
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
	cout << "Command stack : " << endl;
	for(size_t i=0 ; i<currentCommands.size() ; i++)
		cout << currentCommands[i] << " " ;
	if(currentCommands.size()==0)
		cout << "empty" ;
	cout << endl ;
}
