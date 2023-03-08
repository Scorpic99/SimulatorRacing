#include "Camel.h"


Camel::Camel() {
    _speedMove = 10;
    _timeMoveToRelax = 30;
}
double Camel::DurationRelax(int& counter) {
    counter++;
    if (counter == 1) {
        return 5;
    }
    else {
        return 8;
    }
}