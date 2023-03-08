#pragma once
#include "GroundTransport.h"

class CamelSpidrun : public GroundTransport {
public:
    ALLCLASSESTV_API CamelSpidrun();
    ALLCLASSESTV_API double DurationRelax(int& counter)override;
};