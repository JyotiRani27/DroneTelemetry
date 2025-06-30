// ======================= test/test_strategy.cpp =======================
#include <gtest/gtest.h>
#include "MovementStrategy.h"

TEST(RandomWalkStrategyTest, ChangesPosition) {
    DroneTelemetry data{};
    double originalLat = data.latitude;
    double originalLon = data.longitude;

    RandomWalkStrategy strategy;
    strategy.update(data);

    EXPECT_NE(data.latitude, originalLat);
    EXPECT_NE(data.longitude, originalLon);
}

TEST(HoverStrategyTest, MinimalChange) {
    DroneTelemetry data{};
    double originalHeading = data.heading;

    HoverStrategy strategy;
    strategy.update(data);

    EXPECT_NEAR(data.heading, originalHeading + 0.5, 0.1);
}
