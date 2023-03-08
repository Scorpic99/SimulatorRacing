#pragma once
#include "AirTransport.h"


class Broom : public AirTransport {
public:
    ALLCLASSESTV_API Broom();
    ALLCLASSESTV_API int CoefficientSortsDistance(int distance)override;
};