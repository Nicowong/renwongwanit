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

// ------------ TEST STATE ---------------
void testState(){
    testUnit();
    std::cout << "-------------------------" <<std::endl;
    testBuilding();
    std::cout << "-------------------------" <<std::endl;
    testCell();
}

/*--- implementation ---*/
void unitShow(const Unit& unit){
    std::cout<< std::endl ;
    std::cout<< "type : " << unit.getUnitType() << std::endl ;
    std::cout<< "team : " << unit.getUnitTeam() << std::endl ;
    std::cout<< "x : " << unit.getX() << " ; y : " << unit.getY() << std::endl ;
    std::cout<< "health : " << unit.getHealth() << " ; ammo : " << unit.getAmmo() << std::endl;
    std::cout<< "fuel : " << unit.getFuel() << " ; vision : " << unit.getVision() << std::endl ;
}
void buildingShow(const Building& b){
    std::cout<< std::endl ;
    std::cout<< "type : " << b.getBuildingType() << std::endl ;
    std::cout<< "team : " << b.getBuildingTeam() << std::endl ;
    std::cout<< "x : " << b.getX() << " ; y : " << b.getY() << std::endl ;
    std::cout<< "capture : " << b.getCapturePoints() << std::endl;
}
void cellShow(const Cell& cell){
    std::cout<<std::endl;
    std::cout<<"type : "<<cell.getCellType()<<std::endl;
    std::cout<< "x : " << cell.getX() << " ; y : " << cell.getY() << std::endl ;
}
  
void testUnit(){
    std::cout<< "Creation de Unit par defaut."<< std::endl ;
    Unit unit ;
    unitShow(unit);
    
    std::cout<< std::endl << "Changement de valeurs attribut."<<std::endl ;
    unit.setX(10);
    unit.setY(12);
    unit.setAmmo(50);
    unit.setFuel(25);
    unit.setUnitTeam(UT_PLAYER2);
    unit.setUnitType(UT_RECON);
    unit.setVision(4);
    unitShow(unit);
    
    std::cout<< std::endl << "Creation de Unit de type INFANTRY."<<std::endl ;
    Unit unitInf(3,4, UT_INFANTRY, UT_PLAYER2);
    unitShow(unitInf);
    std::cout<< std::endl << "Creation de Unit de type MECH."<<std::endl ;
    Unit unitMech(5,6, UT_MECH, UT_PLAYER1);
    unitShow(unitMech);
    std::cout<< std::endl << "Creation de Unit de type RECON."<<std::endl ;
    Unit unitRecon(7,8, UT_RECON, UT_PLAYER2);
    unitShow(unitRecon);
}

void testBuilding(){
    std::cout << "Creation de Building par defaut" << std::endl ;
    Building b1 ;
    buildingShow(b1);
    
    std::cout<< "Changement d'attribut" << endl << endl;
    
    b1.setX(1);
    b1.setY(2);
    b1.setCapturePoints(10);
    b1.setBuildingTeam(BT_PLAYER1);
    b1.setBuildingType(BT_BASE);
    buildingShow(b1);
}
void testCell(){
    std::cout<<"Creation de Cell par defaut"<<std::endl;
    Cell cell;
    
    Building b2;
    b2.setX(1);
    b2.setY(2);
    b2.setCapturePoints(10);
    b2.setBuildingTeam(BT_PLAYER1);
    b2.setBuildingType(BT_BASE);
   
        
    Unit unit;
    unit.setX(10);
    unit.setY(12);
    unit.setAmmo(50);
    unit.setFuel(25);
    unit.setUnitTeam(UT_PLAYER2);
    unit.setUnitType(UT_RECON);
    unit.setVision(4);
    
    //show data of unit and building 
    unitShow(unit);
    std::cout<<"-------------------------"<<std::endl;
    buildingShow(b2);
    std::cout<<"-------------------------"<<std::endl;
    
    cell.setBuilding(&b2);
    cell.setCellType(CT_FOREST);
    cell.setUnit(&unit);
    cell.setX(11);
    cell.setY(5);
    cellShow(cell);
    
}