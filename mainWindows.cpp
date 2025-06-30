// ======================= MainWindow.cpp =======================
#include "MainWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "SimulatorFactory.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);

    lblID = new QLabel("ID:"); layout->addWidget(lblID);
    lblLat = new QLabel("Lat:"); layout->addWidget(lblLat);
    lblLon = new QLabel("Lon:"); layout->addWidget(lblLon);
    lblAlt = new QLabel("Alt:"); layout->addWidget(lblAlt);
    lblHeading = new QLabel("Heading:"); layout->addWidget(lblHeading);
    lblSpeed = new QLabel("Speed:"); layout->addWidget(lblSpeed);
    lblBattery = new QLabel("Battery:"); layout->addWidget(lblBattery);
    lblGPS = new QLabel("GPS:"); layout->addWidget(lblGPS);

    btnFailure = new QPushButton("Toggle Failure Mode");
    layout->addWidget(btnFailure);
    connect(btnFailure, &QPushButton::clicked, this, &MainWindow::onToggleFailure);

    model.addObserver(this);
    simulator = SimulatorFactory::createSimulator(&model);
    simulator->start();

    setCentralWidget(central);
}

MainWindow::~MainWindow() {
    simulator->stop();
    delete simulator;
}

void MainWindow::update() {
    const auto &data = model.getTelemetry();
    lblID->setText("ID: " + QString::fromStdString(data.id));
    lblLat->setText("Lat: " + QString::number(data.latitude));
    lblLon->setText("Lon: " + QString::number(data.longitude));
    lblAlt->setText("Alt: " + QString::number(data.altitude));
    lblHeading->setText("Heading: " + QString::number(data.heading));
    lblSpeed->setText("Speed: " + QString::number(data.speed));
    lblBattery->setText("Battery: " + QString::number(data.battery));
    lblGPS->setText("GPS: " + QString::fromStdString(data.gpsFix));
}

void MainWindow::onToggleFailure() {
    simulator->toggleFailureMode();
}
