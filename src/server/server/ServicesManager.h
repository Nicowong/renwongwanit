// Generated by dia2code
#ifndef SERVER__SERVICESMANAGER__H
#define SERVER__SERVICESMANAGER__H

#include <vector>
#include <memory>
#include <string>

namespace server {
  class AbstractService;
}

#include "AbstractService.h"

namespace server {

  /// class ServicesManager - 
  class ServicesManager {
    // Associations
    // Attributes
  protected:
    std::vector<std::unique_ptr<AbstractServices>> services;
    // Operations
  public:
    void registerService (std::unique_ptr<AbstractService> service);
    AbstractService* findService (const std::string& url) const;
    queryService (std::string& out, const std::string& in, const std::string& url, const std::string& method);
    // Setters and Getters
    const std::vector<std::unique_ptr<AbstractServices>>& getServices() const;
    void setServices(const std::vector<std::unique_ptr<AbstractServices>>& services);
  };

};

#endif
