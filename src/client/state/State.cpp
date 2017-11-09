#include <iostream>

#include "../shared/state/State.h"

using namespace std ;
using namespace state ;

State::State(size_t width, size_t height): cellTab(width, height), unitTab(width, height){
    
}
State::State (std::string levelFile){
    
}
void State::dayIncr (){
    day++;
}
void State::turnIncr (){
    if(turn == PLAYER2){
        turn = PLAYER1 ;
        dayIncr();
    }else if(turn == PLAYER1){
        turn = PLAYER2 ;
    }else{
        cout << "State::turnIncr error : turn=" << turn << endl ;
    }
}
/*
const std::vector<state::Cell*> State::getCellLayer () const{
    
}
const std::vector<state::Unit*> State::getUnitLayer () const{
    
}
*/
// Setters and Getters
const size_t& State::getW() const{
    return w ;
}
void setW(const size_t& w){
    
}
const size_t& State::getH() const{
    return h ;
}
void State::setH(const size_t& h){
    
}
int State::getDay() const{
    return day ;
}
void State::setDay(int day){
    
}
Team State::getTurn() const{
    return turn ;
}
void State::setTurn(Team turn){
    
}
const std::vector<Player>& State::getPlayers() const{
    return players ;
}
void State::setPlayers(const std::vector<Player>& players){
    
}
const ElementTab& State::getCellTab() const{
    return cellTab ;
}
void State::setCellTab(const ElementTab& cellTab){
    
}
const ElementTab& State::getUnitTab() const{
    return unitTab ;
}
void State::setUnitTab(const ElementTab& unitTab){
    
}
