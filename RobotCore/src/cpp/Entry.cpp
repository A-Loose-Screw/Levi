#include "Logging/Print.h"
#include "RobotBase.h"

extern RBC::RobotBase *RBC::createRobot();

int main(int argc, char** argv) {
  /**
   * @brief Main Logger
   * 
   */
  RBC::Log::init("[Robot Pre-Startup]");

  /**
   * @brief Create Robot Class (supports only 1) & setup client logger
   * 
   */
  auto robot = RBC::createRobot();

  RBC_CORE_PRINT_INFO("Robot Program: " + robot->getName());
  RBC::Log::setClientName("[Runtime - " + robot->getName() + "]");

  /**
   * @brief Super Loop
   * 
   */
  int returner = robot->run();

  RBC::Log::setClientName("[Killtime - " + robot->getName() + "]");

  /**
   * @brief App cleanup
   * 
   */
  delete robot;
  return returner;
}
