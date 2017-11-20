#include "Surface.h"

using namespace std ;
using namespace render ;

void Surface::loadTexture(const std::string& fileName){
    texture.loadFromFile(fileName);
}
void Surface::initVertices(int nTiles){
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(nTiles*4);
}
void Surface::setSpriteLocation(int i, int x, int y){
    vertices[i+0].position = sf::Vector2f( x   *16,  y   *16);
    vertices[i+1].position = sf::Vector2f((x+1)*16,  y   *16);
    vertices[i+2].position = sf::Vector2f((x+1)*16, (y+1)*16);
    vertices[i+3].position = sf::Vector2f( x   *16, (y+1)*16);
}
void Surface::setSpriteTexture(int i, const Tile& t){
    vertices[i+0].texCoords = sf::Vector2f( t.x   *t.w,  t.y   *t.h);
    vertices[i+1].texCoords = sf::Vector2f((t.x+1)*t.w,  t.y   *t.h);
    vertices[i+2].texCoords = sf::Vector2f((t.x+1)*t.w, (t.y+1)*t.h);
    vertices[i+3].texCoords = sf::Vector2f( t.x   *t.w, (t.y+1)*t.h);
}
void Surface::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
    states.texture = &texture ;
    target.draw(vertices, states);
}

const sf::VertexArray& Surface::getVertices() const{
    return vertices ;
}
void Surface::setVertices(const sf::VertexArray& vertices){
    this->vertices = vertices ;
}
const sf::Texture& Surface::getTexture() const{
    return texture ;
}
void Surface::setTexture(const sf::Texture& texture){
    this->texture = texture ;
}