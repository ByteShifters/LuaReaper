#include "LuaDumper.h"
#include <fstream>
#include <iostream>

LuaDumper::LuaDumper(lua_State* luaState, const std::string& outputDir) 
    : L(luaState), outputDirectory(outputDir) {}

bool LuaDumper::dump(const std::string& scriptPath) {
    Logger::log(Logger::LogLevel::INFO, "Attempting to dump bytecode for script: " + scriptPath);
    
    if (luaL_loadfile(L, scriptPath.c_str()) != LUA_OK) {
        Logger::log(Logger::LogLevel::ERROR, "Failed to load script: " + scriptPath);
        Logger::log(Logger::LogLevel::ERROR, lua_tostring(L, -1));
        lua_pop(L, 1);
        return false;
    }
    
    size_t bytecodeSize;
    const char* bytecode = lua_tolstring(L, -1, &bytecodeSize);

    if (bytecode == nullptr || bytecodeSize == 0) {
        Logger::log(Logger::LogLevel::ERROR, "Failed to retrieve bytecode for script: " + scriptPath);
        lua_pop(L, 1);
        return false;
    }

    std::string outputFilePath = outputDirectory + "/" + scriptPath + ".luac";

    bool success = writeBytecodeToFile(std::string(bytecode, bytecodeSize), outputFilePath);
    lua_pop(L, 1);
    
    return success;
}

bool LuaDumper::writeBytecodeToFile(const std::string& bytecode, const std::string& outputFilePath) {
    std::ofstream outFile(outputFilePath, std::ios::binary);
    if (!outFile) {
        Logger::log(Logger::LogLevel::ERROR, "Failed to open output file for writing: " + outputFilePath);
        return false;
    }

    outFile.write(bytecode.data(), bytecode.size());
    outFile.close();

    if (outFile.good()) {
        Logger::log(Logger::LogLevel::DUMP, "Bytecode successfully dumped to: " + outputFilePath);
        return true;
    } else {
        Logger::log(Logger::LogLevel::ERROR, "Error occurred while writing bytecode to file: " + outputFilePath);
        return false;
    }
}
