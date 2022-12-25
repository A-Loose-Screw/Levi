#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "RobotCore.h"
#include "Subsystems/Subsystem.h"

class Drivetrain : public RBC::Subsystems::Subsystem {
 public:
  Drivetrain() : RBC::Subsystems::Subsystem("<Drivetrain>") {}

  void onLoopUpdate(double dt) override {
    RBC_PRINT_TRACE("Drivetrain Freq: " + std::to_string(1.0/dt));
  }

  void onLoopStart() override {
    RBC_PRINT_INFO("Started Drivetrain");
  }

  void onLoopStop() override {
    RBC_PRINT_WARN("Stopped Drivetrain");
  }
};

#endif