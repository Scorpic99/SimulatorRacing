#pragma once
#include "Macros.h"
#include <iostream>

class AirTransport {
public:
    ALLCLASSESTV_API AirTransport();
    ALLCLASSESTV_API virtual int CoefficientSortsDistance(int distance);
    ALLCLASSESTV_API int getSpeedMove();
protected:
    int _speedMove;
};