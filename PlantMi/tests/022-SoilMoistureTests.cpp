#include "catch.hpp"
#include "Sensors.h"

TEST_CASE("1: Soil Moisture content tests","[soil_moisture]"){
    SoilMoistureSensor soilSensor(12);
    soilSensor.setPin(14);
    soilSensor.configure(1330, 2800);

    // Lower than min, should return 0
    REQUIRE(soilSensor.measure() == 0);

    SECTION("Value in range"){
        soilSensor.setPin(18);
        REQUIRE(soilSensor.measure() == 45);
    }

    SECTION("Value higher than range"){
        soilSensor.setPin(19);
        REQUIRE(soilSensor.measure() == 100);
    }
}