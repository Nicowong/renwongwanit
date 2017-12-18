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
using namespace state ;
using namespace engine ;

Engine::Engine (state::State& state, bool rec): currentState(state), record(rec){
		engStatus = PAUSE ;
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
	// attack type command
		if(c->getCommandTypeId() == COM_ATTACK){
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
		}else if(c->getCommandTypeId() == COM_MOVE){
			c->execute(currentState);
	// end turn type command
		}else if(c->getCommandTypeId() == COM_ENDTURN){
			c->execute(currentState);
		}else{
			c->execute(currentState);
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
	if(!record){
		usleep(1500000);
		time_t prvt, now ;
	    double dt=1.0/10.0 , dift ;

	    cout << "Engine::run" << endl ;
		while(engStatus != QUIT){
		    time(&now);
		    dift = difftime(now, prvt);
			if(dift >= dt){
				if(engStatus == RUN && currentCommands.size()>0)
					update();
				else if(engStatus == RUNBACK){}
				//else Pause
				time(&prvt);
			}else{
				usleep((int)((dt-dift)*1000000));
			}
		}
		cout << "Engine quit" <<endl ;

	}else{ // record
		time_t prvt, now ;
	    double dt=1.0/10.0 , dift ;

	    ofstream ofs("replay.txt", ofstream::out | ofstream::trunc);
	    
		Json::StyledStreamWriter writer;
		State& state = getCurrentState();
		ElementTab& ctab = state.getCellTab();
		ctab.debug();
		ElementTab& utab = state.getUnitTab();
		Json::Value JState ;
		size_t w = state.getW();
		JState["w"]=w;
		JState["h"]=state.getH();
		for(size_t j=0 ; j<state.getH(); j++)
			for(size_t i=0 ; i<w ; i++){
				Cell* c = (Cell*)(ctab.getElem(i,j));
				JState["ctab"][i+j*w]["ctype"] = c->getCellType();
				if(c->getCellType()>=7){
					Building* b = (Building*)c ;
					JState["ctab"][i+j*w]["team"]= b->getTeam();
					JState["ctab"][i+j*w]["cp"]= b->getCapturePoints();
				}

				Unit* u = (Unit*)utab.getElem(i,j);
				if(u == nullptr)
					JState["utab"][i+j*w]["empty"] = true;
				else{
					JState["utab"][i+j*w]["empty"] = false;
					JState["utab"][i+j*w]["utype"] = u->getUnitType();
					JState["utab"][i+j*w]["team"] = u->getTeam();
					JState["utab"][i+j*w]["health"] = u->getHealth();
					JState["utab"][i+j*w]["ammo"] = u->getAmmo();
				}
			}
		writer.write(ofs, JState);

	    cout << "Engine::run" << endl ;
		while(engStatus != QUIT){
		    time(&now);
		    dift = difftime(now, prvt);
			if(dift >= dt){
				if(engStatus == RUN && currentCommands.size()>0){
					Json::Value root ;
					Command *com = currentCommands[0];
					switch(com->getCommandTypeId()){
						case COM_ATTACK :
						{
							AttackCommand *ac = (AttackCommand*)com ;
							root["CommandType"]   = "COM_ATTACK";
							root["Attacker"]["x"] = ac->getAttacker().getX();
							root["Attacker"]["y"] = ac->getAttacker().getY();
							root["Defender"]["x"] = ac->getDefender().getX();
							root["Defender"]["y"] = ac->getDefender().getY();
						}
							break ;
						case COM_MOVE :
						{
							MoveCommand* mc = (MoveCommand*)com ;
							root["CommandType"]   = "COM_MOVE";
							root["Unit"]["x"] = mc->getUnit().getX();
							root["Unit"]["y"] = mc->getUnit().getY();
							root["x"] = mc->getX();
							root["y"] = mc->getY();
						}
							break ;
						case COM_ENDTURN :
							root["CommandType"]   = "COM_ENDTURN";
							break ;
						default :
							break ;
					}
					writer.write(ofs, root);

					update();
				}
				else if(engStatus == RUNBACK){

				}
				//else Pause
				time(&prvt);
			}else{
				usleep((int)((dt-dift)*1000000));
			}
		}

		ofs.close();
		cout << "Engine quit" <<endl ;
	}
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