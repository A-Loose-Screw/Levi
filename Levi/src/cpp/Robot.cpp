
#include "Robot.h"
#include "Drivetrain.h"

Drivetrain drivetrain;

unsigned int count = 0;

void Robot::robotInit() {
  // setEnabled();

  drivetrain.setLoop(100);
  registerLoop(&drivetrain);

  setEnabled();
}

void Robot::robotPeriodic() {
  if (count > 100) {
    shutdown();
  }

  // RBC_PRINT_TRACE("Main Freq: " + std::to_string(1.0/getDt()));

  count++;
}

void Robot::enabledInit() {
  drivetrain.startLoop();
}

void Robot::enabledPeriodic() {
  // RBC_PRINT_INFO("Enabled");
}
