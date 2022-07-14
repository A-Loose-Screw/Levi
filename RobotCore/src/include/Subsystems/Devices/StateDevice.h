#ifndef RBC_STATE_DEVICE_H
#define RBC_STATE_DEVICE_H

#include <string>

namespace RBC {

  namespace Subsystems {
    namespace Devices {

      class StateDeviceBase {
       public:
        StateDeviceBase(std::string name = "<no name>") {}

        virtual void update(double dt) = 0;
        virtual std::string getStateString() = 0;

        std::string getName() { return _name; }
       private:
        std::string _name;
      };

      
    } // Devices
  } // Subsystems
}

#endif