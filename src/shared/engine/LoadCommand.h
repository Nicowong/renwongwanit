// Generated by dia2code
#ifndef ENGINE__LOADCOMMAND__H
#define ENGINE__LOADCOMMAND__H


namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "Command.h"

namespace engine {

  /// class LoadCommand - 
  class LoadCommand : public engine::Command {
    // Attributes
  protected:
     character;
    // Operations
  public:
    void loadCommand (const char* charactor);
    CommandTypeId const getTypeID ();
    void excute (state::State& state);
    // Setters and Getters
    const & getCharacter() const;
    void setCharacter(const & character);
  };

};

#endif
