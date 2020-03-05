#include "catch.hpp"
#include "Sensors.h"

TEST_CASE("Thermistor 10bit unit tests","[thermistor_10bit]"){
    Thermistor thermistor(10);

    thermistor.setPin(10);

    thermistor.configure(298.0, 3950.0, 10000.0);

    // Set an approximate target with +/- 0.1
    Approx target = Approx(-17.9).margin(0.1);

    REQUIRE(thermistor.measure() == target);

    SECTION("Larger return value"){
        thermistor.setPin(13);

        REQUIRE(thermistor.measure() == Approx(77.5).margin(0.1));
    }
}