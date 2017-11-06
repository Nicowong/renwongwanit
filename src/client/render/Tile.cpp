#include "../shared/render/Tile.h"

using namespace std ;
using namespace render ;

Tile::Tile()
    : Tile(0,0,16,16){
}
Tile::Tile(int x, int y, int w, int h)
    : x(x), y(y), w(w), h(h) {
}
