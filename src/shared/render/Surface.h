// Generated by dia2code
#ifndef RENDER__SURFACE__H
#define RENDER__SURFACE__H

#include <SFML/Graphics.hpp>
#include <string>

namespace sf {
  class VertexArray;
  class Texture;
};
namespace render {
  class Tile;
};
namespace sf {
  class Transformable;
  class Drawable;
};
namespace render {
  class TileSet;
}

#include "TileSet.h"

namespace render {

  /// class Surface - 
  class Surface : public sf::Transformable, public sf::Drawable {
    // Attributes
  protected:
    sf::VertexArray vertices;
    sf::Texture texture;
    // Operations
  public:
    /// init texture from filename
    /// @param fileName		(???) 
    void loadTexture (const std::string& fileName);
    /// init n (x4) vertices as quads
    /// @param n		(???) 
    void initVertices (int n);
    /// set i-th sprite location to be drawn at on surface (screen)
    /// @param i		(???) 
    /// @param x		(???) 
    /// @param y		(???) 
    void setSpriteLocation (int i, int x, int y);
    /// set sprite texture from rank (i), and tile information (x, y, w, h) on texture file
    /// @param i		(???) 
    /// @param tile		(???) 
    void setSpriteTexture (int i, const Tile& tile);
    /// draw all quads, textures
    /// @param target		(???) 
    /// @param states		(???) 
    void draw (sf::RenderTarget& target, sf::RenderStates states) const;
    // Setters and Getters
    const sf::VertexArray& getVertices() const;
    void setVertices(const sf::VertexArray& vertices);
    const sf::Texture& getTexture() const;
    void setTexture(const sf::Texture& texture);
  };

};

#endif
