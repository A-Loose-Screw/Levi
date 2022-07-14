#include "Robot.h"

RobotArm robotarm;

void Robot::robotInit() {
  RBC_PRINT_WARN("Robot Started");


  drivetrain.setLoop(10);
  intake.setLoop(100);

  robotarm.setLoop(1000);

  registerAsyncLoop(&drivetrain);
  registerAsyncLoop(&intake);
  registerLoop(&robotarm);
}

void Robot::robotPeriodic() {
  if (count > 5000000) {
    shutdown();
  }

  if (count == 10000) {
    setEnabled(true);
  }
  // drivetrain.update();
  count++;
}

void Robot::enabledInit() {
  intake.startLoop();
  drivetrain.startLoop();
  robotarm.startLoop();

  // if (count > 10000) {
  //   robotarm.stopLoop();
  // }
}

void Robot::enabledPeriodic() {
  // RBC_PRINT_INFO("Up Time: " + std::to_string(getUpTime()));
}