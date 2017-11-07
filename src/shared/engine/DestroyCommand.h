// Generated by dia2code
#ifndef ENGINE__DESTROYCOMMAND__H
#define ENGINE__DESTROYCOMMAND__H


namespace engine {
  class Command;
}

#include "Command.h"

namespace engine {

  /// class DestroyCommand - 
  class DestroyCommand : public engine::Command {
    // Attributes
  protected:
    int elementID;
    // Operations
  public:
    void DestroyCommand (int elementID);
    CommandTypeId const getTypeID ();
    void excute (state::State& state);
    // Setters and Getters
    int getElementID() const;
    void setElementID(int elementID);
  };

};

#endif
