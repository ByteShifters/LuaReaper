#include "LuaInterface.h"
#include "ConfigManager.h"
#include <iostream>

int main(int argc, char* argv[]) {
    ConfigManager config("config/dumper_config.json");

    std::string logLevel = config.getSetting("log_level", "INFO");
    std::string outputDirectory = config.getSetting("output_directory", "./");

    if (argc < 2) {
        Logger::log(Logger::LogLevel::ERROR, "Usage: LuaBytecodeDumper <script.lua>");
        return 1;
    }

    LuaInterface luaInterface(outputDirectory);

    for (int i = 1; i < argc; ++i) {
        std::string script = argv[i];
        luaInterface.loadScript(script);
        luaInterface.dumpScript(script);
    }

    return 0;
}
