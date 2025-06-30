// ======================= test/test_model.cpp =======================
#include <gtest/gtest.h>
#include "DroneModel.h"

class DummyObserver : public Observer {
public:
    bool updated = false;
    void update() override { updated = true; }
};

TEST(DroneModelTest, ObserverGetsNotified) {
    DroneModel model;
    DummyObserver observer;
    model.addObserver(&observer);

    DroneTelemetry data;
    data.latitude = 10.5;
    model.updateTelemetry(data);

    EXPECT_TRUE(observer.updated);
}

TEST(DroneModelTest, StoresTelemetry) {
    DroneModel model;
    DroneTelemetry input;
    input.latitude = 42.0;
    model.updateTelemetry(input);

    DroneTelemetry output = model.getTelemetry();
    EXPECT_DOUBLE_EQ(output.latitude, 42.0);
}