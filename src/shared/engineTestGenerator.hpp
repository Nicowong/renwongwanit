#ifndef __engineTestGenerator_hpp__
#define __engineTestGenerator_hpp__

#include "state.h"

using namespace std ;
using namespace state ;

namespace engineTest{
	CellType* generateMap(int w, int h, string fname = "level.txt");
	void generateMap(State &state);
	void generateUnits(State &state);
};

#endif 
