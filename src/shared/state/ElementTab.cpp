#include <iostream>

#include "../shared/state/ElementTab.h"

using namespace std;
using namespace state;

ElementTab::ElementTab(): ElementTab(16,16){}
ElementTab::ElementTab (size_t w, size_t h):
    w(w), h(h), type(T_NONE){
    elemTab.resize(w*h, nullptr);
}
ElementTab::ElementTab (size_t w, size_t h, TypeId type):
    w(w), h(h), type(type){
    elemTab.resize(w*h, nullptr);
}
//access index
size_t ElementTab::getTabIndex(size_t x, size_t y)const{
    return x+y*w ;
}
size_t ElementTab::getTabIndex(const Element* elem)const{
    return elem->getX()+elem->getY()*w ;
}

void ElementTab::resize(size_t width, size_t height){
    for(size_t i=0 ; i<elemList.size() ; i++){
        if(elemList[i]->getX() >= width || elemList[i]->getY() >= height)
            eraseElem(i);
    }
    
    setW(width);
    setH(height);
}
//modifiers and accessor to list
void ElementTab::addElem (Element* elem){
    if(elem != nullptr && (elem->getX()<0 || elem->getX()>=w || elem->getY()<0 || elem->getY()>=h)){
        std::cout << "ElementTab::addElem error : added element out of map at " ;
        std::cout << elem->getX() << ":" << elem->getY() << std::endl ;
    }
    else if(elemTab[getTabIndex(elem)]!=nullptr){
        std::cout << "ElementTab::addElem error : non-null element at " ;
        std::cout << elem->getX() << ":" << elem->getY() << std::endl ;
    }
    else{
        //cout << "addElem"<< elem << endl ;
        elemList.push_back(elem);
        //cout << "(#0)"<< elemList[0]->getX() << endl ;
        elemTab[getTabIndex(elem)] = elem ;
    }
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
    if(x>=0 && x<w && y>=0 && y<h){
        //cout << "getelem " << elemTab[x+y*w] << endl ;
        return elemTab[x+y*w];
    }
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
        //elemList[i] = nullptr;
    }else{
        std::cout << "ElementTab::eraseElem error : erasing null elem, i:"<<i<<std::endl ;
    }
}
void ElementTab::eraseElem (size_t x, size_t y){
    Element *elem = getElem(x,y);
    if(elem != nullptr){
        //cout << "-debug-";
        delete elemTab[getTabIndex(elem)];
        elemTab[getTabIndex(elem)] = nullptr ;
        //cout << "-debug-";
        size_t i=0 ;
        while(i<elemList.size() && elemList[i]!=elem)
            i++ ;
        //cout << "-debug-";
        elemList[i] = nullptr ;
    }else{
        std::cout << "ElementTab::eraseElem error : erasing null elem." ;
        std::cout << "x:"<<x<<",y:"<<y <<std::endl ;
    }
}
void ElementTab::eraseElem(Element* elem){
    eraseElem(elem->getX(), elem->getY());
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
TypeId ElementTab::getType() const{
    return type ;
}
void ElementTab::setType(TypeId type){
    this->type = type ;
}
/*
void ElementTab::setElemTab(const std::vector<Element*>& elemTab){
    
}
void ElementTab::setElemList(const std::vector<Element*>& elemList){
    
}
*/

void ElementTab::debug()const{
    //cout << "ElementTab:: void debug()"<<endl ;
    //cout << "w:"<<w<<" h:"<<h <<endl ;
    /*
    cout << "elemList ("<< elemList.size()<< ") :" <<endl ;
    for(size_t i=0 ; i<elemList.size() ; i++){
        //cout<<"STEPHEN EST PASSE PAR LA"<<endl ;
        //cout<< elemList[i] ;
        cout<< elemList[i]->getType() << " ";
        if(elemTab[i]->isUnit())
            cout << ((Unit*)elemTab[i])->getUnitType() << "|" ;
        else
            cout << ((Cell*)elemTab[i])->getCellType() << "|" ;
    }
    cout << endl ;*/
    //cout << "elemTab"<< endl ;
    for(size_t j=0 ; j<h ; j++){
        for(size_t i=0 ; i<w ; i++)
            if(elemTab[i+j*w]!=nullptr){
                cout << elemTab[i+j*w]->getType() << "," ;
                if(elemTab[i+j*w]->isUnit())
                    cout << ((Unit*)elemTab[i+j*w])->getUnitType() << "|" ;
                else
                    cout << ((Cell*)elemTab[i+j*w])->getCellType() << "|" ;
            }else
                cout << "nul " ;
        cout << endl ;
    }
}

size_t ElementTab::length()const{
    return elemList.size();
}
