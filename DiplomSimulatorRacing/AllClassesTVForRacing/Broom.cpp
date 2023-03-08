#include "Broom.h"


Broom::Broom() {
	_speedMove = 20;
}
int Broom::CoefficientSortsDistance(int distance){
	if (distance < 50000) {
		double temp = distance / 1000;
		int temp2 = static_cast<int>(temp);
		return temp2;
	}
	else {
		return 50;//не зависимо от расстояния больше 50% не будет
	}
}