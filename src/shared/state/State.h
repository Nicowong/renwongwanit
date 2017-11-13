// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H

#include <stdlib.h>
#include <vector>
#include <string>

namespace state {
  class Player;
  class ElementTab;
  class Cell;
}

#include "Team.h"
#include "Player.h"
#include "ElementTab.h"
#include "CellType.h"
#include "Cell.h"

namespace state {

  /// class State - 
  class State {
    // Associations
    // Attributes
  protected:
    size_t w;
    size_t h;
    int day     = 0;
    Team turn     = PLAYER1;
    std::vector<Player> players;
    ElementTab cellTab;
    ElementTab unitTab;
    // Operations
  public:
    State (size_t width, size_t height);
    State (std::string levelFile);
    void initCellTab (CellType* celltab);
    void dayIncr ();
    void turnIncr ();
    void debug () const;
    size_t countBuilding (Team player) const;
    size_t countUnit (Team player) const;
    ElementTab& getCellTab ();
    const ElementTab& getCellTab () const;
    ElementTab& getUnitTab ();
    const ElementTab& getUnitTab () const;
    // Setters and Getters
    const size_t& getW() const;
    void setW(const size_t& w);
    const size_t& getH() const;
    void setH(const size_t& h);
    int getDay() const;
    void setDay(int day);
    Team getTurn() const;
    void setTurn(Team turn);
    const std::vector<Player>& getPlayers() const;
    void setPlayers(const std::vector<Player>& players);
    void setCellTab(const ElementTab& cellTab);
    void setUnitTab(const ElementTab& unitTab);
  };

};

#endif
