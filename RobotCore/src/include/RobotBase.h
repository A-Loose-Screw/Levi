#ifndef RBC_ROBOT_BASE_H
#define RBC_ROBOT_BASE_H

#include "Timing/Timing.h"
#include "Subsystems/SubsystemController.h"

#include <string>

namespace RBC {
  class RobotBase : public Subsystems::SubsystemController {
   public:
    RobotBase(const std::string &name = "RBC-Program");
    virtual ~RobotBase();
    
    /**
     * @brief Super loop (USER SHOULD NOT CALL THIS, called in Entry.h)
     * 
     * @return int 
     */
    int run();

    /**
     * @brief Get the singleton of the class
     * 
     */
    static RobotBase &get() {
      return *_instance;
    }

    /**
     * @brief Runs when robot is first initialised/booted
     * 
     */
    virtual void robotInit() {};

    /**
     * @brief Runs periodically after robot init (loop)
     * 
     */
    virtual void robotPeriodic() {};

    /**
     * @brief Runs once, when robot is set to enabled
     * 
     */
    virtual void enabledInit() {};

    /**
     * @brief Runs periodically after enable init has been called, (loop)
     * Runs after robotPeriodic in loop order
     * 
     */
    virtual void enabledPeriodic() {};

    /**
     * @brief Set the robot to being enabled
     * This is a dangerous method as it unlocks all internal functions which rely on the robot being enabled to function
     */
    void setEnabled(bool enable = true);

    /**
     * @brief returns if the robot is enabled
     * 
     * @return true 
     * @return false 
     */
    bool isEnabled() {
      return _enabled;
    }

    /**
     * @brief Get the Up Time of robot in seconds
     * 
     * @return double 
     */
    double getUpTime() {
      return RBC::Timing::RBCTimer::getTimestamp_s();
    }

    /**
     * @brief Get the Delta time (time since last curr time was updated)
     * 
     * @return double in seconds.0f
     */
    double getDt() {
      return _dt;
    }

    /**
     * @brief Get RobotBase class
     * @return string
     */
    std::string getName() {
      return _name;
    }

    /**
     * @brief Shutdown the robot safely
     * 
     */
    void shutdown();

   private:
    static RobotBase *_instance;
    bool _running = false;
    bool _enabled = false;

    // Timing
    double _dt = 0;

    std::string _name;
  };


  RobotBase *createRobot();
}

#define RBC_ROBOT_MAIN(ROBOT) RBC::RobotBase *RBC::createRobot() { return new ROBOT(); }

#endif