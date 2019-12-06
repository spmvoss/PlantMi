#include "catch.hpp"
#include "Sensors.h"

TEST_CASE("1: Water Level Sensor Test with reversed logic","[water_level]"){
    WaterLevelSensor waterSensorOne;
    waterSensorOne.setPin(10);

    REQUIRE(waterSensorOne.measure() == false);

    SECTION("Setting a pin with low read return value"){
        waterSensorOne.setPin(11);

        REQUIRE(waterSensorOne.measure() == true);
    }
}

TEST_CASE("2: Water Level Sensor Test with regular logic","[water_level]"){
    WaterLevelSensor waterSensorOne(false);
    waterSensorOne.setPin(10);

    REQUIRE(waterSensorOne.measure() == true);

    SECTION("Setting a pin with low read return value"){
        waterSensorOne.setPin(11);

        REQUIRE(waterSensorOne.measure() == false);
    }
}