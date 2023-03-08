#pragma once
#include "GroundTransport.h"

class Camel : public GroundTransport {
public:
    ALLCLASSESTV_API Camel();
    ALLCLASSESTV_API double DurationRelax(int& counter)override;
};