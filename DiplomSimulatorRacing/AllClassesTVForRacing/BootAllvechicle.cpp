#include "BootAllvechicle.h"


BootAllvechicle::BootAllvechicle() {
	_speedMove = 6;
	_timeMoveToRelax = 60;
}
double BootAllvechicle::DurationRelax(int& counter) {
	counter++;
	if (counter == 1) {
		return 10;
	}
	else {
		return 5;
	}
}
