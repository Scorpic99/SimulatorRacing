#include "GroundTransport.h"
    
GroundTransport::GroundTransport() {
    _speedMove = 0;
    _timeMoveToRelax = 0;
}
//virtual double DurationRelax(int& counter) = 0;//это чистая виртуальн. функция - она не имеет реализации, компелятор проверяет переопределение, также нельзя создать объект этого класса
double GroundTransport::DurationRelax(int& counter) {
    return 0;
}
int GroundTransport::getSpeedMove() {
    return _speedMove;
}
int GroundTransport::getTimeMoveToRelax() {
    return _timeMoveToRelax;
}
