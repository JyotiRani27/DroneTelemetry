// ======================= DroneSimulator.cpp =======================
#include "DroneSimulator.h"
#include <chrono>
#include <thread>
#include "Logger.h"

DroneSimulator::DroneSimulator(DroneModel* model, MovementStrategy* strategy)
    : model(model), strategy(strategy), running(false), failure(false) {}

void DroneSimulator::start() {
    running = true;
    worker = std::thread(&DroneSimulator::run, this);
}

void DroneSimulator::stop() {
    running = false;
    if (worker.joinable()) worker.join();
}

void DroneSimulator::toggleFailureMode() {
    failure = !failure;
    Logger::getInstance().log("Failure mode toggled.");
}

void DroneSimulator::run() {
    DroneTelemetry data = model->getTelemetry();
    while (running) {
        if (failure) {
            data.gpsFix = "No Fix";
            data.battery -= 5;
            if (data.battery < 0) data.battery = 0;
        } else {
            data.gpsFix = "3D";
            data.battery -= 1;
            if (data.battery < 0) data.battery = 0;
            strategy->update(data);
        }
        model->updateTelemetry(data);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}