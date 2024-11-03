# tests/CMakeLists.txt
add_executable(RunTests LoggerTest.cpp LuaDumperTest.cpp ConfigManagerTest.cpp)
target_link_libraries(RunTests Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(RunTests)
