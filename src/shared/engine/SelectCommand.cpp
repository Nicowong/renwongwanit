/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "SelectCommand.h"

using namespace std ;
using namespace state;
using namespace engine;

SelectCommand::SelectCommand (state::Element& elem): elem(elem){

    std::cout<< "Selected : " ;
    elem.debug();
    cout << endl ;
}
CommandTypeId SelectCommand::getCommandTypeId () const{
	return COM_SELECT ;
}
void SelectCommand::execute (state::State& state){

}
// Setters and Getters
state::Element& SelectCommand::getElem() const{
	return elem ;
}
void SelectCommand::setElem(const state::Element&& elem){
	this->elem = elem ;
}