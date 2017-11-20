// Generated by dia2code
#ifndef RENDER__LAYER__H
#define RENDER__LAYER__H

#include <string>
#include <SFML/Graphics.hpp>

namespace render {
  class Surface;
  class TileSet;
};
namespace sf {
  class RenderWindow;
}

#include "Surface.h"
#include "TileSet.h"

namespace render {

  /// class Layer - 
  class Layer {
    // Associations
    // Attributes
  protected:
    Surface* surface;
    TileSet* tileSet;
    // Operations
  public:
    Layer (Surface* surface, TileSet* tileSet);
    Layer ();
    Surface* getSurface () const;
    void setSurface (Surface* surface);
    void print (int x, int y, std::string text);
    void draw (sf::RenderWindow& window);
    TileSet* getTileSet () const;
    void setTileSet (TileSet* tileSet);
    // Setters and Getters
  };

};

#endif
