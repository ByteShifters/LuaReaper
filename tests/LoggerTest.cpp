#include "../include/Logger.h"
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("Logger test") {
    REQUIRE_NOTHROW(Logger::log(Logger::LogLevel::INFO, "Test log message"));
}
