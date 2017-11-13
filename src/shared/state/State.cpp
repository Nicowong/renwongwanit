#include <iostream>

#include "../shared/state/State.h"

using namespace std ;
using namespace state ;

State::State(size_t width, size_t height): cellTab(width, height), unitTab(width, height){
    w = width ;
    h = height ;
    day = 1 ;
    turn = PLAYER1;
    Player p1(true, true);
    Player p2(true, true);
    players.push_back(p1);
    players.push_back(p2);
}
State::State (std::string levelFile){
    
}

void State::initCellTab(CellType* celltab){
    for(size_t j=0 ; j<h ; j++){
        for(size_t i=0 ; i<w ; i++){
            Cell *c = new Cell(celltab[i+j*w], i, j);
            this->cellTab.addElem(c);
        }
    }
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

void State::debug()const{
    cout << "State:: void debug()"<<endl ;
    cout << "w:"<<w<<" h:"<<h <<endl ;
    cout << "day:"<<day << "turn:Player" <<turn << endl ; 
    cout << "cellTab : "<<endl ;
    getCellTab().debug();
    cout << endl <<"unitTab : "<<endl ;
    getUnitTab().debug() ;
}