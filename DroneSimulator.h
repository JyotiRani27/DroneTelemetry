// ======================= DroneSimulator.h =======================
#pragma once
#include <thread>
#include <atomic>
#include "DroneModel.h"
#include "MovementStrategy.h"

class DroneSimulator {
public:
    DroneSimulator(DroneModel* model, MovementStrategy* strategy);
    void start();
    void stop();
    void toggleFailureMode();

private:
    void run();
    DroneModel* model;
    MovementStrategy* strategy;
    std::thread worker;
    std::atomic<bool> running;
    std::atomic<bool> failure;
};