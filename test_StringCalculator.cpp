#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/StringCalculator.h"

TEST_CASE("Empty string returns 0") {
    StringCalculator calc;
    REQUIRE(calc.add("") == 0);
}
