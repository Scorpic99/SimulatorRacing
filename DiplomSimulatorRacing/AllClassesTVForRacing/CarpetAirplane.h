#pragma once
#include "AirTransport.h"

class CarpetAirplane : public AirTransport {
public:
    ALLCLASSESTV_API CarpetAirplane();
    ALLCLASSESTV_API int CoefficientSortsDistance(int distance)override;
};