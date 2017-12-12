#include "mapGeneration.h"

using namespace std ;
using namespace state ;
using namespace mapGeneration ;

namespace mapGeneration{

CellType* generateCellMap(int w, int h, string fname){ // generate random cellTypeMap
    CellType *tileMap = new CellType[w * h];
    
    for(int i=0 ; i<w ; i++)
        for(int j=0 ; j<h ; j++){
            tileMap[i + j*w] = generateCell() ; // plaine, foret, montagne, mer
        }
    
    for(int n=0 ; n<RDMAPGENITER ; n++){    //traitement de carte (homogeneisation)
        int x = rand()%w ; // selectionne une case
        int y = rand()%h ;
        
        if(rand()%100 < 60){ //prend la valeur d'un voisin, sinon rien
            int vx=x, vy=y ;
            if(rand()%2==0)
                vx += (rand()%2)*2 -1 ;
            else
                vy += (rand()%2)*2 -1 ;
            
            if(vx>=0 && vx<w && vy>=0 && vy<h)
                tileMap[vx + vy*w] = tileMap[x + y*w];
        }
        if(n%(RDMAPGENITER/10) == 0)
            cout << "." ;
    }
    
    cout << endl ;
    
    // placement de villes, routes
    do{
        int x = rand()%w ;
        int y = rand()%h ;
        tileMap[x+y*w] = generateBuilding(x, y, tileMap[x+y*w]) ;
        generateRoad(x, y, w, h, tileMap);
    }while(rand()%100 < 90);
    
    int x = rand()%w ; //placement du QG
    int y = rand()%h ;
    
    generateRoad(x, y, w, h, tileMap);
    tileMap[x+y*w] = CT_BASE ;
    
    if(fname != "NULL");
        saveMap(tileMap, w, h, fname);
    
    return tileMap ;
}

CellType generateCell(){    //generate a random cellType
    const int pG=40, pS=15, pM=15, pF=20 ;
    int ct = rand()%(pG+pS+pM+pF) ;
    if(ct < pG)
        return CT_PLAIN ;
    else if(ct < pG+pS)
        return CT_SEA ;
    else if(ct < pG+pS+pM)
        return CT_MOUNTAIN ;
    else
        return CT_FOREST ;
}

CellType generateBuilding(int x, int y, CellType ct){   //randomly generate building
    int r = rand()%100 ;
    if(ct==CT_SEA){
        if(r<80)
            return CT_SEAPORT ;
        else if(r<90)
            return CT_CITY ;
        else if(r<97)
            return CT_FACTORY ;
        else
            return CT_AIRPORT ;
    }else if(ct==CT_MOUNTAIN){
        if(r<80)
            return CT_AIRPORT ;
        else if(r<96)
            return CT_CITY ;
        else
            return CT_FACTORY ;
    }else{
        if(r<45)
            return CT_CITY ;
        else if(r<80)
            return CT_FACTORY ;
        else
            return CT_AIRPORT ;
    }
}

void generateRoad(int x, int y, int w, int h, CellType* map){   //make a road
    int dir = rand()%4 ;
    int r ;
    do{
        r = rand()%100 ;
        switch(dir){
            case 0 : if(r<50) x++ ; else if(r<70) y++ ; else if(r<90) y-- ; else x-- ; break ;
            case 1 : if(r<50) y++ ; else if(r<70) x++ ; else if(r<90) x-- ; else y-- ; break ;
            case 2 : if(r<50) x-- ; else if(r<70) y++ ; else if(r<90) y-- ; else x++ ; break ;
            case 3 : if(r<50) y-- ; else if(r<70) x++ ; else if(r<90) x-- ; else y++ ; break ;
            default : break ;
        }
            
        if(x<0 || y<0 || x>=w || y>=h)
            break;
            
        if(map[x+y*w]==CT_SEA)
            map[x+y*w]=CT_BRIDGE ;
        else
            map[x+y*w]=CT_ROAD ;
    }while(rand()%100<75);
    if(rand()%100 < 75)
        map[x+y*w] = generateBuilding(x,y,map[x+y*w]) ;
}

void saveMap(CellType *map, int w, int h, string fname){
    ofstream file;
    file.open(fname.c_str());
    file << w << "\n" << h << "\n" ;
    for(int j=0 ; j<h ; j++){
        for(int i=0 ; i<w ; i++){
            file << (int)map[i+j*w];
            if(i!=h-1)
                file<<" ";
        }
        file << "\n" ;
    }
    file.close();
}

void generateMap(State &state){     //convert CTMAP to ETab in state
    CellType* map = generateCellMap(state.getW(), state.getH(), "level.txt");
    ElementTab& ctab = state.getCellTab();
    for(size_t j=0 ; j<state.getH() ; j++){
        for(size_t i=0 ; i<state.getW() ; i++){
            Element *c = new Cell(map[i+j*state.getW()], i,j);
            //cout << c << " " ;
            //c->debug() ;
            ctab.addElem(c);
        }
    }
    delete[] map ;
}

void generateUnits(State &state){   // random units
    ElementTab& ctab = state.getCellTab();
    ElementTab& utab = state.getUnitTab();
    for(int j=0 ; j<(int)state.getH() ; j++)
        for(int i=0 ; i<(int)state.getW() ; i++)
            if(rand()%100 <= 15){
                Element* u ;
                int uteam = rand()%2+1 ;
                CellType ct = ((Cell*)ctab.getElem(i,j))->getCellType();
                if(ct==CT_MOUNTAIN || ct==CT_RIVER){
                    int ut = rand()%7;
                    if(ut>1) ut+=10 ;
                    u = new Unit(uteam, ut, i, j, true);
                }else if(ct==CT_SEA){
                    int ut = rand()%10 + 12 ;
                    u = new Unit(uteam, ut, i, j, true);
                }else{
                    int ut = rand()%17 ;
                    u = new Unit(uteam, ut, i, j, true);
                }
                utab.addElem(u);
            }
}

/*====== CONSTANT MAP GENERATED FOR COMMAND TESTS ======*/

CellType* generateTestMap(int w, int h, string fname){
    CellType *tileMap = new CellType[w * h];
    
    int j;
    for(int j=0 ; j<h-2 ; j++)
        for(int i=0 ; i<w ; i++)
            tileMap[i + j*w] = CT_PLAIN ; // plaine
    j=h-2 ;
    for(int i=0 ; i<w ; i++)
        tileMap[i + j*w] = CT_SEA ; // mer
    j=h-1 ;
    for(int i=0 ; i<w ; i++)
        tileMap[i + j*w] = CT_MOUNTAIN ; // montagne
    
    // placement de villes, routes
    tileMap[1+1*w] = CT_CITY ;
    tileMap[2+1*w] = CT_ROAD ;
    tileMap[2+2*w] = CT_BASE ;
    tileMap[2+3*w] = CT_ROAD ;
    tileMap[1+3*w] = CT_CITY ;
    tileMap[0+0*w] = CT_FOREST ;
    
    return tileMap ;
}

void generateTestMap(State &state){
    CellType* map = generateTestMap(state.getW(), state.getH(), "level.txt");
    ElementTab& ctab = state.getCellTab();
    for(size_t j=0 ; j<state.getH() ; j++){
        for(size_t i=0 ; i<state.getW() ; i++){
            Element *c ;
            if(i==2 && j==2)
                c = new Building(PLAYER1, CT_BASE, i, j);
            else
                c = new Cell(map[i+j*state.getW()], i,j);
            ctab.addElem(c);
        }
    }
}

void generateTestUnits(State &state){
    ElementTab& unitTab = state.getUnitTab();
    Unit* p1u1 = new Unit(PLAYER1, UT_INFANTRY, 1,0);
    Unit* p1u2 = new Unit(PLAYER1, UT_RECON, 0,1);
    Unit* p1u3 = new Unit(PLAYER1, UT_MISSILELAUNCHER, 0,4);
    Unit* p2u1 = new Unit(PLAYER2, UT_TANK, 5,2);
    Unit* p2u2 = new Unit(PLAYER2, UT_MECH, 4,3);
    Unit* p2u3 = new Unit(PLAYER2, UT_MEGATANK, 3,4);
    unitTab.addElem(p1u1);
    unitTab.addElem(p1u2);
    unitTab.addElem(p1u3);
    unitTab.addElem(p2u1);
    unitTab.addElem(p2u2);
    unitTab.addElem(p2u3);
}

};
