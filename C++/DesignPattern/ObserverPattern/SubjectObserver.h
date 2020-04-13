#pragma once
#include "../Common/head.h"

class IObserver;

class ISubject {
public:
	virtual void Register(IObserver*) = 0;
	virtual void Destory(IObserver*) = 0;
	virtual void Notify(IObserver * p = NULL) = 0;
};