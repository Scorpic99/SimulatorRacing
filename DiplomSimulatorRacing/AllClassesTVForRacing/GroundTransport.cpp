#include "GroundTransport.h"
    
GroundTransport::GroundTransport() {
    _speedMove = 0;
    _timeMoveToRelax = 0;
}
//virtual double DurationRelax(int& counter) = 0;//��� ������ ���������. ������� - ��� �� ����� ����������, ���������� ��������� ���������������, ����� ������ ������� ������ ����� ������
double GroundTransport::DurationRelax(int& counter) {
    return 0;
}
int GroundTransport::getSpeedMove() {
    return _speedMove;
}
int GroundTransport::getTimeMoveToRelax() {
    return _timeMoveToRelax;
}
