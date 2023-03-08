#include "CamelSpidrun.h"


CamelSpidrun::CamelSpidrun() {
	_speedMove = 40;
	_timeMoveToRelax = 10;
}
double CamelSpidrun::DurationRelax(int& counter) {
	counter++;
	if (counter == 1) {
		return 5;
	}
	else if (counter == 2) {
		return 6.5;
	}
	else {
		return 8;
	}
}
