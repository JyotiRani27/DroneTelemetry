// ======================= SimulatorFactory.h =======================
#pragma once
#include "DroneSimulator.h"
#include "MovementStrategy.h"

class SimulatorFactory {
public:
    static DroneSimulator* createSimulator(DroneModel* model) {
        return new DroneSimulator(model, new RandomWalkStrategy());
    }
};
