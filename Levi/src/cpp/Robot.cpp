
#include "Robot.h"

void Robot::robotInit() {
  setEnabled();
}

void Robot::robotPeriodic() {
  // shutdown();
}

void Robot::enabledInit() {

}

void Robot::enabledPeriodic() {
  RBC_PRINT_INFO("Enabled");
  shutdown();
}
