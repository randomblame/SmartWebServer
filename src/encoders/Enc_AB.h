// ----------------------------------------------------------------------------------------------------------------
// Read Quadrature A/B type encoders

#include <Arduino.h>
#include "../../Constants.h"
#include "../../Config.h"
#include "../../ConfigX.h"
#include "../pinmaps/Models.h"

// this is for Quadrature A/B type encoders (library based)
#if AXIS1_ENC_RATE_CONTROL != ON && (AXIS1_ENC == AB || AXIS2_ENC == AB)
  #include <Encoder.h> // from https://github.com/hjd1964/Encoder 
  #if AXIS1_ENC == AB
    extern Encoder axis1Pos;
  #endif
  #if AXIS2_ENC == AB
    extern Encoder axis2Pos;
  #endif
#endif

#if AXIS1_ENC_RATE_CONTROL == ON && (AXIS1_ENC == AB || AXIS2_ENC == AB)

  class ABEncoder {
    public:
      ABEncoder(int16_t aPin, int16_t bPin, int16_t axis);
      int32_t read();
      void write(int32_t v);

    private:
      int16_t _axis;
  };

  #if AXIS1_ENC == AB
    extern ABEncoder axis1Pos;
  #endif

  #if AXIS2_ENC == AB
    extern ABEncoder axis2Pos;
  #endif

#endif
