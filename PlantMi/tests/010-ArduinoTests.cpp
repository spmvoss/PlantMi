#include "catch.hpp"
#include "Arduino.h"

TEST_CASE("1: analogRead return value", "[analogRead()]"){
    REQUIRE(analogRead(10) == 100);
    REQUIRE(analogRead(11) == 300);
    REQUIRE(analogRead(12) == 600);
    REQUIRE(analogRead(13) == 900);
    REQUIRE(analogRead(14) == 1010);
    REQUIRE(analogRead(15) == 10);
    REQUIRE(analogRead(1) == 10);
}