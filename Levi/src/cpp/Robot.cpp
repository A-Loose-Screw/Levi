
#include "Robot.h"
#include "Drivetrain.h"

Drivetrain drivetrain;
Intake intake;

unsigned int count = 0;

void Robot::robotInit() {
  // setEnabled();

  drivetrain.setLoop(100);
  intake.setLoop(200);

  registerLoop(&drivetrain);
  registerLoop(&intake);

  setEnabled();
}

void Robot::robotPeriodic() {
  if (count > 100) {
    shutdown();
  }

  // std::cout << "Freq: " << std::to_string(1.0/getDt()) << std::endl;
  // RBC_PRINT_TRACE("Main Freq: " + std::to_string(1.0/getDt()));

  count++;
}

void Robot::enabledInit() {
  drivetrain.startLoop();
  intake.startLoop();
}

void Robot::enabledPeriodic() {
  // RBC_PRINT_INFO("Enabled");
}
