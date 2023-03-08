#pragma once
#ifdef ALLCLASSESTV_EXPORTS
#define ALLCLASSESTV_API __declspec(dllexport)
#else
#define ALLCLASSESTV_API __declspec(dllimport)
#endif
#include <iostream>


class GroundTransport {
public:
    ALLCLASSESTV_API GroundTransport();
    //virtual double DurationRelax(int& counter) = 0;//это чистая виртуальн. функция - она не имеет реализации, компелятор проверяет переопределение, также нельзя создать объект этого класса
    ALLCLASSESTV_API virtual double DurationRelax(int& counter);
    ALLCLASSESTV_API int getSpeedMove();
    ALLCLASSESTV_API int getTimeMoveToRelax();
protected:
    int _speedMove;
    int _timeMoveToRelax;
};