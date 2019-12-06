cmake_minimum_required(VERSION 3.0.0)
project(plantmi VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories(PlantMi/include PlantMi/include/tests)

file(GLOB SOURCES "PlantMi/src/*.cpp")
add_executable(plantmi ${SOURCES} PlantMi/main.cpp)


file(GLOB TEST_SOURCES "PlantMi/tests/*.cpp")
add_executable(runTests ${TEST_SOURCES})
add_test(runTests runTests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
