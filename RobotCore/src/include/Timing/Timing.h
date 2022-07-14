#ifndef RBC_TIMING_H
#define RBC_TIMING_H

#include <chrono>

namespace RBC {
  namespace Timing {
    class RBCTimer {
     public:
      static double getTimestamp_micro();
      static double getTimestamp_ms();
      static double getTimestamp_s();

      typedef std::chrono::_V2::high_resolution_clock::time_point time_stamp;
      inline static time_stamp getSystemTimestamp() { return std::chrono::high_resolution_clock::now(); };


     private:
      inline static auto start = std::chrono::high_resolution_clock::now();
      inline static auto stop = std::chrono::high_resolution_clock::now();
    };
  }
}

#endif