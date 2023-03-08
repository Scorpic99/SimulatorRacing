#pragma once
#include "GroundTransport.h"

class BootAllvechicle : public GroundTransport {
public:
    ALLCLASSESTV_API BootAllvechicle();
    ALLCLASSESTV_API double DurationRelax(int& counter)override;
};
