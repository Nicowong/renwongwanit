// Generated by dia2code
#ifndef AI__PATHMAP__H
#define AI__PATHMAP__H

#include <vector>

namespace ai {
  class Point;
};
namespace state {
  class ElemetTab;
};
namespace ai {
  class CalculDistance;
}

#include "state/ElemetTab.h"
#include "Point.h"
#include "CalculDistance.h"

namespace ai {

  /// class PathMap - 
  class PathMap {
    // Attributes
  protected:
    int x;
    int y;
    std::vector<int> distancetab;
    // Operations
  public:
    int getDistance (const Point& point) const;
    void setDistance (const Point& point);
    const int* getDistaceTab () const;
    void init (state::ElementTab& element);
    void update (state::ElementTab& element);
    // Setters and Getters
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    const std::vector<int>& getDistancetab() const;
    void setDistancetab(const std::vector<int>& distancetab);
  };

};

#endif
