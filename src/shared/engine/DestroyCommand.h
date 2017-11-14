// Generated by dia2code
#ifndef ENGINE__DESTROYCOMMAND__H
#define ENGINE__DESTROYCOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
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
    CommandTypeId getTypeID () const;
    void execute (state::State& state);
    // Setters and Getters
    int getElementID() const;
    void setElementID(int elementID);
  };

};

#endif
