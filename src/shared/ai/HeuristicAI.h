// Generated by dia2code
#ifndef AI__HEURISTICAI__H
#define AI__HEURISTICAI__H


namespace ai {
  class PathMap;
};
namespace engine {
  class Engine;
};
namespace state {
  class Element;
};
namespace ai {
  class Ai;
}

#include "PathMap.h"
#include "Ai.h"
#include "state/Element.h"

namespace ai {

  /// class HeuristicAI - 
  class HeuristicAI : public ai::Ai {
    // Associations
    // Attributes
  protected:
    PathMap unitMap;
    PathMap cellMap;
    // Operations
  public:
    const PathMap& getUnitMap () const;
    const PathMap& getCellMap () const;
    /// 	
    /// @param engine		(???) 
    /// @param selected		(???) 
    void run (engine::Engine& engine, state::Element& selected);
    // Setters and Getters
    void setUnitMap(const PathMap& unitMap);
    void setCellMap(const PathMap& cellMap);
  };

};

#endif