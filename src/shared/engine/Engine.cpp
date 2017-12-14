#include <iostream>
#include <ctime>
#include <unistd.h>
#include <fstream>

#include "json/json.h"

#include "Engine.h"
#include "AttackCommand.h"
#include "DestroyCommand.h"
#include "MoveCommand.h"
#include "EndTurnCommand.h"

using namespace std ;
using namespace engine ;

Engine::Engine (state::State& state, bool rec): currentState(state), record(rec){
		engStatus = PAUSE ;
		if(record){
			ofs.open("replay.txt", ofstream::out | ofstream::trunc);
		}
}

Engine::~Engine (){
	currentCommands.clear();
	ofs.close();
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
		Command* com = currentCommands[0];
		Json::StyledStreamWriter writer;
		Json::Value root ;
	// attack type command
		if(com->getCommandTypeId() == COM_ATTACK){
			AttackCommand* c = (AttackCommand*)com ;

			root["CommandType"]   = "COM_ATTACK";
			root["Attacker"]["x"] = c->getAttacker().getX();
			root["Attacker"]["y"] = c->getAttacker().getY();
			root["Defender"]["x"] = c->getDefender().getX();
			root["Defender"]["y"] = c->getDefender().getY();

			c->execute(currentState);
			//counter attack
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
	// move type command
		}else if(com->getCommandTypeId() == COM_MOVE){
			MoveCommand* c = (MoveCommand*)com ;

			root["CommandType"]   = "COM_MOVE";
			root["Unit"]["x"] = c->getUnit().getX();
			root["Unit"]["y"] = c->getUnit().getY();
			root["x"] = c->getX();
			root["y"] = c->getY();
			c->execute(currentState);
	// end turn type command
		}else if(com->getCommandTypeId() == COM_ENDTURN){
			root["CommandType"]   = "COM_ENDTURN";
			com->execute(currentState);
		}else{
			com->execute(currentState);
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

void Engine::rollback (){

}
void Engine::rollbackAll (){

}
void Engine::run (){
    time_t prvt, now ;
    double dt=1.0/10.0 , dift ;
    cout << "Engine::run" << endl ;
	while(engStatus != QUIT){
	    time(&now);
	    dift = difftime(now, prvt);
		if(dift >= dt){
			if(engStatus == RUN && currentCommands.size()>0)
				update();
			else if(engStatus == RUNBACK){

			}
			//else Pause
			time(&prvt);
		}else{
			usleep((int)((dt-dift)*1000000));
		}
	}
	cout << "Engine quit" <<endl ;
}
void Engine::setStatus(EngineStatus flag){
	engStatus = flag ;
}

bool Engine::getRecord() const{
	return record ;
}
void Engine::setRecord(bool record){
	this->record = record ;
}