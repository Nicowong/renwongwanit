// Generated by dia2code
#ifndef ENGINE__MOVECOMMAND__H
#define ENGINE__MOVECOMMAND__H

#include <stdlib.h>
#include <json/json.h>

namespace state {
  class Unit;
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class MoveCommand - 
  class MoveCommand : public engine::Command {
    // Attributes
  protected:
    state::Unit& unit;
    size_t x;
    size_t y;
    // Operations
  public:
    MoveCommand (state::Unit& unit, size_t x, size_t y);
    CommandTypeId getCommandTypeId ( ) const;
    void execute (state::State& state);
    void debug () const;
    Json::Value toJson () const;
    // Setters and Getters
    state::Unit& getUnit() const;
    void setUnit(const state::Unit&& unit);
    const size_t& getX() const;
    void setX(const size_t& x);
    const size_t& getY() const;
    void setY(const size_t& y);
  };

};

#endif
