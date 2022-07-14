#include "RobotCore.h"

#include "Drivetrain.h"
#include "Intake.h"

class Robot : public RBC::RobotBase {
 public:
  int count;
  Robot() : RBC::RobotBase("Levi") {}

  void robotInit() override;
  void robotPeriodic() override;

  void enabledInit() override;
  void enabledPeriodic() override;
 private:
  Drivetrain drivetrain;
  Intake intake;
};