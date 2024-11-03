cmake_minimum_required(VERSION 3.10)
project(LuaBytecodeDumper)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(LuaBytecodeDumper src/main.cpp src/Logger.cpp src/LuaDumper.cpp)

enable_testing()
add_subdirectory(tests)
