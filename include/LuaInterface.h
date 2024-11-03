#ifndef LUAINTERFACE_H
#define LUAINTERFACE_H

#include <string>
#include "Logger.h"
#include "LuaDumper.h"

class LuaInterface {
public:
    LuaInterface();
    ~LuaInterface();

    void loadScript(const std::string& script);
    void dumpScript(const std::string& script);

private:
    lua_State* L;
    LuaDumper dumper;
};

#endif
