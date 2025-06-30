// ======================= DroneModel.cpp =======================
#include "DroneModel.h"

void DroneModel::addObserver(Observer* o) {
    observers.push_back(o);
}

void DroneModel::notify() {
    for (auto* o : observers) o->update();
}

void DroneModel::updateTelemetry(const DroneTelemetry& data) {
    std::lock_guard<std::mutex> lock(mu);
    telemetry = data;
    notify();
}

DroneTelemetry DroneModel::getTelemetry() const {
    std::lock_guard<std::mutex> lock(mu);
    return telemetry;
}