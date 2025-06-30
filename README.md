// ======================= README.md =======================
# Real-Time Drone Telemetry Simulator (Single Drone Version)

## Overview
This is a Qt Widgets desktop application simulating real-time telemetry from a single drone. The data updates every 500ms and supports failure simulation.

## Features
- Telemetry Display (ID, Lat, Lon, Alt, Speed, Heading, Battery, GPS Fix)
- Multithreaded Simulation
- Failure Mode Simulation

## Design Patterns Used
- **Observer**: `DroneModel` notifies UI (`MainWindow`)
- **Factory**: `SimulatorFactory` creates `DroneSimulator`
- **Strategy**: `RandomWalkStrategy`, `HoverStrategy`
- **Singleton**: `Logger`

## Build Instructions
```bash
mkdir build && cd build
cmake ..
make
./DroneTelemetrySimulator
```

## Tests
Basic unit tests for strategy behavior and telemetry updates can be added in `tests/` directory using GoogleTest or simple assertions.

---
