// Generated by dia2code
#ifndef STATE__PLAYER__H
#define STATE__PLAYER__H


namespace state {
  class ElementTab;
}

#include "ElementTab.h"

namespace state {

  /// class Player - 
  class Player {
    // Associations
    // Attributes
  protected:
    ElementTab* unitTab;
    int money;
    // Setters and Getters
    const ElementTab*& getUnitTab() const;
    void setUnitTab(const ElementTab*& unitTab);
    int getMoney() const;
    void setMoney(int money);
  };

};

#endif
