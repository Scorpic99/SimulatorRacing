#pragma once
#include "AirTransport.h"

class Eagle : public AirTransport {
public:
    ALLCLASSESTV_API Eagle();
    ALLCLASSESTV_API int CoefficientSortsDistance(int distance)override;
};
