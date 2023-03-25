#pragma once
#include "Macros.h"
#include <iostream>


class GroundTransport {
public:
    ALLCLASSESTV_API GroundTransport();
    //virtual double DurationRelax(int& counter) = 0;//��� ������ ���������. ������� - ��� �� ����� ����������, ���������� ��������� ���������������, ����� ������ ������� ������ ����� ������
    ALLCLASSESTV_API virtual double DurationRelax(int& counter);
    ALLCLASSESTV_API int getSpeedMove();
    ALLCLASSESTV_API int getTimeMoveToRelax();
protected:
    int _speedMove;
    int _timeMoveToRelax;
};