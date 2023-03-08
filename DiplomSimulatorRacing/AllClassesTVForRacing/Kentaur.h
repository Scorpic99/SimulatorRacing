#pragma once
#include "GroundTransport.h"

class Kentaur : public GroundTransport {
public:
    ALLCLASSESTV_API Kentaur();
    ALLCLASSESTV_API double DurationRelax(int& counter)override;
};
