// ======================= test/test_simulator.cpp =======================
#include <gtest/gtest.h>
#include "DroneSimulator.h"
#include "DroneModel.h"
#include "MovementStrategy.h"

class TestStrategy : public MovementStrategy {
public:
    void update(DroneTelemetry& data) override {
        data.latitude += 1.0;
    }
};

TEST(DroneSimulatorTest, FailureModeDropsBattery) {
    DroneModel model;
    TestStrategy strategy;
    DroneSimulator sim(&model, &strategy);

    sim.toggleFailureMode();
    std::thread t([&]() {
        sim.start();
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        sim.stop();
    });
    t.join();

    DroneTelemetry data = model.getTelemetry();
    EXPECT_LT(data.battery, 100);
    EXPECT_EQ(data.gpsFix, "No Fix");
}
