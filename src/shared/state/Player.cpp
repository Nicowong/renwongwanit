#include <iostream>

#include "../shared/state/Player.h"

using namespace std;
using namespace state;

Player::Player(bool wBase, bool wUnit): money(0), startWithBase(wBase), startWithUnit(wUnit){
    
}
void Player::modifMoney (int mod){
    money+=mod ;
}
// Setters and Getters
int Player::getMoney() const{
    return money ;
}
void Player::setMoney(int money){
    this->money = money ;
}
bool Player::getStartWithBase() const{
    return startWithBase ;
}
void Player::setStartWithBase(bool startWithBase){
    cout << "PLayer::SetStartWithBase : forbidden access (read only attribute)";
}
bool Player::getStartWithUnit() const{
    return startWithUnit ;
}
void Player::setStartWithUnit(bool startWithUnit){
    cout << "PLayer::SetStartWithUnit : forbidden access (read only attribute)";
}
    