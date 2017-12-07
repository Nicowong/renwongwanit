#ifndef MAPGENERATION_H
#define MAPGENERATION_H

#include <iostream>
#include <fstream>
#include "state.h"

#define RDMAPGENITER 6000

using namespace std ;
using namespace state ;

namespace mapGeneration{
    CellType* generateMap(int w, int h, string fname = "level.txt");
    CellType generateCell();
    CellType generateBuilding(int x, int y, CellType ct);
    void generateRoad(int x, int y, int w, int h, CellType* map);
    void saveMap(CellType *map, int w, int h, string fname="level.txt");
    int* loadMap(string fname="level.txt");
    void generateMap(State &state);
    void generateUnits(State &state);
};

#endif 