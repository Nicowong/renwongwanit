// Generated by dia2code
#ifndef ENGINE__MOVECOMMAND__H
#define ENGINE__MOVECOMMAND__H


namespace engine {
  class Command;
}

#include "Command.h"

namespace engine {

  /// class MoveCommand - 
  class MoveCommand : public engine::Command {
    // Attributes
  protected:
    int elementID;
    // Operations
  public:
    void MoveCommand (int elementId);
    CommandTypeId const getTypeId ( );
    void excute (state::State& state);
    // Setters and Getters
    int getElementID() const;
    void setElementID(int elementID);
  };

};

#endif