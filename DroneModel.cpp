// ======================= DroneModel.cpp =======================
#include "DroneModel.h"

void DroneModel::addObserver(Observer* o) {
    observers.push_back(o);
}

void DroneModel::notify() {
    for (auto* o : observers) 
        {
            //o->update();
            auto* obj = dynamic_cast<QObject*>(o);
            if (obj) {
                QMetaObject::invokeMethod(obj, "update", Qt::QueuedConnection);
            }
        }
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
