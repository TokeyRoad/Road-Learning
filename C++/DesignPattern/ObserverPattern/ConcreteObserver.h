#pragma once
#include "Observer.h"

class ConcreteObserver :public IObserver {
public:
	ConcreteObserver(string Name) { m_strName = Name; }
	void update(float f) {
		cout << m_strName << " Update price " << f << endl;
	}
private:
	string m_strName;
};