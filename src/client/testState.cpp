#include <iostream>
#include "state.h"

using namespace std ;
using namespace state ;

/*--- Prototype des fonctions de test state ---*/
void testUnit();
void unitShow(const Unit& unit);
void testBuilding();
void buildingShow(const Building& b);
void testCell();
void cellShow(const Cell& c);
void testElementTab();

// ------------ TEST STATE ---------------
void testState(){
    testUnit();
    std::cout << "-------------------------" <<std::endl;
    testBuilding();
    std::cout << "-------------------------" <<std::endl;
    testCell();
    std::cout << "-------------------------" <<std::endl;
    testElementTab() ;
    
}

/*--- implementation ---*/
/*
void unitShow(const Unit& unit){
    std::cout<< std::endl ;
    std::cout<< "type : " << unit.getUnitType() << std::endl ;
    std::cout<< "team : " << unit.getTeam() << std::endl ;
    std::cout<< "x : " << unit.getX() << " ; y : " << unit.getY() << std::endl ;
    std::cout<< "health : " << unit.getHealth() << " ; ammo : " << unit.getAmmo() << std::endl;
    std::cout<< "fuel : " << unit.getFuel() << " ; vision : " << unit.getVision() << std::endl ;
}
void buildingShow(const Building& b){
    std::cout<< std::endl ;
    std::cout<< "type : " << b.getCellType() << std::endl ;
    std::cout<< "team : " << b.getTeam() << std::endl ;
    std::cout<< "x : " << b.getX() << " ; y : " << b.getY() << std::endl ;
    std::cout<< "capture : " << b.getCapturePoints() << std::endl;
}
void cellShow(const Cell& cell){
    std::cout<<std::endl;
    std::cout<<"type : "<<cell.getCellType()<<std::endl;
    std::cout<< "x : " << cell.getX() << " ; y : " << cell.getY() << std::endl ;
}
*/

void testUnit(){
    std::cout<< "Creation de Unit par defaut."<< std::endl ;
    Unit unit ;
    unit.debug();
    //unitShow(unit);
    
    std::cout<< std::endl << "Changement de valeurs attribut."<<std::endl ;
    unit.setX(10);
    unit.setY(12);
    unit.setAmmo(50);
    unit.setFuel(25);
    unit.setTeam(PLAYER2);
    unit.setUnitType(UT_RECON);
    unit.setVision(4);
    unit.debug();
    //unitShow(unit);
    
    std::cout<< std::endl << "Creation de Unit de type INFANTRY."<<std::endl ;
    Unit unitInf(PLAYER2, UT_INFANTRY, 3,4);
    unitInf.debug();
    //unitShow(unitInf);
    std::cout<< std::endl << "Creation de Unit de type MECH."<<std::endl ;
    Unit unitMech(PLAYER1, UT_MECH, 5,6);
    unitMech.debug();
    //unitShow(unitMech);
    std::cout<< std::endl << "Creation de Unit de type RECON."<<std::endl ;
    Unit unitRecon(PLAYER2, UT_RECON, 7,8);
    unitRecon.debug();
    //unitShow(unitRecon);
}

void testBuilding(){
    std::cout << "Creation de Building par defaut" << std::endl ;
    Building b1 ;
    b1.debug();
    //buildingShow(b1);
    
    std::cout<< "Changement d'attribut" << endl << endl;
    
    b1.setX(1);
    b1.setY(2);
    b1.setCapturePoints(10);
    b1.setTeam(PLAYER1);
    b1.setCellType(CT_BASE);
    b1.debug();
    //buildingShow(b1);
}
void testCell(){
    std::cout<<"Creation de Cell par defaut"<<std::endl;
    Cell cell;
    
    cell.setX(11);
    cell.setY(5);
    cell.debug();
    //cellShow(cell);
    
}
void testElementTab(){
    cout << "Creation de ElementTab(20,30)"<<endl ;
    ElementTab etab(16,8);
    etab.debug();
    
    cout << "ajout unite" << endl ;
    Unit u1(PLAYER1, UT_RECON, 6, 4);
    Building b1(PLAYER2, CT_BASE, 2,7);
    Cell c1(CT_PLAIN, 7,7);
    etab.addElem(&u1);
    etab.addElem(&b1);
    etab.addElem(&c1);
    etab.debug();
    
    cout << "suppression" << endl ;
    etab.eraseElem(1);
    etab.debug();
}