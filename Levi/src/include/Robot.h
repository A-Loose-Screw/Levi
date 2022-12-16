#ifndef ROBOT_H
#define ROBOT_H

#include "RobotCore.h"

class Robot : public RBC::RobotBase {
 public:
  Robot(int argc, char** argv) : RBC::RobotBase("Levi", argc, argv) {}
  ~Robot() {
    RBC_PRINT_WARN("Levi deconstructed");
  }

  void robotInit() override;
  void robotPeriodic() override;

  void enabledInit() override;
  void enabledPeriodic() override;
 private:

};

#endif