// ======================= MovementStrategy.h =======================
#pragma once
#include "DroneTelemetry.h"

class MovementStrategy {
public:
    virtual void update(DroneTelemetry& data) = 0;
    virtual ~MovementStrategy() = default;
};

class HoverStrategy : public MovementStrategy {
public:
    void update(DroneTelemetry& data) override {
        data.heading += 0.5;
    }
};

class RandomWalkStrategy : public MovementStrategy {
public:
    void update(DroneTelemetry& data) override {
        data.latitude += ((rand() % 100) - 50) * 0.0001;
        data.longitude += ((rand() % 100) - 50) * 0.0001;
        data.speed = 10 + rand() % 10;
        data.heading += ((rand() % 20) - 10);
    }
};
