#ifndef Intake_H
#define Intake_H

#include "RobotCore.h"
#include "Subsystems/Subsystem.h"

class Intake : public RBC::Subsystems::Subsystem {
 public:
  Intake() : RBC::Subsystems::Subsystem("<Intake>") {}

  void onUpdate(double dt) override {
    RBC_PRINT_TRACE("Intake Freq: " + std::to_string(1.0/dt));
  }
};

#endif