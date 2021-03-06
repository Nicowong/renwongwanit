#include "rules.h"

extern const int dmgRule[22*22]={
     40, 35, 20, 15,  7,  5,  2, 20, 25, 30, 30, 15, 20, 20,  0,  0,  0,  0,  0,  0,  0,  0,
     50, 40, 40, 40, 20, 15,  8, 40, 40, 40, 40, 40, 25, 25,  0,  0,  0,  0,  0,  0,  0,  0,
     60, 58, 40, 20, 10,  7,  5, 28, 32, 35, 35, 20, 30, 30,  0,  0,  0,  0,  0,  0,  0,  0,
     70, 60, 70, 40, 25, 18, 12, 60, 65, 68, 68, 60, 38, 35,  0,  0,  0, 15, 11,  9,  7,  7,
    110, 95, 90, 64, 40, 30, 20, 93, 85, 90, 90, 80, 44, 40,  0,  0,  0, 18, 14, 12, 10, 10,
    120,110,102, 98, 60, 40, 30,120,115,120,120,115, 70, 65,  0,  0,  0, 27, 23, 17, 14, 14,
    130,120,115,110, 80, 60, 40,140,135,140,140,130, 80, 75,  0,  0,  0, 30, 25, 20, 20, 20,
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     75, 70, 70, 60, 48, 42, 33, 70, 68, 70, 70, 66,  0,  0,  0,  0,  0, 80, 60, 70, 38, 45,
     82, 78, 80, 80, 50, 40, 30, 80, 80, 80, 80, 80,  0,  0,  0,  0,  0,100, 80,100, 44, 50,
	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,130,128,102,105,100,  0,  0,  0,  0,  0,
	110,102, 66, 33, 12,  9,  5, 40, 43, 45, 45, 44,144,134,104,115,108,  0,  0,  0,  0,  0,
	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 80, 76, 82, 78, 33, 22, 14, 80, 80, 80, 80, 34,110, 70,  0,  0,  0, 80, 40, 30, 35, 30,
	 60, 55, 25, 20, 12, 10,  7, 24, 24, 22, 22, 18,115,110, 70, 80, 66,  0,  0,  0,  0,  0,
	124,105,110,100, 75, 68, 55,105,108,110,110,105,  0,  0,  0,  0,  0,110, 80,100, 70, 70,
	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,134,130,110,115, 88,  0,  0,  0,  0,  0,
	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,120,117, 80, 88, 82,  0,  0,105,  0,  0,
	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,110, 33, 45, 66, 70,
	  85, 80, 82, 82, 53, 43, 33, 83, 83, 83, 83, 83,  0,  0,  0,  0,  0,102, 83,102, 45, 52,
	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 66, 51, 34, 25, 22,  0,  0,  0,  0,  0
    };

extern const int maxRangeRule[22] = {
	  1,  1,  1,  1,  1,  1,  1,  0,  3,  5,  6,  1,  0,  1,  1,  1,  1,  0,  1,  1,  5,  0
};
extern const int minRangeRule[22] = {
	  1,  1,  1,  1,  1,  1,  1,  0,  2,  3,  3,  1,  0,  1,  1,  1,  1,  0,  1,  1,  2,  0
};

extern const int moveRangeRule[22]={
	  3,  2,  8,  7,  6,  6,  5,  7,  6,  6,  6,  7,  7,  7,  7,  9,  8,  7,  7,  6,  6,  5
};
