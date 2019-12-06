#include "catch.hpp"
#include "Pump.h"

TEST_CASE("Testing the pump's water level sensor","[pump-watersensor-test]"){
    Pump pump;
    pump.setPin(2);

    REQUIRE_THROWS(pump.waterLevelOk());
    REQUIRE_THROWS(pump.water());
    pump.setCapacity(0.6);
    REQUIRE(pump.water());
    REQUIRE(pump.water(900));

    SECTION("Adding a watersensor that will return true to the pump"){
        pump.addWaterSensor(2, false);
        REQUIRE(pump.waterLevelOk());
        REQUIRE(pump.water());
        REQUIRE(pump.water(900));
    }

    SECTION("Adding a watersensor that will return false to the pump"){
        pump.addWaterSensor(2, true);
        REQUIRE_FALSE(pump.waterLevelOk());
        REQUIRE_FALSE(pump.water());
        REQUIRE_FALSE(pump.water(900));
    }
    
}