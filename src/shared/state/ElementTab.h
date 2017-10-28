// Generated by dia2code
#ifndef STATE__ELEMENTTAB__H
#define STATE__ELEMENTTAB__H

#include <vector>

namespace state {
  class Element;
}

#include "Element.h"

namespace state {

  /// class ElementTab - 
  class ElementTab {
    // Associations
    // Attributes
  protected:
    int w;
    int h;
    std::vector<Element*> tab;
    // Operations
  public:
    const Element* operator[] (int i) const;
    Element* operator[] (int i);
    // Setters and Getters
    int getW() const;
    void setW(int w);
    int getH() const;
    void setH(int h);
    const std::vector<Element*>& getTab() const;
    void setTab(const std::vector<Element*>& tab);
  };

};

#endif
