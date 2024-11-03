#include "LuaInterface.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        Logger::log(Logger::LogLevel::ERROR, "Usage: LuaBytecodeDumper <script.lua>");
        return 1;
    }

    LuaInterface luaInterface;

    for (int i = 1; i < argc; ++i) {
        std::string script = argv[i];
        luaInterface.loadScript(script);
        luaInterface.dumpScript(script);
    }

    return 0;
}
