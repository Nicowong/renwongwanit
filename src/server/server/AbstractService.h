// Generated by dia2code
#ifndef SERVER__ABSTRACTSERVICE__H
#define SERVER__ABSTRACTSERVICE__H

#include <string>
#include <json/json.h>

#include "HttpStatus.h"

namespace server {

  /// class AbstractService - 
  class AbstractService {
    // Attributes
  protected:
    std::string pattern;
    // Operations
  public:
    AbstractService (const std::string& pattern);
    ~AbstractService ();
    virtual HttpStatus get (Json::Value& out, int id) const;
    virtual HttpStatus post (const Json::Value& in, int id);
    virtual HttpStatus put (Json::Value& out, const Json::Value& in);
    virtual HttpStatus remove (int id);
    // Setters and Getters
    const std::string& getPattern() const;
    void setPattern(const std::string& pattern);
  };

};

#endif
