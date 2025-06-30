// ======================= DroneModel.h =======================
#pragma once
#include <vector>
#include <mutex>
#include "Observer.h"
#include "DroneTelemetry.h"

class DroneModel {
public:
    void addObserver(Observer* o);
    void notify();
    void updateTelemetry(const DroneTelemetry& data);
    DroneTelemetry getTelemetry() const;

private:
    std::vector<Observer*> observers;
    DroneTelemetry telemetry;
    mutable std::mutex mu;
};