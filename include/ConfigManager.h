#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>

class ConfigManager {
public:
    explicit ConfigManager(const std::string& configFile);
    std::string getSetting(const std::string& key, const std::string& defaultValue = "") const;

private:
    nlohmann::json configData;
    void loadConfig(const std::string& configFile);
};

#endif
