// ======================= README.md =======================
# Real-Time Drone Telemetry Simulator (Single Drone Version)

## Overview
This is a Qt Widgets desktop application simulating real-time telemetry from a single drone. The data updates every 500ms and supports failure simulation.

src/
├── main.cpp
├── MainWindow.h/cpp        # GUI code
├── DroneModel.h/cpp        # Holds current telemetry state
├── DroneSimulator.h/cpp    # Simulates telemetry in a thread
├── MovementStrategy.h/cpp  # Strategy Pattern: RandomWalk, Hover
├── SimulatorFactory.h/cpp  # Factory Pattern
├── Logger.h/cpp            # Singleton Pattern
├── tests/
│   ├── test_simulator.cpp  # Test logic for simulator
│   └── test_strategy.cpp   # Test movement behavior
    └── test_model.cpp      # Verifies that when telemetry is updated, DroneModel notifies its registered observers and Confirms that DroneModel actually stores the telemetry correctly.
CMakeLists.txt
README.md

**Function call flowchart ->**
main() 
 └── QApplication app
 └── MainWindow window
     ├── setup UI and labels
     ├── model.addObserver(this)         <-- Observer Pattern
     ├── simulator = SimulatorFactory::createSimulator(&model)
     │     └── new DroneSimulator(model, new RandomWalkStrategy)
     ├── simulator->start()              <-- Starts background thread
     │     └── DroneSimulator::run()
     │           ├── while running:
     │           │     ├── strategy->update(data)  <-- Strategy Pattern
     │           │     ├── model->updateTelemetry(data)
     │           │     │     ├── updates internal state
     │           │     │     └── notify()          <-- Observer notified
     │           │     │           └── MainWindow::update()
     │           │     │               └── UI labels updated
     ├── User clicks toggle failure
     │     └── MainWindow::onToggleFailure()
     │           └── simulator->toggleFailureMode()


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
Basic unit tests for strategy behavior and telemetry updates are added in `tests/` directory using GoogleTest.

---
