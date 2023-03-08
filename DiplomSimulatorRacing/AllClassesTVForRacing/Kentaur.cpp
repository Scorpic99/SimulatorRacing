#include "Kentaur.h"


Kentaur::Kentaur() {
	_speedMove = 15;
	_timeMoveToRelax = 8;
}
double Kentaur::DurationRelax(int& counter) {
	counter++;
	return 2;
}