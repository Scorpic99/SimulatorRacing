#include "CarpetAirplane.h"


CarpetAirplane::CarpetAirplane() {
	_speedMove = 10;
}
int CarpetAirplane::CoefficientSortsDistance(int distance) {
	if (distance < 1000) {
		return 0;//без сокращения
	}
	else if (distance < 5000) {
		return 3;//%
	}
	else if (distance < 10000) {
		return 10;
	}
	else {
		return 5;
	}
}
