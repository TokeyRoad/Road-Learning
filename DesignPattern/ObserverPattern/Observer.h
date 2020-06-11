#pragma once
#include "../Common/head.h"
#include "SubjectObserver.h"

class IObserver {
public:
	virtual void update(float price) = 0;
};