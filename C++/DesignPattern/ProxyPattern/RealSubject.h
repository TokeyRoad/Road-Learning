#pragma once
#include "Subject.h"

class CMCC :public ITelco {
public:
	void Recharge(int money) {
		cout << "CMCC Recharge " << money << endl;
	}
};

class CUCC :public ITelco {
public:
	void Recharge(int money) {
		cout << "CUCC Recharge " << money << endl;
	}
};

class CNET :public ITelco {
public:
	void Recharge(int money) {
		cout << "CNET Recharge " << money << endl;
	}
};