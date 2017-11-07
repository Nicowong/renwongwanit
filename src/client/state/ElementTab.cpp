#include <iostream>

#include "../shared/state/ElementTab.h"

using namespace std;
using namespace state;

ElementTab::ElementTab (size_t w, size_t h):
    w(w), h(h){
    elemTab.resize(w*h, nullptr);
}
//access index
size_t ElementTab::getTabIndex(size_t x, size_t y)const{
    return x+y*w ;
}
size_t ElementTab::getTabIndex(const Element* elem)const{
    return elem->getX()+elem->getY()*w ;
}
//modifiers and accessor to list
void ElementTab::addElem (Element* elem){
    if(elemTab[getTabIndex(elem)]==nullptr){
        elemList.push_back(elem);
        elemTab[getTabIndex(elem)] = elem ;
    }
    else
        std::cout << "ElementTab::addElem error : non-null element at " ;
        std::cout << elem->getX() << ":" << elem->getY() << std::endl ;
}
const Element* ElementTab::getElem (size_t i)const{
    if(i<elemList.size())
        return elemList[i];
    else
        return nullptr ;
}
Element* ElementTab::getElem (size_t i){
    if(i<elemList.size())
        return elemList[i];
    else
        return nullptr ;
}
const Element* ElementTab::operator[] (size_t i) const{
    if(i<elemList.size())
        return elemList[i];
    else
        return nullptr ;
}
Element* ElementTab::operator[] (size_t i){
    if(i<elemList.size())
        return elemList[i];
    else
        return nullptr ;
}
const Element* ElementTab::getElem (size_t x, size_t y) const{
    if(x>=0 && x<w && y>=0 && y<h)
        return elemTab[x+y*w];
    else{
        std::cout << "ElementTab::getElem error : out of map " ;
        std::cout << "x:"<<x<<" y:"<<y<<" w:"<<w<<" h:"<<h <<std::endl ;
        return nullptr ;
    }
}
Element* ElementTab::getElem (size_t x, size_t y){
    if(x>=0 && x<w && y>=0 && y<h)
        return elemTab[x+y*w];
    else{
        std::cout << "ElementTab::getElem error : out of map " ;
        std::cout << "x:"<<x<<" y:"<<y<<" w:"<<w<<" h:"<<h <<std::endl ;
        return nullptr ;
    }
}
void ElementTab::eraseElem (int i){
    Element *elem = getElem(i);
    if(elem != nullptr){
        elemTab[getTabIndex(elem)] = nullptr ;
        elemList.erase(elemList.begin()+i);
        delete elem ;
    }else
        std::cout << "ElementTab::eraseElem error : erasing null elem, i:"<<i<<std::endl ;
}
void ElementTab::eraseElem (size_t x, size_t y){
    Element *elem = getElem(x,y);
    if(elem != nullptr){
        elemTab[getTabIndex(elem)] = nullptr ;
        size_t i=0 ;
        while(i<elemList.size() && elemList[i]!=elem)
            i++ ;
        elemList.erase(elemList.begin()+i);
        delete elem ;
    }else
        std::cout << "ElementTab::eraseElem error : erasing null elem." ;
        std::cout << "x:"<<x<<",y:"<<y <<std::endl ;
}
void ElementTab::moveElem (size_t x1, size_t y1, size_t x2, size_t y2){
    Element *elem1 = getElem(x1,y1);
    if(elem1 != nullptr){
        elem1->setX(x2);
        elem1->setY(y2);
    }
    elemTab[getTabIndex(x2,y2)] = elem1 ;
    elemTab[getTabIndex(x1,y1)] = nullptr ;
}
// Setters and Getters
const size_t& ElementTab::getW() const{
    return w ;
}
void ElementTab::setW(const size_t& w){
    this->w = w ;
}
const size_t& ElementTab::getH() const{
    return h ;
}
void ElementTab::setH(const size_t& h){
    this->h = h ;
}
const std::vector<Element*>& ElementTab::getElemList() const{
    return elemList ;
}
const std::vector<Element*>& ElementTab::getElemTab() const{
    return elemTab ;
}
/*
void ElementTab::setElemTab(const std::vector<Element*>& elemTab){
    
}
void ElementTab::setElemList(const std::vector<Element*>& elemList){
    
}
*/
