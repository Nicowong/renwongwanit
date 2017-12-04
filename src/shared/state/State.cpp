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
    victory = NONE ;
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
size_t State::countBuilding(Team player)const{
    size_t n=0 ;
    for(size_t i=0 ; i<cellTab.length() ; i++){
        if(cellTab[i]->isBuilding() && cellTab[i]->getTeam()==player)
            n++ ;
    }
    return n ;
}
size_t State::countUnit(Team player)const{
    size_t n=0 ;
    for(size_t i=0 ; i<cellTab.length() ; i++){
        if(cellTab[i]->isUnit() && cellTab[i]->getTeam()==player)
            n++ ;
    }
    return n ;
}

// GET ELEMENTTABs
ElementTab& State::getCellTab(){
    return cellTab ;
}
const ElementTab& State::getCellTab()const{
    return cellTab ;
}
void State::setCellTab(const ElementTab& cellTab){
    //illegal
}

ElementTab& State::getUnitTab(){
    return unitTab ;
}
const ElementTab& State::getUnitTab()const{
    return unitTab ;
}

//ERASE

void State::eraseUnit(size_t x, size_t y){
    unitTab.eraseElem(x, y);
}
void State::eraseUnit(Element* unit){
    unitTab.eraseElem(unit);
}
void State::eraseUnit(int i){
    unitTab.eraseElem(i);
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
    // illegal
}

void State::setUnitTab(const ElementTab& unitTab){
    // illegal
}

Team State::getVictory() const{
    return victory ;
}
void State::setVictory(Team victory){
    this->victory = victory ;
}

// DEBUG

void State::debug()const{
    cout << "w:"<<w<<" h:"<<h <<endl ;
    cout << "day:"<<day << " turn:Player" <<turn << endl ; 
    cout << "cellTab : "<<endl ;
    getCellTab().debug();
    cout << endl <<"unitTab : "<<endl ;
    getUnitTab().debug() ;
}
