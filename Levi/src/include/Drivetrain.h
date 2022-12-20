#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "RobotCore.h"
#include "Subsystems/Subsystem.h"

class Drivetrain : public RBC::Subsystems::Subsystem {
 public:
  Drivetrain() : RBC::Subsystems::Subsystem("<Drivetrain>") {}

  void onUpdate(double dt) override {
    RBC_PRINT_TRACE("Drivetrain Freq: " + std::to_string(1.0/dt));
  }

  void onStart() override {
    RBC_PRINT_INFO("Started Drivetrain");
  }

  void onStop() override {
    RBC_PRINT_WARN("Stopped Drivetrain");
  }
};

class Intake : public RBC::Subsystems::Subsystem {
 public:
  Intake() : RBC::Subsystems::Subsystem("<Intake>") {}

  void onUpdate(double dt) override {
    RBC_PRINT_TRACE("Intake Freq: " + std::to_string(1.0/dt));
  }
};

#endif