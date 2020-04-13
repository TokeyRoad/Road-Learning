#pragma once
#include "../Common/head.h"

class Car {
public:
	Car(){}
	virtual ~Car(){}
	virtual Car* clone() = 0;
	virtual void run() = 0;
};
