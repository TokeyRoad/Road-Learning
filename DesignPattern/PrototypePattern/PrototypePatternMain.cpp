#include "ConcretePrototype.h"

int main() {
	Car * Bwm = new BWM("mine");
	Bwm->run();
	Car * car1 = Bwm->clone();
	Car * car2 = Bwm->clone();
	car1->run();
	car2->run();
	DEL(Bwm);
	DEL(car1);
	DEL(car2);
	system("pause");
	return 0;
}