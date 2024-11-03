#include "ConfigManager.h"
#include <fstream>
#include <nlohmann/json.hpp>

ConfigManager::ConfigManager(const std::string& configFile) {
    loadConfig(configFile);
}

void ConfigManager::loadConfig(const std::string& configFile) {
    std::ifstream file(configFile);
    if (file.is_open()) {
        file >> configData;
    }
}

std::string ConfigManager::getSetting(const std::string& key, const std::string& defaultValue) const {
    return configData.value(key, defaultValue);
}
