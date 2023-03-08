#pragma once
#ifdef ALLCLASSESTV_EXPORTS
#define ALLCLASSESTV_API __declspec(dllexport)
#else
#define ALLCLASSESTV_API __declspec(dllimport)
#endif
#include <iostream>

class AirTransport {
public:
    ALLCLASSESTV_API AirTransport();
    ALLCLASSESTV_API virtual int CoefficientSortsDistance(int distance);
    ALLCLASSESTV_API int getSpeedMove();
protected:
    int _speedMove;
};