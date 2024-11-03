
#ifndef LUADUMPER_H
#define LUADUMPER_H

#include <string>
#include <lua.hpp>
#include "Logger.h"

class LuaDumper {
public:
    LuaDumper(lua_State* luaState, const std::string& outputDirectory);

    bool dump(const std::string& scriptPath);

private:
    lua_State* L;
    std::string outputDirectory;

    bool writeBytecodeToFile(const std::string& bytecode, const std::string& outputFilePath);
};

#endif // LUADUMPER_H
