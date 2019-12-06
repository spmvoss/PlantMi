#include "catch.hpp"
#include "Sensors.h"

TEST_CASE("1: Test LDR output values", "[LDR output]"){
    LightSensor ldr;
    ldr.setPin(13);
    ldr.configure(-1.42, 7.1, 10000.0, 3.3);
    
    REQUIRE(ldr.measure() == 443.97549f);
}