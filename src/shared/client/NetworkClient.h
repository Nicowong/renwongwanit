// Generated by dia2code
#ifndef CLIENT__NETWORKCLIENT__H
#define CLIENT__NETWORKCLIENT__H

#include <string>
#include <json/json.h>

namespace engine {
  class Engine;
}

#include "engine/Engine.h"

namespace client {

  /// class NetworkClient - 
  class NetworkClient {
    // Attributes
  private:
    std::string url;
    int port;
    engine::Engine engine;
    // Operations
  public:
    NetworkClient (const std::string& url, int port, int character);
    bool getServerCommands (Json::Value& out);
    void putServerCommand ( command engine::Command*);
    void run ();
    // Setters and Getters
  };

};

#endif
