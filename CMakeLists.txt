# ======================= CMakeLists.txt =======================
cmake_minimum_required(VERSION 3.16)
project(DroneTelemetrySimulator)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6Widgets REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp
    mainWindows.cpp
    DroneModel.cpp
    DroneSimulator.cpp
    Logger.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} Qt6::Widgets)


# GoogleTest
enable_testing()
add_subdirectory(googletest)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(unit_tests
    test/test_strategy.cpp
    test/test_model.cpp
    test/test_simulator.cpp
)

target_link_libraries(unit_tests PRIVATE Qt6::Widgets ${GTEST_LIBRARIES} pthread)
add_test(NAME AllTests COMMAND unit_tests)
