#pragma once
#include "../Common/head.h"

class ITelco {
public:
	virtual ~ITelco(){}
	virtual void Recharge(int money) = 0;
};