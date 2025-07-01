// ======================= MainWindow.h =======================
#pragma once
#include <QMainWindow>
#include "DroneModel.h"
#include "DroneSimulator.h"
#include "Observer.h"

class QLabel;
class QPushButton;

class MainWindow : public QMainWindow, public Observer {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void update() override;

private slots:
    void onToggleFailure();

private:
    DroneModel model;
    DroneSimulator* simulator;
    QLabel *lblID, *lblLat, *lblLon, *lblAlt, *lblHeading, *lblSpeed, *lblBattery, *lblGPS;
    QPushButton *btnFailure;
};
