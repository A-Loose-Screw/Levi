#ifndef ROBOT_H
#define ROBOT_H

#include "RobotCore.h"
#include <iostream>

class Robot : public RBC::RobotBase {
 public:
  Robot() : RBC::RobotBase("Levi") {}

  void robotInit() override {
    std::cout << "Robot initialised" << std::endl;
  }
  void robotPeriodic() override {
    std::cout << "Robot running..." << std::endl;
    _counter++;
    if (_counter > 20) {
      setEnabled();
    }

    if (_counter > 50) {
      shutdown();
    }
  }

  void enabledInit() override {
    std::cout << "Robot enabled" << std::endl;
  }
  void enabledPeriodic() override {
    std::cout << "Robot enabled periodic" << std::endl;
  }

 private:
  int _counter = 0;
};

#endif