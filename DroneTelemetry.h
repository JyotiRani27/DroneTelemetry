// ======================= DroneTelemetry.h =======================
#pragma once
#include <string>

struct DroneTelemetry {
    std::string id = "DRONE-001";
    double latitude = 0.0, longitude = 0.0, altitude = 100.0;
    double heading = 0.0, speed = 0.0;
    int battery = 100;
    std::string gpsFix = "3D";
};

// ======================= Observer.h =======================
#pragma once
class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};