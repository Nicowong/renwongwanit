// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H

#include <stdlib.h>

#include "TypeId.h"
#include "Team.h"

namespace state {

  /// class Element - 
  class Element {
    // Associations
    // Attributes
  protected:
    TypeId type;
    Team team     = NONE;
    size_t x     = 0;
    size_t y     = 0;
    // Operations
  public:
    Element (TypeId type, Team team = NONE, size_t x = 0, size_t y = 0);
    bool isUnit () const;
    bool isBuilding () const;
    void debug () const;
    // Setters and Getters
    TypeId getType() const;
    void setType(TypeId type);
    Team getTeam() const;
    void setTeam(Team team);
    const size_t& getX() const;
    void setX(const size_t& x);
    const size_t& getY() const;
    void setY(const size_t& y);
  };

};

#endif
